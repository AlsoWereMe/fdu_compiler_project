; ModuleID = 'llvm-link'
source_filename = "llvm-link"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.timeval = type { i64, i64 }

@TOKEN_NUM = global i32 0
@TOKEN_OTHER = global i32 1
@last_char = global i32 32
@num = global i32 0
@other = global i32 0
@cur_token = global i32 0
@llvm.global_ctors = appending global [1 x { i32, ptr, ptr }] [{ i32, ptr, ptr } { i32 65535, ptr @before_main, ptr null }]
@llvm.global_dtors = appending global [1 x { i32, ptr, ptr }] [{ i32, ptr, ptr } { i32 65535, ptr @after_main, ptr null }]
@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str.1 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@.str.2 = private unnamed_addr constant [4 x i8] c"%d:\00", align 1
@.str.3 = private unnamed_addr constant [4 x i8] c" %d\00", align 1
@.str.4 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@_sysy_us = dso_local global [1024 x i32] zeroinitializer, align 16
@_sysy_s = dso_local global [1024 x i32] zeroinitializer, align 16
@_sysy_m = dso_local global [1024 x i32] zeroinitializer, align 16
@_sysy_h = dso_local global [1024 x i32] zeroinitializer, align 16
@_sysy_idx = dso_local global i32 0, align 4
@stderr = external global ptr, align 8
@.str.5 = private unnamed_addr constant [35 x i8] c"Timer@%04d-%04d: %dH-%dM-%dS-%dus\0A\00", align 1
@_sysy_l1 = dso_local global [1024 x i32] zeroinitializer, align 16
@_sysy_l2 = dso_local global [1024 x i32] zeroinitializer, align 16
@.str.6 = private unnamed_addr constant [25 x i8] c"TOTAL: %dH-%dM-%dS-%dus\0A\00", align 1
@_sysy_start = dso_local global %struct.timeval zeroinitializer, align 8
@_sysy_end = dso_local global %struct.timeval zeroinitializer, align 8

define i32 @next_char() {
next_char:
  %r100 = call i32 @getch()
  store i32 %r100, ptr @last_char, align 4
  %r101 = load i32, ptr @last_char, align 4
  ret i32 %r101
}

define i32 @is_space(i32 %r102) {
is_space:
  %r103 = alloca i32, align 4
  store i32 %r102, ptr %r103, align 4
  %r104 = load i32, ptr %r103, align 4
  %r105 = icmp eq i32 %r104, 32
  br i1 %r105, label %bb1, label %bb3

bb3:                                              ; preds = %is_space
  %r106 = load i32, ptr %r103, align 4
  %r107 = icmp eq i32 %r106, 10
  br i1 %r107, label %bb1, label %bb2

bb1:                                              ; preds = %bb3, %is_space
  ret i32 1

bb67:                                             ; No predecessors!
  br label %bb4

bb2:                                              ; preds = %bb3
  ret i32 0

bb4:                                              ; preds = %bb67
  ret i32 0
}

define i32 @is_num(i32 %r108) {
is_num:
  %r109 = alloca i32, align 4
  store i32 %r108, ptr %r109, align 4
  %r110 = load i32, ptr %r109, align 4
  %r111 = icmp sge i32 %r110, 48
  br i1 %r111, label %bb7, label %bb6

bb7:                                              ; preds = %is_num
  %r112 = load i32, ptr %r109, align 4
  %r113 = icmp sle i32 %r112, 57
  br i1 %r113, label %bb5, label %bb6

bb5:                                              ; preds = %bb7
  ret i32 1

bb68:                                             ; No predecessors!
  br label %bb8

bb6:                                              ; preds = %bb7, %is_num
  ret i32 0

bb8:                                              ; preds = %bb68
  ret i32 0
}

define i32 @next_token() {
next_token:
  br label %bb9

bb9:                                              ; preds = %bb10, %next_token
  %r114 = load i32, ptr @last_char, align 4
  %r115 = call i32 @is_space(i32 %r114)
  %r116 = icmp ne i32 %r115, 0
  br i1 %r116, label %bb10, label %bb11

bb10:                                             ; preds = %bb9
  %r117 = call i32 @next_char()
  br label %bb9

bb11:                                             ; preds = %bb9
  %r118 = load i32, ptr @last_char, align 4
  %r119 = call i32 @is_num(i32 %r118)
  %r120 = icmp ne i32 %r119, 0
  br i1 %r120, label %bb12, label %bb13

bb12:                                             ; preds = %bb11
  %r121 = load i32, ptr @last_char, align 4
  %r122 = sub i32 %r121, 48
  store i32 %r122, ptr @num, align 4
  br label %bb14

bb14:                                             ; preds = %bb15, %bb12
  %r123 = call i32 @next_char()
  %r124 = call i32 @is_num(i32 %r123)
  %r125 = icmp ne i32 %r124, 0
  br i1 %r125, label %bb15, label %bb16

bb15:                                             ; preds = %bb14
  %r126 = load i32, ptr @num, align 4
  %r127 = mul i32 %r126, 10
  %r128 = load i32, ptr @last_char, align 4
  %r129 = add i32 %r127, %r128
  %r130 = sub i32 %r129, 48
  store i32 %r130, ptr @num, align 4
  br label %bb14

bb16:                                             ; preds = %bb14
  %r131 = load i32, ptr @TOKEN_NUM, align 4
  store i32 %r131, ptr @cur_token, align 4
  br label %bb17

bb13:                                             ; preds = %bb11
  %r132 = load i32, ptr @last_char, align 4
  store i32 %r132, ptr @other, align 4
  %r133 = call i32 @next_char()
  %r134 = load i32, ptr @TOKEN_OTHER, align 4
  store i32 %r134, ptr @cur_token, align 4
  br label %bb17

bb17:                                             ; preds = %bb13, %bb16
  %r135 = load i32, ptr @cur_token, align 4
  ret i32 %r135
}

define i32 @panic() {
panic:
  call void @putch(i32 112)
  call void @putch(i32 97)
  call void @putch(i32 110)
  call void @putch(i32 105)
  call void @putch(i32 99)
  call void @putch(i32 33)
  call void @putch(i32 10)
  %r136 = sub i32 0, 1
  ret i32 %r136
}

define i32 @get_op_prec(i32 %r137) {
get_op_prec:
  %r138 = alloca i32, align 4
  store i32 %r137, ptr %r138, align 4
  %r139 = load i32, ptr %r138, align 4
  %r140 = icmp eq i32 %r139, 43
  br i1 %r140, label %bb18, label %bb20

bb20:                                             ; preds = %get_op_prec
  %r141 = load i32, ptr %r138, align 4
  %r142 = icmp eq i32 %r141, 45
  br i1 %r142, label %bb18, label %bb19

bb18:                                             ; preds = %bb20, %get_op_prec
  ret i32 10

bb69:                                             ; No predecessors!
  br label %bb21

bb19:                                             ; preds = %bb20
  br label %bb21

bb21:                                             ; preds = %bb19, %bb69
  %r143 = load i32, ptr %r138, align 4
  %r144 = icmp eq i32 %r143, 42
  br i1 %r144, label %bb22, label %bb24

bb24:                                             ; preds = %bb21
  %r145 = load i32, ptr %r138, align 4
  %r146 = icmp eq i32 %r145, 47
  br i1 %r146, label %bb22, label %bb25

bb25:                                             ; preds = %bb24
  %r147 = load i32, ptr %r138, align 4
  %r148 = icmp eq i32 %r147, 37
  br i1 %r148, label %bb22, label %bb23

bb22:                                             ; preds = %bb25, %bb24, %bb21
  ret i32 20

bb70:                                             ; No predecessors!
  br label %bb26

bb23:                                             ; preds = %bb25
  br label %bb26

bb26:                                             ; preds = %bb23, %bb70
  ret i32 0
}

define void @stack_push(ptr %r149, i32 %r150) {
stack_push:
  %r151 = alloca i32, align 4
  store i32 %r150, ptr %r151, align 4
  %r152 = getelementptr i32, ptr %r149, i32 0
  %r153 = getelementptr i32, ptr %r149, i32 0
  %r154 = load i32, ptr %r153, align 4
  %r155 = add i32 %r154, 1
  store i32 %r155, ptr %r152, align 4
  %r157 = getelementptr i32, ptr %r149, i32 0
  %r158 = load i32, ptr %r157, align 4
  %r156 = alloca i32, align 4
  store i32 %r158, ptr %r156, align 4
  %r159 = load i32, ptr %r156, align 4
  %r160 = getelementptr i32, ptr %r149, i32 %r159
  %r161 = load i32, ptr %r151, align 4
  store i32 %r161, ptr %r160, align 4
  ret void
}

define i32 @stack_pop(ptr %r162) {
stack_pop:
  %r164 = getelementptr i32, ptr %r162, i32 0
  %r165 = load i32, ptr %r164, align 4
  %r163 = alloca i32, align 4
  store i32 %r165, ptr %r163, align 4
  %r167 = load i32, ptr %r163, align 4
  %r168 = getelementptr i32, ptr %r162, i32 %r167
  %r169 = load i32, ptr %r168, align 4
  %r166 = alloca i32, align 4
  store i32 %r169, ptr %r166, align 4
  %r170 = getelementptr i32, ptr %r162, i32 0
  %r171 = getelementptr i32, ptr %r162, i32 0
  %r172 = load i32, ptr %r171, align 4
  %r173 = sub i32 %r172, 1
  store i32 %r173, ptr %r170, align 4
  %r174 = load i32, ptr %r166, align 4
  ret i32 %r174
}

define i32 @stack_peek(ptr %r175) {
stack_peek:
  %r177 = getelementptr i32, ptr %r175, i32 0
  %r178 = load i32, ptr %r177, align 4
  %r176 = alloca i32, align 4
  store i32 %r178, ptr %r176, align 4
  %r179 = load i32, ptr %r176, align 4
  %r180 = getelementptr i32, ptr %r175, i32 %r179
  %r181 = load i32, ptr %r180, align 4
  ret i32 %r181
}

define i32 @stack_size(ptr %r182) {
stack_size:
  %r183 = getelementptr i32, ptr %r182, i32 0
  %r184 = load i32, ptr %r183, align 4
  ret i32 %r184
}

define i32 @mod(i32 %r185, i32 %r187) {
mod:
  %r186 = alloca i32, align 4
  store i32 %r185, ptr %r186, align 4
  %r188 = alloca i32, align 4
  store i32 %r187, ptr %r188, align 4
  %r189 = load i32, ptr %r186, align 4
  %r190 = load i32, ptr %r186, align 4
  %r191 = load i32, ptr %r188, align 4
  %r192 = sdiv i32 %r190, %r191
  %r193 = load i32, ptr %r188, align 4
  %r194 = mul i32 %r192, %r193
  %r195 = sub i32 %r189, %r194
  ret i32 %r195
}

define i32 @eval_op(i32 %r196, i32 %r198, i32 %r200) {
eval_op:
  %r197 = alloca i32, align 4
  store i32 %r196, ptr %r197, align 4
  %r199 = alloca i32, align 4
  store i32 %r198, ptr %r199, align 4
  %r201 = alloca i32, align 4
  store i32 %r200, ptr %r201, align 4
  %r202 = load i32, ptr %r197, align 4
  %r203 = icmp eq i32 %r202, 43
  br i1 %r203, label %bb27, label %bb28

bb27:                                             ; preds = %eval_op
  %r204 = load i32, ptr %r199, align 4
  %r205 = load i32, ptr %r201, align 4
  %r206 = add i32 %r204, %r205
  ret i32 %r206

bb71:                                             ; No predecessors!
  br label %bb29

bb28:                                             ; preds = %eval_op
  br label %bb29

bb29:                                             ; preds = %bb28, %bb71
  %r207 = load i32, ptr %r197, align 4
  %r208 = icmp eq i32 %r207, 45
  br i1 %r208, label %bb30, label %bb31

bb30:                                             ; preds = %bb29
  %r209 = load i32, ptr %r199, align 4
  %r210 = load i32, ptr %r201, align 4
  %r211 = sub i32 %r209, %r210
  ret i32 %r211

bb72:                                             ; No predecessors!
  br label %bb32

bb31:                                             ; preds = %bb29
  br label %bb32

bb32:                                             ; preds = %bb31, %bb72
  %r212 = load i32, ptr %r197, align 4
  %r213 = icmp eq i32 %r212, 42
  br i1 %r213, label %bb33, label %bb34

bb33:                                             ; preds = %bb32
  %r214 = load i32, ptr %r199, align 4
  %r215 = load i32, ptr %r201, align 4
  %r216 = mul i32 %r214, %r215
  ret i32 %r216

bb73:                                             ; No predecessors!
  br label %bb35

bb34:                                             ; preds = %bb32
  br label %bb35

bb35:                                             ; preds = %bb34, %bb73
  %r217 = load i32, ptr %r197, align 4
  %r218 = icmp eq i32 %r217, 47
  br i1 %r218, label %bb36, label %bb37

bb36:                                             ; preds = %bb35
  %r219 = load i32, ptr %r199, align 4
  %r220 = load i32, ptr %r201, align 4
  %r221 = sdiv i32 %r219, %r220
  ret i32 %r221

bb74:                                             ; No predecessors!
  br label %bb38

bb37:                                             ; preds = %bb35
  br label %bb38

bb38:                                             ; preds = %bb37, %bb74
  %r222 = load i32, ptr %r197, align 4
  %r223 = icmp eq i32 %r222, 37
  br i1 %r223, label %bb39, label %bb40

bb39:                                             ; preds = %bb38
  %r224 = load i32, ptr %r199, align 4
  %r225 = load i32, ptr %r201, align 4
  %r226 = call i32 @mod(i32 %r224, i32 %r225)
  ret i32 %r226

bb75:                                             ; No predecessors!
  br label %bb41

bb40:                                             ; preds = %bb38
  br label %bb41

bb41:                                             ; preds = %bb40, %bb75
  ret i32 0
}

define i32 @eval() {
eval:
  %r284 = alloca i32, align 4
  %r282 = alloca i32, align 4
  %r280 = alloca i32, align 4
  %r264 = alloca i32, align 4
  %r262 = alloca i32, align 4
  %r260 = alloca i32, align 4
  %r247 = alloca i32, align 4
  %r227 = alloca [256 x i32], align 4
  %r228 = alloca [256 x i32], align 4
  %r229 = alloca i32, align 4
  store i32 0, ptr %r229, align 4
  br label %bb42

bb42:                                             ; preds = %bb43, %eval
  %r230 = load i32, ptr %r229, align 4
  %r231 = icmp slt i32 %r230, 256
  br i1 %r231, label %bb43, label %bb44

bb43:                                             ; preds = %bb42
  %r232 = load i32, ptr %r229, align 4
  %r233 = getelementptr [256 x i32], ptr %r227, i32 0, i32 %r232
  store i32 0, ptr %r233, align 4
  %r234 = load i32, ptr %r229, align 4
  %r235 = getelementptr [256 x i32], ptr %r228, i32 0, i32 %r234
  store i32 0, ptr %r235, align 4
  %r236 = load i32, ptr %r229, align 4
  %r237 = add i32 %r236, 1
  store i32 %r237, ptr %r229, align 4
  br label %bb42

bb44:                                             ; preds = %bb42
  %r238 = load i32, ptr @cur_token, align 4
  %r239 = load i32, ptr @TOKEN_NUM, align 4
  %r240 = icmp ne i32 %r238, %r239
  br i1 %r240, label %bb45, label %bb46

bb45:                                             ; preds = %bb44
  %r241 = call i32 @panic()
  ret i32 %r241

bb76:                                             ; No predecessors!
  br label %bb47

bb46:                                             ; preds = %bb44
  br label %bb47

bb47:                                             ; preds = %bb46, %bb76
  %r242 = load i32, ptr @num, align 4
  call void @stack_push(ptr %r227, i32 %r242)
  %r243 = call i32 @next_token()
  br label %bb48

bb48:                                             ; preds = %bb60, %bb47
  %r244 = load i32, ptr @cur_token, align 4
  %r245 = load i32, ptr @TOKEN_OTHER, align 4
  %r246 = icmp eq i32 %r244, %r245
  br i1 %r246, label %bb49, label %bb50

bb49:                                             ; preds = %bb48
  %r248 = load i32, ptr @other, align 4
  store i32 %r248, ptr %r247, align 4
  %r249 = load i32, ptr %r247, align 4
  %r250 = call i32 @get_op_prec(i32 %r249)
  %r251 = icmp eq i32 %r250, 0
  br i1 %r251, label %bb51, label %bb52

bb51:                                             ; preds = %bb49
  br label %bb50

bb77:                                             ; No predecessors!
  br label %bb53

bb52:                                             ; preds = %bb49
  br label %bb53

bb53:                                             ; preds = %bb52, %bb77
  %r252 = call i32 @next_token()
  br label %bb54

bb54:                                             ; preds = %bb55, %bb53
  %r253 = call i32 @stack_size(ptr %r228)
  %r254 = icmp ne i32 %r253, 0
  br i1 %r254, label %bb57, label %bb56

bb57:                                             ; preds = %bb54
  %r255 = call i32 @stack_peek(ptr %r228)
  %r256 = call i32 @get_op_prec(i32 %r255)
  %r257 = load i32, ptr %r247, align 4
  %r258 = call i32 @get_op_prec(i32 %r257)
  %r259 = icmp sge i32 %r256, %r258
  br i1 %r259, label %bb55, label %bb56

bb55:                                             ; preds = %bb57
  %r261 = call i32 @stack_pop(ptr %r228)
  store i32 %r261, ptr %r260, align 4
  %r263 = call i32 @stack_pop(ptr %r227)
  store i32 %r263, ptr %r262, align 4
  %r265 = call i32 @stack_pop(ptr %r227)
  store i32 %r265, ptr %r264, align 4
  %r266 = load i32, ptr %r260, align 4
  %r267 = load i32, ptr %r264, align 4
  %r268 = load i32, ptr %r262, align 4
  %r269 = call i32 @eval_op(i32 %r266, i32 %r267, i32 %r268)
  call void @stack_push(ptr %r227, i32 %r269)
  br label %bb54

bb56:                                             ; preds = %bb57, %bb54
  %r270 = load i32, ptr %r247, align 4
  call void @stack_push(ptr %r228, i32 %r270)
  %r271 = load i32, ptr @cur_token, align 4
  %r272 = load i32, ptr @TOKEN_NUM, align 4
  %r273 = icmp ne i32 %r271, %r272
  br i1 %r273, label %bb58, label %bb59

bb58:                                             ; preds = %bb56
  %r274 = call i32 @panic()
  ret i32 %r274

bb78:                                             ; No predecessors!
  br label %bb60

bb59:                                             ; preds = %bb56
  br label %bb60

bb60:                                             ; preds = %bb59, %bb78
  %r275 = load i32, ptr @num, align 4
  call void @stack_push(ptr %r227, i32 %r275)
  %r276 = call i32 @next_token()
  br label %bb48

bb50:                                             ; preds = %bb51, %bb48
  %r277 = call i32 @next_token()
  br label %bb61

bb61:                                             ; preds = %bb62, %bb50
  %r278 = call i32 @stack_size(ptr %r228)
  %r279 = icmp ne i32 %r278, 0
  br i1 %r279, label %bb62, label %bb63

bb62:                                             ; preds = %bb61
  %r281 = call i32 @stack_pop(ptr %r228)
  store i32 %r281, ptr %r280, align 4
  %r283 = call i32 @stack_pop(ptr %r227)
  store i32 %r283, ptr %r282, align 4
  %r285 = call i32 @stack_pop(ptr %r227)
  store i32 %r285, ptr %r284, align 4
  %r286 = load i32, ptr %r280, align 4
  %r287 = load i32, ptr %r284, align 4
  %r288 = load i32, ptr %r282, align 4
  %r289 = call i32 @eval_op(i32 %r286, i32 %r287, i32 %r288)
  call void @stack_push(ptr %r227, i32 %r289)
  br label %bb61

bb63:                                             ; preds = %bb61
  %r290 = call i32 @stack_peek(ptr %r227)
  ret i32 %r290
}

define i32 @main() {
main:
  %r292 = call i32 @getint()
  %r291 = alloca i32, align 4
  store i32 %r292, ptr %r291, align 4
  %r293 = call i32 @getch()
  %r294 = call i32 @next_token()
  br label %bb64

bb64:                                             ; preds = %bb65, %main
  %r295 = load i32, ptr %r291, align 4
  %r296 = icmp ne i32 %r295, 0
  br i1 %r296, label %bb65, label %bb66

bb65:                                             ; preds = %bb64
  %r297 = call i32 @eval()
  call void @putint(i32 %r297)
  call void @putch(i32 10)
  %r298 = load i32, ptr %r291, align 4
  %r299 = sub i32 %r298, 1
  store i32 %r299, ptr %r291, align 4
  br label %bb64

bb66:                                             ; preds = %bb64
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @before_main() #0 {
  %1 = alloca i32, align 4
  store i32 0, ptr %1, align 4
  br label %2

2:                                                ; preds = %18, %0
  %3 = load i32, ptr %1, align 4
  %4 = icmp slt i32 %3, 1024
  br i1 %4, label %5, label %21

5:                                                ; preds = %2
  %6 = load i32, ptr %1, align 4
  %7 = sext i32 %6 to i64
  %8 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %7
  store i32 0, ptr %8, align 4
  %9 = load i32, ptr %1, align 4
  %10 = sext i32 %9 to i64
  %11 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %10
  store i32 0, ptr %11, align 4
  %12 = load i32, ptr %1, align 4
  %13 = sext i32 %12 to i64
  %14 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %13
  store i32 0, ptr %14, align 4
  %15 = load i32, ptr %1, align 4
  %16 = sext i32 %15 to i64
  %17 = getelementptr inbounds [1024 x i32], ptr @_sysy_h, i64 0, i64 %16
  store i32 0, ptr %17, align 4
  br label %18

18:                                               ; preds = %5
  %19 = load i32, ptr %1, align 4
  %20 = add nsw i32 %19, 1
  store i32 %20, ptr %1, align 4
  br label %2, !llvm.loop !6

21:                                               ; preds = %2
  store i32 1, ptr @_sysy_idx, align 4
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @after_main() #0 {
  %1 = alloca i32, align 4
  store i32 1, ptr %1, align 4
  br label %2

2:                                                ; preds = %63, %0
  %3 = load i32, ptr %1, align 4
  %4 = load i32, ptr @_sysy_idx, align 4
  %5 = icmp slt i32 %3, %4
  br i1 %5, label %6, label %66

6:                                                ; preds = %2
  %7 = load ptr, ptr @stderr, align 8
  %8 = load i32, ptr %1, align 4
  %9 = sext i32 %8 to i64
  %10 = getelementptr inbounds [1024 x i32], ptr @_sysy_l1, i64 0, i64 %9
  %11 = load i32, ptr %10, align 4
  %12 = load i32, ptr %1, align 4
  %13 = sext i32 %12 to i64
  %14 = getelementptr inbounds [1024 x i32], ptr @_sysy_l2, i64 0, i64 %13
  %15 = load i32, ptr %14, align 4
  %16 = load i32, ptr %1, align 4
  %17 = sext i32 %16 to i64
  %18 = getelementptr inbounds [1024 x i32], ptr @_sysy_h, i64 0, i64 %17
  %19 = load i32, ptr %18, align 4
  %20 = load i32, ptr %1, align 4
  %21 = sext i32 %20 to i64
  %22 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %21
  %23 = load i32, ptr %22, align 4
  %24 = load i32, ptr %1, align 4
  %25 = sext i32 %24 to i64
  %26 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %25
  %27 = load i32, ptr %26, align 4
  %28 = load i32, ptr %1, align 4
  %29 = sext i32 %28 to i64
  %30 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %29
  %31 = load i32, ptr %30, align 4
  %32 = call i32 (ptr, ptr, ...) @fprintf(ptr noundef %7, ptr noundef getelementptr inbounds ([35 x i8], ptr @.str.5, i64 0, i64 0), i32 noundef %11, i32 noundef %15, i32 noundef %19, i32 noundef %23, i32 noundef %27, i32 noundef %31)
  %33 = load i32, ptr %1, align 4
  %34 = sext i32 %33 to i64
  %35 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %34
  %36 = load i32, ptr %35, align 4
  %37 = load i32, ptr getelementptr inbounds ([1024 x i32], ptr @_sysy_us, i64 0, i64 0), align 16
  %38 = add nsw i32 %37, %36
  store i32 %38, ptr getelementptr inbounds ([1024 x i32], ptr @_sysy_us, i64 0, i64 0), align 16
  %39 = load i32, ptr %1, align 4
  %40 = sext i32 %39 to i64
  %41 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %40
  %42 = load i32, ptr %41, align 4
  %43 = load i32, ptr getelementptr inbounds ([1024 x i32], ptr @_sysy_s, i64 0, i64 0), align 16
  %44 = add nsw i32 %43, %42
  store i32 %44, ptr getelementptr inbounds ([1024 x i32], ptr @_sysy_s, i64 0, i64 0), align 16
  %45 = load i32, ptr getelementptr inbounds ([1024 x i32], ptr @_sysy_us, i64 0, i64 0), align 16
  %46 = srem i32 %45, 1000000
  store i32 %46, ptr getelementptr inbounds ([1024 x i32], ptr @_sysy_us, i64 0, i64 0), align 16
  %47 = load i32, ptr %1, align 4
  %48 = sext i32 %47 to i64
  %49 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %48
  %50 = load i32, ptr %49, align 4
  %51 = load i32, ptr getelementptr inbounds ([1024 x i32], ptr @_sysy_m, i64 0, i64 0), align 16
  %52 = add nsw i32 %51, %50
  store i32 %52, ptr getelementptr inbounds ([1024 x i32], ptr @_sysy_m, i64 0, i64 0), align 16
  %53 = load i32, ptr getelementptr inbounds ([1024 x i32], ptr @_sysy_s, i64 0, i64 0), align 16
  %54 = srem i32 %53, 60
  store i32 %54, ptr getelementptr inbounds ([1024 x i32], ptr @_sysy_s, i64 0, i64 0), align 16
  %55 = load i32, ptr %1, align 4
  %56 = sext i32 %55 to i64
  %57 = getelementptr inbounds [1024 x i32], ptr @_sysy_h, i64 0, i64 %56
  %58 = load i32, ptr %57, align 4
  %59 = load i32, ptr getelementptr inbounds ([1024 x i32], ptr @_sysy_h, i64 0, i64 0), align 16
  %60 = add nsw i32 %59, %58
  store i32 %60, ptr getelementptr inbounds ([1024 x i32], ptr @_sysy_h, i64 0, i64 0), align 16
  %61 = load i32, ptr getelementptr inbounds ([1024 x i32], ptr @_sysy_m, i64 0, i64 0), align 16
  %62 = srem i32 %61, 60
  store i32 %62, ptr getelementptr inbounds ([1024 x i32], ptr @_sysy_m, i64 0, i64 0), align 16
  br label %63

63:                                               ; preds = %6
  %64 = load i32, ptr %1, align 4
  %65 = add nsw i32 %64, 1
  store i32 %65, ptr %1, align 4
  br label %2, !llvm.loop !8

66:                                               ; preds = %2
  %67 = load ptr, ptr @stderr, align 8
  %68 = load i32, ptr getelementptr inbounds ([1024 x i32], ptr @_sysy_h, i64 0, i64 0), align 16
  %69 = load i32, ptr getelementptr inbounds ([1024 x i32], ptr @_sysy_m, i64 0, i64 0), align 16
  %70 = load i32, ptr getelementptr inbounds ([1024 x i32], ptr @_sysy_s, i64 0, i64 0), align 16
  %71 = load i32, ptr getelementptr inbounds ([1024 x i32], ptr @_sysy_us, i64 0, i64 0), align 16
  %72 = call i32 (ptr, ptr, ...) @fprintf(ptr noundef %67, ptr noundef getelementptr inbounds ([25 x i8], ptr @.str.6, i64 0, i64 0), i32 noundef %68, i32 noundef %69, i32 noundef %70, i32 noundef %71)
  ret void
}

declare i32 @fprintf(ptr noundef, ptr noundef, ...) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @getint() #0 {
  %1 = alloca i32, align 4
  %2 = call i32 (ptr, ...) @__isoc99_scanf(ptr noundef getelementptr inbounds ([3 x i8], ptr @.str, i64 0, i64 0), ptr noundef %1)
  %3 = load i32, ptr %1, align 4
  ret i32 %3
}

declare i32 @__isoc99_scanf(ptr noundef, ...) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @getch() #0 {
  %1 = alloca i8, align 1
  %2 = call i32 (ptr, ...) @__isoc99_scanf(ptr noundef getelementptr inbounds ([3 x i8], ptr @.str.1, i64 0, i64 0), ptr noundef %1)
  %3 = load i8, ptr %1, align 1
  %4 = sext i8 %3 to i32
  ret i32 %4
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @getarray(ptr noundef %0) #0 {
  %2 = alloca ptr, align 8
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store ptr %0, ptr %2, align 8
  %5 = call i32 (ptr, ...) @__isoc99_scanf(ptr noundef getelementptr inbounds ([3 x i8], ptr @.str, i64 0, i64 0), ptr noundef %3)
  store i32 0, ptr %4, align 4
  br label %6

6:                                                ; preds = %16, %1
  %7 = load i32, ptr %4, align 4
  %8 = load i32, ptr %3, align 4
  %9 = icmp slt i32 %7, %8
  br i1 %9, label %10, label %19

10:                                               ; preds = %6
  %11 = load ptr, ptr %2, align 8
  %12 = load i32, ptr %4, align 4
  %13 = sext i32 %12 to i64
  %14 = getelementptr inbounds i32, ptr %11, i64 %13
  %15 = call i32 (ptr, ...) @__isoc99_scanf(ptr noundef getelementptr inbounds ([3 x i8], ptr @.str, i64 0, i64 0), ptr noundef %14)
  br label %16

16:                                               ; preds = %10
  %17 = load i32, ptr %4, align 4
  %18 = add nsw i32 %17, 1
  store i32 %18, ptr %4, align 4
  br label %6, !llvm.loop !9

19:                                               ; preds = %6
  %20 = load i32, ptr %3, align 4
  ret i32 %20
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @putint(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = load i32, ptr %2, align 4
  %4 = call i32 (ptr, ...) @printf(ptr noundef getelementptr inbounds ([3 x i8], ptr @.str, i64 0, i64 0), i32 noundef %3)
  ret void
}

declare i32 @printf(ptr noundef, ...) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @putch(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = load i32, ptr %2, align 4
  %4 = call i32 (ptr, ...) @printf(ptr noundef getelementptr inbounds ([3 x i8], ptr @.str.1, i64 0, i64 0), i32 noundef %3)
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @putarray(i32 noundef %0, ptr noundef %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca ptr, align 8
  %5 = alloca i32, align 4
  store i32 %0, ptr %3, align 4
  store ptr %1, ptr %4, align 8
  %6 = load i32, ptr %3, align 4
  %7 = call i32 (ptr, ...) @printf(ptr noundef getelementptr inbounds ([4 x i8], ptr @.str.2, i64 0, i64 0), i32 noundef %6)
  store i32 0, ptr %5, align 4
  br label %8

8:                                                ; preds = %19, %2
  %9 = load i32, ptr %5, align 4
  %10 = load i32, ptr %3, align 4
  %11 = icmp slt i32 %9, %10
  br i1 %11, label %12, label %22

12:                                               ; preds = %8
  %13 = load ptr, ptr %4, align 8
  %14 = load i32, ptr %5, align 4
  %15 = sext i32 %14 to i64
  %16 = getelementptr inbounds i32, ptr %13, i64 %15
  %17 = load i32, ptr %16, align 4
  %18 = call i32 (ptr, ...) @printf(ptr noundef getelementptr inbounds ([4 x i8], ptr @.str.3, i64 0, i64 0), i32 noundef %17)
  br label %19

19:                                               ; preds = %12
  %20 = load i32, ptr %5, align 4
  %21 = add nsw i32 %20, 1
  store i32 %21, ptr %5, align 4
  br label %8, !llvm.loop !10

22:                                               ; preds = %8
  %23 = call i32 (ptr, ...) @printf(ptr noundef getelementptr inbounds ([2 x i8], ptr @.str.4, i64 0, i64 0))
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @_sysy_starttime(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = load i32, ptr %2, align 4
  %4 = load i32, ptr @_sysy_idx, align 4
  %5 = sext i32 %4 to i64
  %6 = getelementptr inbounds [1024 x i32], ptr @_sysy_l1, i64 0, i64 %5
  store i32 %3, ptr %6, align 4
  %7 = call i32 @gettimeofday(ptr noundef @_sysy_start, ptr noundef null) #3
  ret void
}

; Function Attrs: nounwind
declare i32 @gettimeofday(ptr noundef, ptr noundef) #2

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @_sysy_stoptime(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = call i32 @gettimeofday(ptr noundef @_sysy_end, ptr noundef null) #3
  %4 = load i32, ptr %2, align 4
  %5 = load i32, ptr @_sysy_idx, align 4
  %6 = sext i32 %5 to i64
  %7 = getelementptr inbounds [1024 x i32], ptr @_sysy_l2, i64 0, i64 %6
  store i32 %4, ptr %7, align 4
  %8 = load i64, ptr getelementptr inbounds (%struct.timeval, ptr @_sysy_end, i32 0, i32 0), align 8
  %9 = load i64, ptr getelementptr inbounds (%struct.timeval, ptr @_sysy_start, i32 0, i32 0), align 8
  %10 = sub nsw i64 %8, %9
  %11 = mul nsw i64 1000000, %10
  %12 = load i64, ptr getelementptr inbounds (%struct.timeval, ptr @_sysy_end, i32 0, i32 1), align 8
  %13 = add nsw i64 %11, %12
  %14 = load i64, ptr getelementptr inbounds (%struct.timeval, ptr @_sysy_start, i32 0, i32 1), align 8
  %15 = sub nsw i64 %13, %14
  %16 = load i32, ptr @_sysy_idx, align 4
  %17 = sext i32 %16 to i64
  %18 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %17
  %19 = load i32, ptr %18, align 4
  %20 = sext i32 %19 to i64
  %21 = add nsw i64 %20, %15
  %22 = trunc i64 %21 to i32
  store i32 %22, ptr %18, align 4
  %23 = load i32, ptr @_sysy_idx, align 4
  %24 = sext i32 %23 to i64
  %25 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %24
  %26 = load i32, ptr %25, align 4
  %27 = sdiv i32 %26, 1000000
  %28 = load i32, ptr @_sysy_idx, align 4
  %29 = sext i32 %28 to i64
  %30 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %29
  %31 = load i32, ptr %30, align 4
  %32 = add nsw i32 %31, %27
  store i32 %32, ptr %30, align 4
  %33 = load i32, ptr @_sysy_idx, align 4
  %34 = sext i32 %33 to i64
  %35 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %34
  %36 = load i32, ptr %35, align 4
  %37 = srem i32 %36, 1000000
  store i32 %37, ptr %35, align 4
  %38 = load i32, ptr @_sysy_idx, align 4
  %39 = sext i32 %38 to i64
  %40 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %39
  %41 = load i32, ptr %40, align 4
  %42 = sdiv i32 %41, 60
  %43 = load i32, ptr @_sysy_idx, align 4
  %44 = sext i32 %43 to i64
  %45 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %44
  %46 = load i32, ptr %45, align 4
  %47 = add nsw i32 %46, %42
  store i32 %47, ptr %45, align 4
  %48 = load i32, ptr @_sysy_idx, align 4
  %49 = sext i32 %48 to i64
  %50 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %49
  %51 = load i32, ptr %50, align 4
  %52 = srem i32 %51, 60
  store i32 %52, ptr %50, align 4
  %53 = load i32, ptr @_sysy_idx, align 4
  %54 = sext i32 %53 to i64
  %55 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %54
  %56 = load i32, ptr %55, align 4
  %57 = sdiv i32 %56, 60
  %58 = load i32, ptr @_sysy_idx, align 4
  %59 = sext i32 %58 to i64
  %60 = getelementptr inbounds [1024 x i32], ptr @_sysy_h, i64 0, i64 %59
  %61 = load i32, ptr %60, align 4
  %62 = add nsw i32 %61, %57
  store i32 %62, ptr %60, align 4
  %63 = load i32, ptr @_sysy_idx, align 4
  %64 = sext i32 %63 to i64
  %65 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %64
  %66 = load i32, ptr %65, align 4
  %67 = srem i32 %66, 60
  store i32 %67, ptr %65, align 4
  %68 = load i32, ptr @_sysy_idx, align 4
  %69 = add nsw i32 %68, 1
  store i32 %69, ptr @_sysy_idx, align 4
  ret void
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { nounwind }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1, !2, !3, !4, !5}

!0 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
!1 = !{i32 1, !"wchar_size", i32 4}
!2 = !{i32 7, !"PIC Level", i32 2}
!3 = !{i32 7, !"PIE Level", i32 2}
!4 = !{i32 7, !"uwtable", i32 1}
!5 = !{i32 7, !"frame-pointer", i32 2}
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
!8 = distinct !{!8, !7}
!9 = distinct !{!9, !7}
!10 = distinct !{!10, !7}
