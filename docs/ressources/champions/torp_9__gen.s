.name		"torpille... V 6.0"
.comment	""

l_0:
	sti		r1, %:l_3, %1
	sti		r1, %:l_5, %1
	sti		r1, %:l_5, %6
	sti		r1, %:l_5, %11
	ld		%300, r2
	fork	%:l_1
	fork	%:l_2
	ldi		%:l_3, %0, r1
	ld		%0, r3
	ldi		%:l_3, %16, r4
	ld		%11, r5
	ldi		%:l_3, %32, r6
	ld		%22, r7
	ldi		%:l_3, %48, r8
	ld		%33, r9
	ldi		%:l_3, %64, r10
	ld		%44, r11
	ldi		%:l_3, %80, r12
	ld		%55, r13
	ldi		%:l_3, %96, r14
	ld		%66, r15
	xor		r16, r16, r16
	zjmp	%:l_3

l_1:
	fork	%:l_4
	ldi		%:l_3, %4, r1
	ld		%4, r3
	ldi		%:l_3, %20, r4
	ld		%15, r5
	ldi		%:l_3, %36, r6
	ld		%26, r7
	ldi		%:l_3, %52, r8
	ld		%37, r9
	ldi		%:l_3, %68, r10
	ld		%48, r11
	ldi		%:l_3, %84, r12
	ld		%59, r13
	ldi		%:l_3, %100, r14
	ld		%70, r15
	xor		r16, r16, r16
	zjmp	%:l_3

l_2:
	ldi		%:l_3, %8, r1
	ld		%8, r3
	ldi		%:l_3, %24, r4
	ld		%19, r5
	ldi		%:l_3, %40, r6
	ld		%30, r7
	ldi		%:l_3, %56, r8
	ld		%41, r9
	ldi		%:l_3, %72, r10
	ld		%52, r11
	ldi		%:l_3, %88, r12
	ld		%63, r13
	ldi		%:l_3, %104, r14
	ld		%74, r15
	xor		r16, r16, r16
	zjmp	%:l_3

l_4:
	ldi		%:l_3, %12, r1
	ld		%12, r3
	ldi		%:l_3, %28, r4
	ld		%23, r5
	ldi		%:l_3, %44, r6
	ld		%34, r7
	ldi		%:l_3, %60, r8
	ld		%45, r9
	ldi		%:l_3, %76, r10
	ld		%56, r11
	ldi		%:l_3, %92, r12
	ld		%67, r13
	ldi		%:l_3, %108, r14
	ld		%78, r15
	xor		r16, r16, r16
	zjmp	%:l_3

l_3:
	live	%42
	sti		r1, r2, r3
	sti		r4, r2, r5
	sti		r6, r2, r7
	sti		r8, r2, r9
	sti		r10, r2, r11
	sti		r12, r2, r13
	sti		r14, r2, r15
	zjmp	%265
	xor		r16, r16, r16

l_5:
	live	%42
	live	%42
	live	%42
	zjmp	%:l_5

; generated ;