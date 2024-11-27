#!/bin/bash

# Ensure output directory exists
mkdir -p ./output

# Get the absolute path of the test directory
func_testcase_dir=$(realpath $(dirname "$0")/./tests)

# Function to check the exit status of commands
check_error() {
    if [ $? != 0 ]; then
        echo "$1 failed"
        exit 1
    fi
}

test_single() {
    test_file=$(realpath --relative-base=$func_testcase_dir $func_testcase_dir/$1.tea)
    test_name=${test_file%.tea}

    echo -n $test_name
    echo ": "

    # Run compiler
    ./compiler $func_testcase_dir/$test_name.tea
    check_error "Compiler"

    # Run llvm-link
    llvm-link -opaque-pointers ./tests/$test_name.ll sylib.ll -S -o ./output/$test_name.ll
    check_error "LLVM link"

    # Run LLI with or without input file
    if [ -f $func_testcase_dir/$test_name.in ]; then
        lli -opaque-pointers ./output/$test_name.ll < $func_testcase_dir/$test_name.in > output/$test_name.out
    else
        lli -opaque-pointers ./output/$test_name.ll > ./output/$test_name.out
    fi

    # Output the result of the LLI execution
    echo -e $? >> ./output/$test_name.out

    # Compare the output files
    diff -Bb ./output/$test_name.out $func_testcase_dir/$test_name.out > /dev/null 2>/dev/null
    if [ $? == 0 ]; then
        echo pass
    else
        echo fail
        # Optionally, print the expected and got output for debugging
        # echo "Expect:"
        # cat $func_testcase_dir/$test_name.out
        # echo "Got:"
        # cat ./output/$test_name.out
        exit 1
    fi
}

main() {
    test_single $1
}

main $@
