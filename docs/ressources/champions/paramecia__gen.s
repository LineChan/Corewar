.name		"paramecia"
.comment	""

l_0:
	sti		r1, %312, %1
	ld		%1, r14
	ld		%-200, r11
	ld		%200, r12
	live	%42
	fork	%:l_1
	live	%42
	fork	%:l_2
	ldi		%:l_3, %0, r1
	ldi		%:l_3, %4, r2
	ldi		%:l_3, %8, r3
	ldi		%:l_3, %12, r4
	ld		%-28, r6
	ld		%-29, r7
	ld		%-30, r8
	ld		%-31, r9
	sub		r15, r15, r15
	zjmp	%:l_3

l_1:
	live	%42
	fork	%:l_4
	ldi		%:l_3, %16, r1
	ldi		%:l_3, %20, r2
	ldi		%:l_3, %24, r3
	ldi		%:l_3, %28, r4
	ld		%-12, r6
	ld		%-13, r7
	ld		%-14, r8
	ld		%-15, r9
	sub		r15, r15, r15
	zjmp	%:l_3

l_2:
	ldi		%:l_3, %32, r1
	ldi		%:l_3, %36, r2
	ldi		%:l_3, %40, r3
	ldi		%:l_3, %44, r4
	ld		%4, r6
	ld		%3, r7
	ld		%2, r8
	ld		%1, r9
	sub		r15, r15, r15
	zjmp	%:l_3

l_4:
	ldi		%:l_3, %48, r1
	ldi		%:l_3, %52, r2
	ldi		%:l_3, %56, r3
	ldi		%:l_3, %60, r4
	ld		%20, r6
	ld		%19, r7
	ld		%18, r8
	ld		%17, r9
	sub		r15, r15, r15
	zjmp	%:l_3

l_3:
	st		r14, r10
	live	%42
	fork	%:l_5
	st		r11, r5
	sub		r10, r10, r10
	zjmp	%:l_6

l_5:
	st		r12, r5

l_6:
	sti		r1, r5, r6
	sti		r2, r5, r7
	sti		r3, r5, r8
	sti		r4, r5, r9
	or		r10, r10, r10
	zjmp	%147
	sub		r5, r5, r5
	zjmp	%:l_1

; generated ;