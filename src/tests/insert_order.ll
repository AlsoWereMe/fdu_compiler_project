declare i32 @getch( )
declare i32 @getint( )
declare void @putint( i32 )
declare void @putch( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@N = global i32 0
define i32 @insert( i32* %r100, i32 %r101 ) {
insert:
  %r119 = alloca i32
  %r102 = alloca i32
  store i32 %r101, i32* %r102
  %r103 = alloca i32
  %r104 = alloca i32
  store i32 0, i32* %r103
  br label %bb1

bb1:
  %r105 = load i32, i32* %r102
  %r106 = load i32, i32* %r103
  %r107 = getelementptr i32, i32* %r100, i32 %r106
  %r108 = load i32, i32* %r107
  %r109 = icmp sgt i32 %r105, %r108
  br i1 %r109, label %bb4, label %bb3

bb4:
  %r110 = load i32, i32* %r103
  %r111 = load i32, i32* @N
  %r112 = icmp slt i32 %r110, %r111
  br i1 %r112, label %bb2, label %bb3

bb2:
  %r113 = load i32, i32* %r103
  %r114 = add i32 %r113, 1
  store i32 %r114, i32* %r103
  br label %bb1

bb3:
  %r115 = load i32, i32* @N
  store i32 %r115, i32* %r104
  br label %bb5

bb5:
  %r116 = load i32, i32* %r104
  %r117 = load i32, i32* %r103
  %r118 = icmp sgt i32 %r116, %r117
  br i1 %r118, label %bb6, label %bb7

bb6:
  %r120 = load i32, i32* %r104
  %r121 = sub i32 %r120, 1
  store i32 %r121, i32* %r119
  %r122 = load i32, i32* %r104
  %r123 = getelementptr i32, i32* %r100, i32 %r122
  %r124 = load i32, i32* %r119
  %r125 = getelementptr i32, i32* %r100, i32 %r124
  %r126 = load i32, i32* %r125
  store i32 %r126, i32* %r123
  %r127 = load i32, i32* %r103
  %r128 = getelementptr i32, i32* %r100, i32 %r127
  %r129 = load i32, i32* %r102
  store i32 %r129, i32* %r128
  %r130 = load i32, i32* %r104
  %r131 = sub i32 %r130, 1
  store i32 %r131, i32* %r104
  br label %bb5

bb7:
  ret i32 0
}

define i32 @main( ) {
main:
  store i32 10, i32* @N
  %r132 = alloca [ 11 x i32 ]
  %r133 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 0
  store i32 1, i32* %r133
  %r134 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 1
  store i32 3, i32* %r134
  %r135 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 2
  store i32 4, i32* %r135
  %r136 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 3
  store i32 7, i32* %r136
  %r137 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 4
  store i32 8, i32* %r137
  %r138 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 5
  store i32 11, i32* %r138
  %r139 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 6
  store i32 13, i32* %r139
  %r140 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 7
  store i32 18, i32* %r140
  %r141 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 8
  store i32 56, i32* %r141
  %r142 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 9
  store i32 78, i32* %r142
  %r143 = alloca i32
  %r144 = alloca i32
  store i32 0, i32* %r144
  %r145 = call i32 @getint()
  store i32 %r145, i32* %r143
  %r146 = load i32, i32* %r143
  %r147 = call i32 @insert(i32* %r132, i32 %r146)
  store i32 %r147, i32* %r143
  br label %bb8

bb8:
  %r148 = load i32, i32* %r144
  %r149 = load i32, i32* @N
  %r150 = icmp slt i32 %r148, %r149
  br i1 %r150, label %bb9, label %bb10

bb9:
  %r151 = load i32, i32* %r144
  %r152 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 %r151
  %r153 = load i32, i32* %r152
  store i32 %r153, i32* %r143
  %r154 = load i32, i32* %r143
  call void @putint(i32 %r154)
  store i32 10, i32* %r143
  %r155 = load i32, i32* %r143
  call void @putch(i32 %r155)
  %r156 = load i32, i32* %r144
  %r157 = add i32 %r156, 1
  store i32 %r157, i32* %r144
  br label %bb8

bb10:
  ret i32 0
}

