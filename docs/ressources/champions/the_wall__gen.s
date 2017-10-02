.name		"THE WALL"
.comment	"FLOWER"

l_0:
	sti		r1, %:l_2, %1
	sti		r1, %:l_4, %1
	sti		r1, %:l_3, %1
	xor		r1, r1, r1

l_2:
	live	%1
	fork	%:l_1
	zjmp	%:l_2

l_1:
	ld		%11, r2
	fork	%:l_3
	live	%1
	ldi		%:l_4, %0, r1
	ld		%0, r3
	ldi		%:l_4, %8, r4
	ld		%3, r5
	xor		r16, r16, r16
	zjmp	%:l_4

l_3:
	live	%1
	ldi		%:l_4, %4, r1
	ld		%4, r3
	ldi		%:l_4, %12, r4
	ld		%7, r5
	xor		r16, r16, r16
	zjmp	%:l_4

l_4:
	live	%1
	sti		r1, r2, r3
	sti		r4, r2, r5

; generated ;