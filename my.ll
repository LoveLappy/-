define i32 @main() {
entry:
  %v_a_0 = alloca i32, align 4
  store i32 10, i32* %v_a_0, align 4
  %v_b_1 = alloca i32, align 4
  store i32 5, i32* %v_b_1, align 4
  %v_c_2 = alloca i32, align 4
  store i32 2, i32* %v_c_2, align 4
  %t1 = load i32, i32* %v_a_0, align 4
  %t2 = load i32, i32* %v_b_1, align 4
  %t3 = icmp sgt i32 %t1, %t2
  br i1 %t3, label %if.then.1, label %if.else.2
if.then.1:
  %t4 = load i32, i32* %v_a_0, align 4
  %t5 = load i32, i32* %v_b_1, align 4
  %t6 = mul i32 2, %t5
  %t7 = add i32 %t4, %t6
  store i32 %t7, i32* %v_c_2, align 4
  br label %if.end.3
if.else.2:
  %t8 = load i32, i32* %v_b_1, align 4
  store i32 %t8, i32* %v_c_2, align 4
  br label %if.end.3
if.end.3:
  br label %while.cond.4
while.cond.4:
  %t9 = load i32, i32* %v_a_0, align 4
  %t10 = icmp sgt i32 %t9, 0
  br i1 %t10, label %while.body.5, label %while.end.6
while.body.5:
  store i32 10, i32* %v_a_0, align 4
  br label %while.cond.4
while.end.6:
  %t11 = load i32, i32* %v_a_0, align 4
  ret i32 %t11
}
