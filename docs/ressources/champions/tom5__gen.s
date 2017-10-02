.name		"fulguro-point !"
.comment	""

l_0:
	st		r1, 191
	st		r1, 224
	st		r1, -10
	ld		%466, r6
	live	%42
	fork	%:l_1
	ld		160, r1
	ld		159, r2
	ld		158, r3
	ld		157, r4
	ld		156, r5
	ld		155, r12
	ld		%-8, r7
	ld		%-9, r8
	ld		%-10, r9
	ld		%-11, r10
	ld		%-12, r11
	ld		%-13, r13
	sub		r15, r15, r15
	zjmp	%:l_2

l_1:
	ld		104, r1
	ld		103, r2
	ld		102, r3
	ld		101, r4
	ld		100, r5
	ld		99, r12
	ld		%16, r7
	ld		%15, r8
	ld		%14, r9
	ld		%13, r10
	ld		%12, r11
	ld		%11, r13
	sub		r15, r15, r15
	zjmp	%:l_2

l_3:
	live	%42
	zjmp	%:l_3

l_2:
	sti		r1, r6, r7
	sti		r2, r6, r8
	sti		r3, r6, r9
	sti		r4, r6, r10
	sti		r5, r6, r11
	sti		r12, r6, r13
	live	%42
	zjmp	%431

; generated ;