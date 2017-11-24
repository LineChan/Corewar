.name		"speedfreak"
.comment	""

l_0:
	st		r1, r10
	xor		r1, r1, r1

l_2:
	sti		r10, %7, %1
	live	%1
	fork	%:l_1
	zjmp	%:l_2

l_1:
	ld		%400, r2
	fork	%:l_3
	ldi		%:l_4, %0, r1
	ld		%0, r3
	ldi		%:l_4, %8, r4
	ld		%3, r5
	xor		r16, r16, r16
	zjmp	%:l_4

l_3:
	ldi		%:l_4, %4, r1
	ld		%4, r3
	ldi		%:l_4, %12, r4
	ld		%7, r5
	xor		r16, r16, r16
	zjmp	%:l_4

l_4:
	sti		r10, %7, %1
	live	%1
	sti		r1, r2, r3
	sti		r4, r2, r5
	zjmp	%390

; generated ;