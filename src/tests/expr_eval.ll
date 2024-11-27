declare i32 @getch( )
declare i32 @getint( )
declare void @putint( i32 )
declare void @putch( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@TOKEN_NUM = global i32 0
@TOKEN_OTHER = global i32 1
@last_char = global i32 32
@num = global i32 0
@other = global i32 0
@cur_token = global i32 0
define i32 @next_char( ) {
next_char:
  %r100 = call i32 @getch()
  store i32 %r100, i32* @last_char
  %r101 = load i32, i32* @last_char
  ret i32 %r101
}

define i32 @is_space( i32 %r102 ) {
is_space:
  %r103 = alloca i32
  store i32 %r102, i32* %r103
  %r104 = load i32, i32* %r103
  %r105 = icmp eq i32 %r104, 32
  br i1 %r105, label %bb1, label %bb3

bb3:
  %r106 = load i32, i32* %r103
  %r107 = icmp eq i32 %r106, 10
  br i1 %r107, label %bb1, label %bb2

bb1:
  ret i32 1
bb67:
  br label %bb4

bb2:
  ret i32 0
bb4:
  ret i32 0
}

define i32 @is_num( i32 %r108 ) {
is_num:
  %r109 = alloca i32
  store i32 %r108, i32* %r109
  %r110 = load i32, i32* %r109
  %r111 = icmp sge i32 %r110, 48
  br i1 %r111, label %bb7, label %bb6

bb7:
  %r112 = load i32, i32* %r109
  %r113 = icmp sle i32 %r112, 57
  br i1 %r113, label %bb5, label %bb6

bb5:
  ret i32 1
bb68:
  br label %bb8

bb6:
  ret i32 0
bb8:
  ret i32 0
}

define i32 @next_token( ) {
next_token:
  br label %bb9

bb9:
  %r114 = load i32, i32* @last_char
  %r115 = call i32 @is_space(i32 %r114)
  %r116 = icmp ne i32 %r115, 0
  br i1 %r116, label %bb10, label %bb11

bb10:
  %r117 = call i32 @next_char()
  br label %bb9

bb11:
  %r118 = load i32, i32* @last_char
  %r119 = call i32 @is_num(i32 %r118)
  %r120 = icmp ne i32 %r119, 0
  br i1 %r120, label %bb12, label %bb13

bb12:
  %r121 = load i32, i32* @last_char
  %r122 = sub i32 %r121, 48
  store i32 %r122, i32* @num
  br label %bb14

bb14:
  %r123 = call i32 @next_char()
  %r124 = call i32 @is_num(i32 %r123)
  %r125 = icmp ne i32 %r124, 0
  br i1 %r125, label %bb15, label %bb16

bb15:
  %r126 = load i32, i32* @num
  %r127 = mul i32 %r126, 10
  %r128 = load i32, i32* @last_char
  %r129 = add i32 %r127, %r128
  %r130 = sub i32 %r129, 48
  store i32 %r130, i32* @num
  br label %bb14

bb16:
  %r131 = load i32, i32* @TOKEN_NUM
  store i32 %r131, i32* @cur_token
  br label %bb17

bb13:
  %r132 = load i32, i32* @last_char
  store i32 %r132, i32* @other
  %r133 = call i32 @next_char()
  %r134 = load i32, i32* @TOKEN_OTHER
  store i32 %r134, i32* @cur_token
  br label %bb17

bb17:
  %r135 = load i32, i32* @cur_token
  ret i32 %r135
}

define i32 @panic( ) {
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

define i32 @get_op_prec( i32 %r137 ) {
get_op_prec:
  %r138 = alloca i32
  store i32 %r137, i32* %r138
  %r139 = load i32, i32* %r138
  %r140 = icmp eq i32 %r139, 43
  br i1 %r140, label %bb18, label %bb20

bb20:
  %r141 = load i32, i32* %r138
  %r142 = icmp eq i32 %r141, 45
  br i1 %r142, label %bb18, label %bb19

bb18:
  ret i32 10
bb69:
  br label %bb21

bb19:
  br label %bb21

bb21:
  %r143 = load i32, i32* %r138
  %r144 = icmp eq i32 %r143, 42
  br i1 %r144, label %bb22, label %bb24

bb24:
  %r145 = load i32, i32* %r138
  %r146 = icmp eq i32 %r145, 47
  br i1 %r146, label %bb22, label %bb25

bb25:
  %r147 = load i32, i32* %r138
  %r148 = icmp eq i32 %r147, 37
  br i1 %r148, label %bb22, label %bb23

bb22:
  ret i32 20
bb70:
  br label %bb26

bb23:
  br label %bb26

bb26:
  ret i32 0
}

define void @stack_push( i32* %r149, i32 %r150 ) {
stack_push:
  %r151 = alloca i32
  store i32 %r150, i32* %r151
  %r152 = getelementptr i32, i32* %r149, i32 0
  %r153 = getelementptr i32, i32* %r149, i32 0
  %r154 = load i32, i32* %r153
  %r155 = add i32 %r154, 1
  store i32 %r155, i32* %r152
  %r157 = getelementptr i32, i32* %r149, i32 0
  %r158 = load i32, i32* %r157
  %r156 = alloca i32
  store i32 %r158, i32* %r156
  %r159 = load i32, i32* %r156
  %r160 = getelementptr i32, i32* %r149, i32 %r159
  %r161 = load i32, i32* %r151
  store i32 %r161, i32* %r160
  ret void
}

define i32 @stack_pop( i32* %r162 ) {
stack_pop:
  %r164 = getelementptr i32, i32* %r162, i32 0
  %r165 = load i32, i32* %r164
  %r163 = alloca i32
  store i32 %r165, i32* %r163
  %r167 = load i32, i32* %r163
  %r168 = getelementptr i32, i32* %r162, i32 %r167
  %r169 = load i32, i32* %r168
  %r166 = alloca i32
  store i32 %r169, i32* %r166
  %r170 = getelementptr i32, i32* %r162, i32 0
  %r171 = getelementptr i32, i32* %r162, i32 0
  %r172 = load i32, i32* %r171
  %r173 = sub i32 %r172, 1
  store i32 %r173, i32* %r170
  %r174 = load i32, i32* %r166
  ret i32 %r174
}

define i32 @stack_peek( i32* %r175 ) {
stack_peek:
  %r177 = getelementptr i32, i32* %r175, i32 0
  %r178 = load i32, i32* %r177
  %r176 = alloca i32
  store i32 %r178, i32* %r176
  %r179 = load i32, i32* %r176
  %r180 = getelementptr i32, i32* %r175, i32 %r179
  %r181 = load i32, i32* %r180
  ret i32 %r181
}

define i32 @stack_size( i32* %r182 ) {
stack_size:
  %r183 = getelementptr i32, i32* %r182, i32 0
  %r184 = load i32, i32* %r183
  ret i32 %r184
}

define i32 @mod( i32 %r185, i32 %r187 ) {
mod:
  %r186 = alloca i32
  store i32 %r185, i32* %r186
  %r188 = alloca i32
  store i32 %r187, i32* %r188
  %r189 = load i32, i32* %r186
  %r190 = load i32, i32* %r186
  %r191 = load i32, i32* %r188
  %r192 = sdiv i32 %r190, %r191
  %r193 = load i32, i32* %r188
  %r194 = mul i32 %r192, %r193
  %r195 = sub i32 %r189, %r194
  ret i32 %r195
}

define i32 @eval_op( i32 %r196, i32 %r198, i32 %r200 ) {
eval_op:
  %r197 = alloca i32
  store i32 %r196, i32* %r197
  %r199 = alloca i32
  store i32 %r198, i32* %r199
  %r201 = alloca i32
  store i32 %r200, i32* %r201
  %r202 = load i32, i32* %r197
  %r203 = icmp eq i32 %r202, 43
  br i1 %r203, label %bb27, label %bb28

bb27:
  %r204 = load i32, i32* %r199
  %r205 = load i32, i32* %r201
  %r206 = add i32 %r204, %r205
  ret i32 %r206
bb71:
  br label %bb29

bb28:
  br label %bb29

bb29:
  %r207 = load i32, i32* %r197
  %r208 = icmp eq i32 %r207, 45
  br i1 %r208, label %bb30, label %bb31

bb30:
  %r209 = load i32, i32* %r199
  %r210 = load i32, i32* %r201
  %r211 = sub i32 %r209, %r210
  ret i32 %r211
bb72:
  br label %bb32

bb31:
  br label %bb32

bb32:
  %r212 = load i32, i32* %r197
  %r213 = icmp eq i32 %r212, 42
  br i1 %r213, label %bb33, label %bb34

bb33:
  %r214 = load i32, i32* %r199
  %r215 = load i32, i32* %r201
  %r216 = mul i32 %r214, %r215
  ret i32 %r216
bb73:
  br label %bb35

bb34:
  br label %bb35

bb35:
  %r217 = load i32, i32* %r197
  %r218 = icmp eq i32 %r217, 47
  br i1 %r218, label %bb36, label %bb37

bb36:
  %r219 = load i32, i32* %r199
  %r220 = load i32, i32* %r201
  %r221 = sdiv i32 %r219, %r220
  ret i32 %r221
bb74:
  br label %bb38

bb37:
  br label %bb38

bb38:
  %r222 = load i32, i32* %r197
  %r223 = icmp eq i32 %r222, 37
  br i1 %r223, label %bb39, label %bb40

bb39:
  %r224 = load i32, i32* %r199
  %r225 = load i32, i32* %r201
  %r226 = call i32 @mod(i32 %r224, i32 %r225)
  ret i32 %r226
bb75:
  br label %bb41

bb40:
  br label %bb41

bb41:
  ret i32 0
}

define i32 @eval( ) {
eval:
  %r284 = alloca i32
  %r282 = alloca i32
  %r280 = alloca i32
  %r264 = alloca i32
  %r262 = alloca i32
  %r260 = alloca i32
  %r247 = alloca i32
  %r227 = alloca [ 256 x i32 ]
  %r228 = alloca [ 256 x i32 ]
  %r229 = alloca i32
  store i32 0, i32* %r229
  br label %bb42

bb42:
  %r230 = load i32, i32* %r229
  %r231 = icmp slt i32 %r230, 256
  br i1 %r231, label %bb43, label %bb44

bb43:
  %r232 = load i32, i32* %r229
  %r233 = getelementptr [256 x i32 ], [256 x i32 ]* %r227, i32 0, i32 %r232
  store i32 0, i32* %r233
  %r234 = load i32, i32* %r229
  %r235 = getelementptr [256 x i32 ], [256 x i32 ]* %r228, i32 0, i32 %r234
  store i32 0, i32* %r235
  %r236 = load i32, i32* %r229
  %r237 = add i32 %r236, 1
  store i32 %r237, i32* %r229
  br label %bb42

bb44:
  %r238 = load i32, i32* @cur_token
  %r239 = load i32, i32* @TOKEN_NUM
  %r240 = icmp ne i32 %r238, %r239
  br i1 %r240, label %bb45, label %bb46

bb45:
  %r241 = call i32 @panic()
  ret i32 %r241
bb76:
  br label %bb47

bb46:
  br label %bb47

bb47:
  %r242 = load i32, i32* @num
  call void @stack_push(i32* %r227, i32 %r242)
  %r243 = call i32 @next_token()
  br label %bb48

bb48:
  %r244 = load i32, i32* @cur_token
  %r245 = load i32, i32* @TOKEN_OTHER
  %r246 = icmp eq i32 %r244, %r245
  br i1 %r246, label %bb49, label %bb50

bb49:
  %r248 = load i32, i32* @other
  store i32 %r248, i32* %r247
  %r249 = load i32, i32* %r247
  %r250 = call i32 @get_op_prec(i32 %r249)
  %r251 = icmp eq i32 %r250, 0
  br i1 %r251, label %bb51, label %bb52

bb51:
  br label %bb50

bb77:
  br label %bb53

bb52:
  br label %bb53

bb53:
  %r252 = call i32 @next_token()
  br label %bb54

bb54:
  %r253 = call i32 @stack_size(i32* %r228)
  %r254 = icmp ne i32 %r253, 0
  br i1 %r254, label %bb57, label %bb56

bb57:
  %r255 = call i32 @stack_peek(i32* %r228)
  %r256 = call i32 @get_op_prec(i32 %r255)
  %r257 = load i32, i32* %r247
  %r258 = call i32 @get_op_prec(i32 %r257)
  %r259 = icmp sge i32 %r256, %r258
  br i1 %r259, label %bb55, label %bb56

bb55:
  %r261 = call i32 @stack_pop(i32* %r228)
  store i32 %r261, i32* %r260
  %r263 = call i32 @stack_pop(i32* %r227)
  store i32 %r263, i32* %r262
  %r265 = call i32 @stack_pop(i32* %r227)
  store i32 %r265, i32* %r264
  %r266 = load i32, i32* %r260
  %r267 = load i32, i32* %r264
  %r268 = load i32, i32* %r262
  %r269 = call i32 @eval_op(i32 %r266, i32 %r267, i32 %r268)
  call void @stack_push(i32* %r227, i32 %r269)
  br label %bb54

bb56:
  %r270 = load i32, i32* %r247
  call void @stack_push(i32* %r228, i32 %r270)
  %r271 = load i32, i32* @cur_token
  %r272 = load i32, i32* @TOKEN_NUM
  %r273 = icmp ne i32 %r271, %r272
  br i1 %r273, label %bb58, label %bb59

bb58:
  %r274 = call i32 @panic()
  ret i32 %r274
bb78:
  br label %bb60

bb59:
  br label %bb60

bb60:
  %r275 = load i32, i32* @num
  call void @stack_push(i32* %r227, i32 %r275)
  %r276 = call i32 @next_token()
  br label %bb48

bb50:
  %r277 = call i32 @next_token()
  br label %bb61

bb61:
  %r278 = call i32 @stack_size(i32* %r228)
  %r279 = icmp ne i32 %r278, 0
  br i1 %r279, label %bb62, label %bb63

bb62:
  %r281 = call i32 @stack_pop(i32* %r228)
  store i32 %r281, i32* %r280
  %r283 = call i32 @stack_pop(i32* %r227)
  store i32 %r283, i32* %r282
  %r285 = call i32 @stack_pop(i32* %r227)
  store i32 %r285, i32* %r284
  %r286 = load i32, i32* %r280
  %r287 = load i32, i32* %r284
  %r288 = load i32, i32* %r282
  %r289 = call i32 @eval_op(i32 %r286, i32 %r287, i32 %r288)
  call void @stack_push(i32* %r227, i32 %r289)
  br label %bb61

bb63:
  %r290 = call i32 @stack_peek(i32* %r227)
  ret i32 %r290
}

define i32 @main( ) {
main:
  %r292 = call i32 @getint()
  %r291 = alloca i32
  store i32 %r292, i32* %r291
  %r293 = call i32 @getch()
  %r294 = call i32 @next_token()
  br label %bb64

bb64:
  %r295 = load i32, i32* %r291
  %r296 = icmp ne i32 %r295, 0
  br i1 %r296, label %bb65, label %bb66

bb65:
  %r297 = call i32 @eval()
  call void @putint(i32 %r297)
  call void @putch(i32 10)
  %r298 = load i32, i32* %r291
  %r299 = sub i32 %r298, 1
  store i32 %r299, i32* %r291
  br label %bb64

bb66:
  ret i32 0
}

