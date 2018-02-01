.name		"Wrong Char Label Short"
.comment	"Wrong char label short"

l_0,:
	sti		r1, %140, %1
	fork	%:l_1
	fork	%:l_2
	ld		%0, r4
	ld		%-471, r3
	ldi		%105, %0, r2
	xor		r16, r16, r16
	zjmp	%:l_3

l_2:
	ld		%4, r4
	ld		%-471, r3
	ldi		%:l_3, %1, r2
	xor		r16, r16, r16
	zjmp	%:l_3

l_1:
	fork	%:l_4
	ld		%8, r4
	ld		%-471, r3
	ldi		%52, %0, r2
	xor		r16, r16, r16
	zjmp	%:l_3

l_4:
	ld		%12, r4
	ld		%-471, r3
	ldi		%23, %4, r2
	xor		r16, r16, r16
	zjmp	%:l_3
	zjmp	%0

l_3:
	sti		r2, r3, r4
	live	%1
	zjmp	%-479

; generated ;
