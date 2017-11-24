.name		"Guyver"
.comment	"No Comment!"

l_0:
	st		r1, 73
	st		r6, -4
	ld		63, r1
	ld		%0, r7
	zjmp	%:l_1

l_3:
	live	%66
	ldi		%:l_3, r3, r1
	sti		r1, %-173, r3
	add		r3, r4, r3
	xor		r5, r3, r6
	zjmp	%:l_2
	ld		%0, r7
	zjmp	%:l_3

l_2:
	xor		r3, r3, r3
	zjmp	%-207
	st		r1, r1

l_1:
	sti		r1, %7, %1
	live	%66
	sti		r2, %-74, %-60
	ld		%4, r4
	st		r2, 512
	ld		%48, r5
	sti		r1, %:l_3, %1
	sti		r1, %:l_6, %1
	sti		r1, %:l_4, %1
	sti		r1, %40, %1
	sti		r1, %38, %1
	sti		r1, %36, %1
	sti		r1, %34, %1
	sti		r1, %32, %1

l_4:
	live	%66
	live	%66
	live	%66
	live	%:l_5
	live	%66
	live	%66
	zjmp	%:l_4
	xor		r3, r3, r3
	sti		r1, %7, %1
	live	%66
	fork	%:l_4
	sti		r1, %:l_5, %1
	sti		r1, %:l_5, %9
	sti		r1, %:l_5, %17
	sti		r1, %:l_5, %25

l_5:
	live	%66
	fork	%:l_3
	live	%66
	fork	%:l_5
	live	%66
	fork	%:l_6
	live	%66
	zjmp	%:l_3

l_6:
	live	%66
	ldi		%:l_6, r3, r1
	sti		r1, %147, r3
	add		r3, r4, r3
	xor		r5, r3, r6
	zjmp	%:l_7
	ld		%0, r7
	zjmp	%:l_6

l_7:
	xor		r3, r3, r3
	zjmp	%113

; generated ;