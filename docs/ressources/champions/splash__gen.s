.name		":-)"
.comment	":-<"

l_0:
	sti		r1, %:l_3, %6
	ld		%-471, r3
	st		r1, 6
	live	%0
	fork	%:l_1
	fork	%:l_2
	ld		%0, r4
	ldi		%80, r4, r2
	xor		r16, r16, r16
	zjmp	%:l_3

l_1:
	fork	%:l_4
	ld		%4, r4
	ldi		%56, r4, r2
	xor		r16, r16, r16
	zjmp	%:l_3

l_2:
	ld		%8, r4
	ldi		%35, r4, r2
	xor		r16, r16, r16
	zjmp	%:l_3

l_4:
	ld		%12, r4
	ldi		%14, r4, r2
	xor		r16, r16, r16
	zjmp	%:l_3
	zjmp	%0

l_3:
	sti		r2, r3, r4
	live	%0
	zjmp	%:l_2

; generated ;