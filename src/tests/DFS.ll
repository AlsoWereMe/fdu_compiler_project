declare i32 @getch( )
declare i32 @getint( )
declare void @putint( i32 )
declare void @putch( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@n = global i32 0
@m = global i32 0
@to = global [ 5005 x i32 ] zeroinitializer
@next = global [ 5005 x i32 ] zeroinitializer
@head = global [ 1005 x i32 ] zeroinitializer
@cnt = global i32 0
@vis = global [ 1005 x i32 ] zeroinitializer
define i32 @quickread( ) {
quickread:
  %r101 = call i32 @getch()
  %r100 = alloca i32
  store i32 %r101, i32* %r100
  %r102 = alloca i32
  store i32 0, i32* %r102
  %r103 = alloca i32
  store i32 0, i32* %r103
  br label %bb1

bb1:
  %r104 = load i32, i32* %r100
  %r105 = icmp slt i32 %r104, 48
  br i1 %r105, label %bb2, label %bb4

bb4:
  %r106 = load i32, i32* %r100
  %r107 = icmp sgt i32 %r106, 57
  br i1 %r107, label %bb2, label %bb3

bb2:
  %r108 = load i32, i32* %r100
  %r109 = icmp eq i32 %r108, 45
  br i1 %r109, label %bb5, label %bb6

bb5:
  store i32 1, i32* %r103
  br label %bb7

bb6:
  br label %bb7

bb7:
  %r110 = call i32 @getch()
  store i32 %r110, i32* %r100
  br label %bb1

bb3:
  br label %bb8

bb8:
  %r111 = load i32, i32* %r100
  %r112 = icmp sge i32 %r111, 48
  br i1 %r112, label %bb11, label %bb10

bb11:
  %r113 = load i32, i32* %r100
  %r114 = icmp sle i32 %r113, 57
  br i1 %r114, label %bb9, label %bb10

bb9:
  %r115 = load i32, i32* %r102
  %r116 = mul i32 %r115, 10
  %r117 = load i32, i32* %r100
  %r118 = add i32 %r116, %r117
  %r119 = sub i32 %r118, 48
  store i32 %r119, i32* %r102
  %r120 = call i32 @getch()
  store i32 %r120, i32* %r100
  br label %bb8

bb10:
  %r121 = load i32, i32* %r103
  %r122 = icmp ne i32 %r121, 0
  br i1 %r122, label %bb12, label %bb13

bb12:
  %r123 = load i32, i32* %r102
  %r124 = sub i32 0, %r123
  ret i32 %r124
bb41:
  br label %bb14

bb13:
  %r125 = load i32, i32* %r102
  ret i32 %r125
bb14:
  ret i32 0
}

define void @addedge( i32 %r126, i32 %r128 ) {
addedge:
  %r127 = alloca i32
  store i32 %r126, i32* %r127
  %r129 = alloca i32
  store i32 %r128, i32* %r129
  %r130 = load i32, i32* @cnt
  %r131 = getelementptr [5005 x i32 ], [5005 x i32 ]* @to, i32 0, i32 %r130
  %r132 = load i32, i32* %r129
  store i32 %r132, i32* %r131
  %r133 = load i32, i32* @cnt
  %r134 = getelementptr [5005 x i32 ], [5005 x i32 ]* @next, i32 0, i32 %r133
  %r135 = load i32, i32* %r127
  %r136 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r135
  %r137 = load i32, i32* %r136
  store i32 %r137, i32* %r134
  %r138 = load i32, i32* %r127
  %r139 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r138
  %r140 = load i32, i32* @cnt
  store i32 %r140, i32* %r139
  %r141 = load i32, i32* @cnt
  %r142 = add i32 %r141, 1
  store i32 %r142, i32* @cnt
  %r143 = load i32, i32* @cnt
  %r144 = getelementptr [5005 x i32 ], [5005 x i32 ]* @to, i32 0, i32 %r143
  %r145 = load i32, i32* %r127
  store i32 %r145, i32* %r144
  %r146 = load i32, i32* @cnt
  %r147 = getelementptr [5005 x i32 ], [5005 x i32 ]* @next, i32 0, i32 %r146
  %r148 = load i32, i32* %r129
  %r149 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r148
  %r150 = load i32, i32* %r149
  store i32 %r150, i32* %r147
  %r151 = load i32, i32* %r129
  %r152 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r151
  %r153 = load i32, i32* @cnt
  store i32 %r153, i32* %r152
  %r154 = load i32, i32* @cnt
  %r155 = add i32 %r154, 1
  store i32 %r155, i32* @cnt
  ret void
}

define void @init( ) {
init:
  %r156 = alloca i32
  store i32 0, i32* %r156
  br label %bb15

bb15:
  %r157 = load i32, i32* %r156
  %r158 = icmp slt i32 %r157, 1005
  br i1 %r158, label %bb16, label %bb17

bb16:
  %r159 = load i32, i32* %r156
  %r160 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r159
  %r161 = sub i32 0, 1
  store i32 %r161, i32* %r160
  %r162 = load i32, i32* %r156
  %r163 = add i32 %r162, 1
  store i32 %r163, i32* %r156
  br label %bb15

bb17:
  ret void
}

define void @clear( ) {
clear:
  %r164 = alloca i32
  store i32 1, i32* %r164
  br label %bb18

bb18:
  %r165 = load i32, i32* %r164
  %r166 = load i32, i32* @n
  %r167 = icmp sle i32 %r165, %r166
  br i1 %r167, label %bb19, label %bb20

bb19:
  %r168 = load i32, i32* %r164
  %r169 = getelementptr [1005 x i32 ], [1005 x i32 ]* @vis, i32 0, i32 %r168
  store i32 0, i32* %r169
  %r170 = load i32, i32* %r164
  %r171 = add i32 %r170, 1
  store i32 %r171, i32* %r164
  br label %bb18

bb20:
  ret void
}

define i32 @same( i32 %r172, i32 %r174 ) {
same:
  %r188 = alloca i32
  %r181 = alloca i32
  %r173 = alloca i32
  store i32 %r172, i32* %r173
  %r175 = alloca i32
  store i32 %r174, i32* %r175
  %r176 = load i32, i32* %r173
  %r177 = getelementptr [1005 x i32 ], [1005 x i32 ]* @vis, i32 0, i32 %r176
  store i32 1, i32* %r177
  %r178 = load i32, i32* %r173
  %r179 = load i32, i32* %r175
  %r180 = icmp eq i32 %r178, %r179
  br i1 %r180, label %bb21, label %bb22

bb21:
  ret i32 1
bb42:
  br label %bb23

bb22:
  br label %bb23

bb23:
  %r182 = load i32, i32* %r173
  %r183 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r182
  %r184 = load i32, i32* %r183
  store i32 %r184, i32* %r181
  br label %bb24

bb24:
  %r185 = load i32, i32* %r181
  %r186 = sub i32 0, 1
  %r187 = icmp ne i32 %r185, %r186
  br i1 %r187, label %bb25, label %bb26

bb25:
  %r189 = load i32, i32* %r181
  %r190 = getelementptr [5005 x i32 ], [5005 x i32 ]* @to, i32 0, i32 %r189
  %r191 = load i32, i32* %r190
  store i32 %r191, i32* %r188
  %r192 = load i32, i32* %r188
  %r193 = getelementptr [1005 x i32 ], [1005 x i32 ]* @vis, i32 0, i32 %r192
  %r194 = load i32, i32* %r193
  %r195 = icmp eq i32 %r194, 0
  br i1 %r195, label %bb29, label %bb28

bb29:
  %r196 = load i32, i32* %r188
  %r197 = load i32, i32* %r175
  %r198 = call i32 @same(i32 %r196, i32 %r197)
  %r199 = icmp ne i32 %r198, 0
  br i1 %r199, label %bb27, label %bb28

bb27:
  ret i32 1
bb43:
  br label %bb30

bb28:
  br label %bb30

bb30:
  %r200 = load i32, i32* %r181
  %r201 = getelementptr [5005 x i32 ], [5005 x i32 ]* @next, i32 0, i32 %r200
  %r202 = load i32, i32* %r201
  store i32 %r202, i32* %r181
  br label %bb24

bb26:
  ret i32 0
}

define i32 @main( ) {
main:
  %r203 = call i32 @quickread()
  store i32 %r203, i32* @n
  %r204 = call i32 @quickread()
  store i32 %r204, i32* @m
  call void @init()
  %r205 = alloca i32
  store i32 0, i32* %r205
  %r206 = alloca i32
  store i32 0, i32* %r206
  %r207 = alloca i32
  store i32 0, i32* %r207
  br label %bb31

bb31:
  %r208 = load i32, i32* @m
  %r209 = icmp ne i32 %r208, 0
  br i1 %r209, label %bb32, label %bb33

bb32:
  %r210 = call i32 @getch()
  store i32 %r210, i32* %r205
  br label %bb34

bb34:
  %r211 = load i32, i32* %r205
  %r212 = icmp ne i32 %r211, 81
  br i1 %r212, label %bb37, label %bb36

bb37:
  %r213 = load i32, i32* %r205
  %r214 = icmp ne i32 %r213, 85
  br i1 %r214, label %bb35, label %bb36

bb35:
  %r215 = call i32 @getch()
  store i32 %r215, i32* %r205
  br label %bb34

bb36:
  %r216 = load i32, i32* %r205
  %r217 = icmp eq i32 %r216, 81
  br i1 %r217, label %bb38, label %bb39

bb38:
  %r218 = call i32 @quickread()
  store i32 %r218, i32* %r206
  %r219 = call i32 @quickread()
  store i32 %r219, i32* %r207
  call void @clear()
  %r220 = load i32, i32* %r206
  %r221 = load i32, i32* %r207
  %r222 = call i32 @same(i32 %r220, i32 %r221)
  call void @putint(i32 %r222)
  call void @putch(i32 10)
  br label %bb40

bb39:
  %r223 = call i32 @quickread()
  store i32 %r223, i32* %r206
  %r224 = call i32 @quickread()
  store i32 %r224, i32* %r207
  %r225 = load i32, i32* %r206
  %r226 = load i32, i32* %r207
  call void @addedge(i32 %r225, i32 %r226)
  br label %bb40

bb40:
  %r227 = load i32, i32* @m
  %r228 = sub i32 %r227, 1
  store i32 %r228, i32* @m
  br label %bb31

bb33:
  ret i32 0
}

