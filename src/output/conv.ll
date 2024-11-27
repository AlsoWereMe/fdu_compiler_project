; ModuleID = 'llvm-link'
source_filename = "llvm-link"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.timeval = type { i64, i64 }

@max = global i32 1073741824
@a = global [10000000 x i32] zeroinitializer
@b = global [10000000 x i32] zeroinitializer
@kernelid_ = global [10000 x i32] zeroinitializer
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

define i32 @checkrange(i32 %r100) {
checkrange:
  %r101 = alloca i32, align 4
  store i32 %r100, ptr %r101, align 4
  br label %bb1

bb1:                                              ; preds = %bb2, %checkrange
  %r102 = load i32, ptr %r101, align 4
  %r103 = load i32, ptr @max, align 4
  %r104 = icmp sgt i32 %r102, %r103
  br i1 %r104, label %bb2, label %bb3

bb2:                                              ; preds = %bb1
  %r105 = load i32, ptr %r101, align 4
  %r106 = load i32, ptr @max, align 4
  %r107 = sub i32 %r105, %r106
  store i32 %r107, ptr %r101, align 4
  br label %bb1

bb3:                                              ; preds = %bb1
  br label %bb4

bb4:                                              ; preds = %bb5, %bb3
  %r108 = load i32, ptr %r101, align 4
  %r109 = icmp slt i32 %r108, 0
  br i1 %r109, label %bb5, label %bb6

bb5:                                              ; preds = %bb4
  %r110 = load i32, ptr %r101, align 4
  %r111 = load i32, ptr @max, align 4
  %r112 = add i32 %r110, %r111
  store i32 %r112, ptr %r101, align 4
  br label %bb4

bb6:                                              ; preds = %bb4
  %r113 = load i32, ptr %r101, align 4
  ret i32 %r113
}

define i32 @mod(i32 %r114, i32 %r116) {
mod:
  %r115 = alloca i32, align 4
  store i32 %r114, ptr %r115, align 4
  %r117 = alloca i32, align 4
  store i32 %r116, ptr %r117, align 4
  %r118 = load i32, ptr %r115, align 4
  %r119 = load i32, ptr %r115, align 4
  %r120 = load i32, ptr %r117, align 4
  %r121 = sdiv i32 %r119, %r120
  %r122 = load i32, ptr %r117, align 4
  %r123 = mul i32 %r121, %r122
  %r124 = sub i32 %r118, %r123
  ret i32 %r124
}

define i32 @reduce(i32 %r125, i32 %r127, i32 %r129) {
reduce:
  %r196 = alloca i32, align 4
  %r195 = alloca i32, align 4
  %r171 = alloca i32, align 4
  %r170 = alloca i32, align 4
  %r140 = alloca i32, align 4
  %r139 = alloca i32, align 4
  %r126 = alloca i32, align 4
  store i32 %r125, ptr %r126, align 4
  %r128 = alloca i32, align 4
  store i32 %r127, ptr %r128, align 4
  %r130 = alloca i32, align 4
  store i32 %r129, ptr %r130, align 4
  %r131 = load i32, ptr %r126, align 4
  %r132 = icmp eq i32 %r131, 0
  br i1 %r132, label %bb7, label %bb8

bb7:                                              ; preds = %reduce
  %r133 = load i32, ptr %r128, align 4
  %r134 = load i32, ptr %r130, align 4
  %r135 = add i32 %r133, %r134
  %r136 = call i32 @checkrange(i32 %r135)
  ret i32 %r136

bb87:                                             ; No predecessors!
  br label %bb9

bb8:                                              ; preds = %reduce
  br label %bb9

bb9:                                              ; preds = %bb8, %bb87
  %r137 = load i32, ptr %r126, align 4
  %r138 = icmp eq i32 %r137, 1
  br i1 %r138, label %bb10, label %bb11

bb10:                                             ; preds = %bb9
  store i32 0, ptr %r139, align 4
  store i32 1, ptr %r140, align 4
  br label %bb12

bb12:                                             ; preds = %bb17, %bb10
  %r141 = load i32, ptr %r140, align 4
  %r142 = load i32, ptr @max, align 4
  %r143 = icmp slt i32 %r141, %r142
  br i1 %r143, label %bb13, label %bb14

bb13:                                             ; preds = %bb12
  %r144 = load i32, ptr %r128, align 4
  %r145 = load i32, ptr %r140, align 4
  %r146 = sdiv i32 %r144, %r145
  %r147 = call i32 @mod(i32 %r146, i32 2)
  %r148 = load i32, ptr %r130, align 4
  %r149 = load i32, ptr %r140, align 4
  %r150 = sdiv i32 %r148, %r149
  %r151 = call i32 @mod(i32 %r150, i32 2)
  %r152 = icmp eq i32 %r147, %r151
  br i1 %r152, label %bb15, label %bb16

bb15:                                             ; preds = %bb13
  %r153 = load i32, ptr %r139, align 4
  %r154 = mul i32 %r153, 2
  store i32 %r154, ptr %r139, align 4
  br label %bb17

bb16:                                             ; preds = %bb13
  %r155 = load i32, ptr %r139, align 4
  %r156 = mul i32 %r155, 2
  %r157 = add i32 %r156, 1
  store i32 %r157, ptr %r139, align 4
  br label %bb17

bb17:                                             ; preds = %bb16, %bb15
  %r158 = load i32, ptr %r140, align 4
  %r159 = mul i32 %r158, 2
  store i32 %r159, ptr %r140, align 4
  br label %bb12

bb14:                                             ; preds = %bb12
  %r160 = load i32, ptr %r139, align 4
  ret i32 %r160

bb88:                                             ; No predecessors!
  br label %bb18

bb11:                                             ; preds = %bb9
  br label %bb18

bb18:                                             ; preds = %bb11, %bb88
  %r161 = load i32, ptr %r126, align 4
  %r162 = icmp eq i32 %r161, 2
  br i1 %r162, label %bb19, label %bb20

bb19:                                             ; preds = %bb18
  %r163 = load i32, ptr %r128, align 4
  %r164 = load i32, ptr %r130, align 4
  %r165 = icmp sgt i32 %r163, %r164
  br i1 %r165, label %bb21, label %bb22

bb21:                                             ; preds = %bb19
  %r166 = load i32, ptr %r128, align 4
  ret i32 %r166

bb89:                                             ; No predecessors!
  br label %bb23

bb22:                                             ; preds = %bb19
  %r167 = load i32, ptr %r130, align 4
  ret i32 %r167

bb23:                                             ; preds = %bb89
  br label %bb24

bb20:                                             ; preds = %bb18
  br label %bb24

bb24:                                             ; preds = %bb20, %bb23
  %r168 = load i32, ptr %r126, align 4
  %r169 = icmp eq i32 %r168, 3
  br i1 %r169, label %bb25, label %bb26

bb25:                                             ; preds = %bb24
  store i32 0, ptr %r170, align 4
  store i32 1, ptr %r171, align 4
  br label %bb27

bb27:                                             ; preds = %bb33, %bb25
  %r172 = load i32, ptr %r171, align 4
  %r173 = load i32, ptr @max, align 4
  %r174 = icmp slt i32 %r172, %r173
  br i1 %r174, label %bb28, label %bb29

bb28:                                             ; preds = %bb27
  %r175 = load i32, ptr %r128, align 4
  %r176 = load i32, ptr %r171, align 4
  %r177 = sdiv i32 %r175, %r176
  %r178 = call i32 @mod(i32 %r177, i32 2)
  %r179 = icmp eq i32 %r178, 1
  br i1 %r179, label %bb30, label %bb32

bb32:                                             ; preds = %bb28
  %r180 = load i32, ptr %r130, align 4
  %r181 = load i32, ptr %r171, align 4
  %r182 = sdiv i32 %r180, %r181
  %r183 = call i32 @mod(i32 %r182, i32 2)
  %r184 = icmp eq i32 %r183, 1
  br i1 %r184, label %bb30, label %bb31

bb30:                                             ; preds = %bb32, %bb28
  %r185 = load i32, ptr %r170, align 4
  %r186 = mul i32 %r185, 2
  %r187 = add i32 %r186, 1
  store i32 %r187, ptr %r170, align 4
  br label %bb33

bb31:                                             ; preds = %bb32
  %r188 = load i32, ptr %r170, align 4
  %r189 = mul i32 %r188, 2
  store i32 %r189, ptr %r170, align 4
  br label %bb33

bb33:                                             ; preds = %bb31, %bb30
  %r190 = load i32, ptr %r171, align 4
  %r191 = mul i32 %r190, 2
  store i32 %r191, ptr %r171, align 4
  br label %bb27

bb29:                                             ; preds = %bb27
  %r192 = load i32, ptr %r170, align 4
  ret i32 %r192

bb90:                                             ; No predecessors!
  br label %bb34

bb26:                                             ; preds = %bb24
  br label %bb34

bb34:                                             ; preds = %bb26, %bb90
  %r193 = load i32, ptr %r126, align 4
  %r194 = icmp eq i32 %r193, 4
  br i1 %r194, label %bb35, label %bb36

bb35:                                             ; preds = %bb34
  store i32 0, ptr %r195, align 4
  store i32 1, ptr %r196, align 4
  br label %bb37

bb37:                                             ; preds = %bb43, %bb35
  %r197 = load i32, ptr %r196, align 4
  %r198 = load i32, ptr @max, align 4
  %r199 = icmp slt i32 %r197, %r198
  br i1 %r199, label %bb38, label %bb39

bb38:                                             ; preds = %bb37
  %r200 = load i32, ptr %r128, align 4
  %r201 = load i32, ptr %r196, align 4
  %r202 = sdiv i32 %r200, %r201
  %r203 = call i32 @mod(i32 %r202, i32 2)
  %r204 = icmp eq i32 %r203, 1
  br i1 %r204, label %bb42, label %bb41

bb42:                                             ; preds = %bb38
  %r205 = load i32, ptr %r130, align 4
  %r206 = load i32, ptr %r196, align 4
  %r207 = sdiv i32 %r205, %r206
  %r208 = call i32 @mod(i32 %r207, i32 2)
  %r209 = icmp eq i32 %r208, 1
  br i1 %r209, label %bb40, label %bb41

bb40:                                             ; preds = %bb42
  %r210 = load i32, ptr %r195, align 4
  %r211 = mul i32 %r210, 2
  %r212 = add i32 %r211, 1
  store i32 %r212, ptr %r195, align 4
  br label %bb43

bb41:                                             ; preds = %bb42, %bb38
  %r213 = load i32, ptr %r195, align 4
  %r214 = mul i32 %r213, 2
  store i32 %r214, ptr %r195, align 4
  br label %bb43

bb43:                                             ; preds = %bb41, %bb40
  %r215 = load i32, ptr %r196, align 4
  %r216 = mul i32 %r215, 2
  store i32 %r216, ptr %r196, align 4
  br label %bb37

bb39:                                             ; preds = %bb37
  %r217 = load i32, ptr %r195, align 4
  ret i32 %r217

bb91:                                             ; No predecessors!
  br label %bb44

bb36:                                             ; preds = %bb34
  br label %bb44

bb44:                                             ; preds = %bb36, %bb91
  ret i32 0
}

define i32 @getvalue(ptr %r218, i32 %r219, i32 %r221, i32 %r223, i32 %r225) {
getvalue:
  %r237 = alloca i32, align 4
  %r220 = alloca i32, align 4
  store i32 %r219, ptr %r220, align 4
  %r222 = alloca i32, align 4
  store i32 %r221, ptr %r222, align 4
  %r224 = alloca i32, align 4
  store i32 %r223, ptr %r224, align 4
  %r226 = alloca i32, align 4
  store i32 %r225, ptr %r226, align 4
  %r227 = load i32, ptr %r224, align 4
  %r228 = icmp slt i32 %r227, 0
  br i1 %r228, label %bb45, label %bb47

bb47:                                             ; preds = %getvalue
  %r229 = load i32, ptr %r226, align 4
  %r230 = icmp slt i32 %r229, 0
  br i1 %r230, label %bb45, label %bb48

bb48:                                             ; preds = %bb47
  %r231 = load i32, ptr %r224, align 4
  %r232 = load i32, ptr %r220, align 4
  %r233 = icmp sge i32 %r231, %r232
  br i1 %r233, label %bb45, label %bb49

bb49:                                             ; preds = %bb48
  %r234 = load i32, ptr %r226, align 4
  %r235 = load i32, ptr %r222, align 4
  %r236 = icmp sge i32 %r234, %r235
  br i1 %r236, label %bb45, label %bb46

bb45:                                             ; preds = %bb49, %bb48, %bb47, %getvalue
  ret i32 0

bb92:                                             ; No predecessors!
  br label %bb50

bb46:                                             ; preds = %bb49
  br label %bb50

bb50:                                             ; preds = %bb46, %bb92
  %r238 = load i32, ptr %r224, align 4
  %r239 = load i32, ptr %r222, align 4
  %r240 = mul i32 %r238, %r239
  %r241 = load i32, ptr %r226, align 4
  %r242 = add i32 %r240, %r241
  store i32 %r242, ptr %r237, align 4
  %r243 = load i32, ptr %r237, align 4
  %r244 = getelementptr i32, ptr %r218, i32 %r243
  %r245 = load i32, ptr %r244, align 4
  ret i32 %r245
}

define i32 @convn(i32 %r246, ptr %r248, ptr %r249, i32 %r250, i32 %r252, i32 %r254) {
convn:
  %r306 = alloca i32, align 4
  %r247 = alloca i32, align 4
  store i32 %r246, ptr %r247, align 4
  %r251 = alloca i32, align 4
  store i32 %r250, ptr %r251, align 4
  %r253 = alloca i32, align 4
  store i32 %r252, ptr %r253, align 4
  %r255 = alloca i32, align 4
  store i32 %r254, ptr %r255, align 4
  %r256 = alloca i32, align 4
  store i32 0, ptr %r256, align 4
  %r257 = alloca i32, align 4
  store i32 0, ptr %r257, align 4
  %r258 = alloca i32, align 4
  %r259 = alloca i32, align 4
  %r260 = alloca i32, align 4
  %r261 = alloca i32, align 4
  store i32 1, ptr %r261, align 4
  br label %bb51

bb51:                                             ; preds = %bb74, %convn
  %r262 = load i32, ptr %r261, align 4
  %r263 = load i32, ptr %r261, align 4
  %r264 = icmp eq i32 %r262, %r263
  br i1 %r264, label %bb52, label %bb53

bb52:                                             ; preds = %bb51
  store i32 0, ptr %r257, align 4
  br label %bb54

bb54:                                             ; preds = %bb71, %bb52
  %r265 = load i32, ptr %r261, align 4
  %r266 = load i32, ptr %r261, align 4
  %r267 = icmp eq i32 %r265, %r266
  br i1 %r267, label %bb55, label %bb56

bb55:                                             ; preds = %bb54
  store i32 0, ptr %r260, align 4
  %r268 = load i32, ptr %r256, align 4
  %r269 = load i32, ptr %r255, align 4
  %r270 = sdiv i32 %r269, 2
  %r271 = sub i32 %r268, %r270
  store i32 %r271, ptr %r258, align 4
  br label %bb57

bb57:                                             ; preds = %bb68, %bb55
  %r272 = load i32, ptr %r261, align 4
  %r273 = load i32, ptr %r261, align 4
  %r274 = icmp eq i32 %r272, %r273
  br i1 %r274, label %bb58, label %bb59

bb58:                                             ; preds = %bb57
  %r275 = load i32, ptr %r257, align 4
  %r276 = load i32, ptr %r255, align 4
  %r277 = sdiv i32 %r276, 2
  %r278 = sub i32 %r275, %r277
  store i32 %r278, ptr %r259, align 4
  br label %bb60

bb60:                                             ; preds = %bb65, %bb58
  %r279 = load i32, ptr %r261, align 4
  %r280 = load i32, ptr %r261, align 4
  %r281 = icmp eq i32 %r279, %r280
  br i1 %r281, label %bb61, label %bb62

bb61:                                             ; preds = %bb60
  %r282 = load i32, ptr %r247, align 4
  %r283 = load i32, ptr %r260, align 4
  %r284 = load i32, ptr %r251, align 4
  %r285 = load i32, ptr %r253, align 4
  %r286 = load i32, ptr %r258, align 4
  %r287 = load i32, ptr %r259, align 4
  %r288 = call i32 @getvalue(ptr %r248, i32 %r284, i32 %r285, i32 %r286, i32 %r287)
  %r289 = call i32 @reduce(i32 %r282, i32 %r283, i32 %r288)
  store i32 %r289, ptr %r260, align 4
  %r290 = load i32, ptr %r259, align 4
  %r291 = add i32 %r290, 1
  store i32 %r291, ptr %r259, align 4
  %r292 = load i32, ptr %r259, align 4
  %r293 = load i32, ptr %r257, align 4
  %r294 = load i32, ptr %r255, align 4
  %r295 = sdiv i32 %r294, 2
  %r296 = add i32 %r293, %r295
  %r297 = icmp sge i32 %r292, %r296
  br i1 %r297, label %bb63, label %bb64

bb63:                                             ; preds = %bb61
  br label %bb62

bb93:                                             ; No predecessors!
  br label %bb65

bb64:                                             ; preds = %bb61
  br label %bb65

bb65:                                             ; preds = %bb64, %bb93
  br label %bb60

bb62:                                             ; preds = %bb63, %bb60
  %r298 = load i32, ptr %r258, align 4
  %r299 = add i32 %r298, 1
  store i32 %r299, ptr %r258, align 4
  %r300 = load i32, ptr %r258, align 4
  %r301 = load i32, ptr %r256, align 4
  %r302 = load i32, ptr %r255, align 4
  %r303 = sdiv i32 %r302, 2
  %r304 = add i32 %r301, %r303
  %r305 = icmp sge i32 %r300, %r304
  br i1 %r305, label %bb66, label %bb67

bb66:                                             ; preds = %bb62
  br label %bb59

bb94:                                             ; No predecessors!
  br label %bb68

bb67:                                             ; preds = %bb62
  br label %bb68

bb68:                                             ; preds = %bb67, %bb94
  br label %bb57

bb59:                                             ; preds = %bb66, %bb57
  %r307 = load i32, ptr %r256, align 4
  %r308 = load i32, ptr %r253, align 4
  %r309 = mul i32 %r307, %r308
  %r310 = load i32, ptr %r257, align 4
  %r311 = add i32 %r309, %r310
  store i32 %r311, ptr %r306, align 4
  %r312 = load i32, ptr %r306, align 4
  %r313 = getelementptr i32, ptr %r249, i32 %r312
  %r314 = load i32, ptr %r260, align 4
  store i32 %r314, ptr %r313, align 4
  %r315 = load i32, ptr %r257, align 4
  %r316 = add i32 %r315, 1
  store i32 %r316, ptr %r257, align 4
  %r317 = load i32, ptr %r257, align 4
  %r318 = load i32, ptr %r253, align 4
  %r319 = icmp sge i32 %r317, %r318
  br i1 %r319, label %bb69, label %bb70

bb69:                                             ; preds = %bb59
  br label %bb56

bb95:                                             ; No predecessors!
  br label %bb71

bb70:                                             ; preds = %bb59
  br label %bb71

bb71:                                             ; preds = %bb70, %bb95
  br label %bb54

bb56:                                             ; preds = %bb69, %bb54
  %r320 = load i32, ptr %r256, align 4
  %r321 = add i32 %r320, 1
  store i32 %r321, ptr %r256, align 4
  %r322 = load i32, ptr %r256, align 4
  %r323 = load i32, ptr %r251, align 4
  %r324 = icmp sge i32 %r322, %r323
  br i1 %r324, label %bb72, label %bb73

bb72:                                             ; preds = %bb56
  br label %bb53

bb96:                                             ; No predecessors!
  br label %bb74

bb73:                                             ; preds = %bb56
  br label %bb74

bb74:                                             ; preds = %bb73, %bb96
  br label %bb51

bb53:                                             ; preds = %bb72, %bb51
  ret i32 0
}

define void @memmove(ptr %r325, ptr %r326, i32 %r327) {
memmove:
  %r328 = alloca i32, align 4
  store i32 %r327, ptr %r328, align 4
  %r329 = alloca i32, align 4
  store i32 0, ptr %r329, align 4
  br label %bb75

bb75:                                             ; preds = %bb76, %memmove
  %r330 = load i32, ptr %r329, align 4
  %r331 = load i32, ptr %r328, align 4
  %r332 = icmp slt i32 %r330, %r331
  br i1 %r332, label %bb76, label %bb77

bb76:                                             ; preds = %bb75
  %r333 = load i32, ptr %r329, align 4
  %r334 = getelementptr i32, ptr %r325, i32 %r333
  %r335 = load i32, ptr %r329, align 4
  %r336 = getelementptr i32, ptr %r326, i32 %r335
  %r337 = load i32, ptr %r336, align 4
  store i32 %r337, ptr %r334, align 4
  %r338 = load i32, ptr %r329, align 4
  %r339 = add i32 %r338, 1
  store i32 %r339, ptr %r329, align 4
  br label %bb75

bb77:                                             ; preds = %bb75
  ret void
}

define i32 @main() {
main:
  %r368 = alloca i32, align 4
  %r366 = alloca i32, align 4
  %r341 = call i32 @getint()
  %r340 = alloca i32, align 4
  store i32 %r341, ptr %r340, align 4
  %r343 = call i32 @getint()
  %r342 = alloca i32, align 4
  store i32 %r343, ptr %r342, align 4
  %r345 = call i32 @getint()
  %r344 = alloca i32, align 4
  store i32 %r345, ptr %r344, align 4
  %r346 = alloca i32, align 4
  %r347 = call i32 @getint()
  store i32 %r347, ptr %r346, align 4
  %r348 = alloca i32, align 4
  store i32 0, ptr %r348, align 4
  br label %bb78

bb78:                                             ; preds = %bb79, %main
  %r349 = load i32, ptr %r348, align 4
  %r350 = load i32, ptr %r346, align 4
  %r351 = icmp slt i32 %r349, %r350
  br i1 %r351, label %bb79, label %bb80

bb79:                                             ; preds = %bb78
  %r352 = load i32, ptr %r348, align 4
  %r353 = getelementptr [10000000 x i32], ptr @a, i32 0, i32 %r352
  %r354 = call i32 @getint()
  store i32 %r354, ptr %r353, align 4
  %r355 = load i32, ptr %r348, align 4
  %r356 = add i32 %r355, 1
  store i32 %r356, ptr %r348, align 4
  br label %bb78

bb80:                                             ; preds = %bb78
  %r357 = call i32 @getint()
  store i32 %r357, ptr %r346, align 4
  store i32 0, ptr %r348, align 4
  br label %bb81

bb81:                                             ; preds = %bb82, %bb80
  %r358 = load i32, ptr %r348, align 4
  %r359 = load i32, ptr %r346, align 4
  %r360 = icmp slt i32 %r358, %r359
  br i1 %r360, label %bb82, label %bb83

bb82:                                             ; preds = %bb81
  %r361 = load i32, ptr %r348, align 4
  %r362 = getelementptr [10000 x i32], ptr @kernelid_, i32 0, i32 %r361
  %r363 = call i32 @getint()
  store i32 %r363, ptr %r362, align 4
  %r364 = load i32, ptr %r348, align 4
  %r365 = add i32 %r364, 1
  store i32 %r365, ptr %r348, align 4
  br label %bb81

bb83:                                             ; preds = %bb81
  %r367 = load i32, ptr %r346, align 4
  store i32 %r367, ptr %r366, align 4
  call void @_sysy_starttime(i32 209)
  store i32 0, ptr %r368, align 4
  br label %bb84

bb84:                                             ; preds = %bb85, %bb83
  %r369 = load i32, ptr %r368, align 4
  %r370 = load i32, ptr %r366, align 4
  %r371 = icmp slt i32 %r369, %r370
  br i1 %r371, label %bb85, label %bb86

bb85:                                             ; preds = %bb84
  %r372 = load i32, ptr %r368, align 4
  %r373 = getelementptr [10000 x i32], ptr @kernelid_, i32 0, i32 %r372
  %r374 = load i32, ptr %r373, align 4
  %r375 = load i32, ptr %r342, align 4
  %r376 = load i32, ptr %r344, align 4
  %r377 = load i32, ptr %r340, align 4
  %r378 = call i32 @convn(i32 %r374, ptr @a, ptr @b, i32 %r375, i32 %r376, i32 %r377)
  %r379 = load i32, ptr %r342, align 4
  %r380 = load i32, ptr %r344, align 4
  %r381 = mul i32 %r379, %r380
  call void @memmove(ptr @a, ptr @b, i32 %r381)
  %r382 = load i32, ptr %r368, align 4
  %r383 = add i32 %r382, 1
  store i32 %r383, ptr %r368, align 4
  br label %bb84

bb86:                                             ; preds = %bb84
  call void @_sysy_stoptime(i32 312)
  %r384 = load i32, ptr %r342, align 4
  %r385 = load i32, ptr %r344, align 4
  %r386 = mul i32 %r384, %r385
  call void @putarray(i32 %r386, ptr @a)
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
