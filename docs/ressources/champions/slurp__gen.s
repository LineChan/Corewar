.name		"HeHo"
.comment	"<>"

l_0:
	ld		%461, r3
	sti		r1, %:l_6, %1
	xor		r16, r16, r16

l_3:
	live	%:l_3
	fork	%:l_1
	sti		r1, %:l_2, %1
	live	%0
	st		r1, 6
	live	%0
	fork	%:l_2
	zjmp	%:l_3

l_1:
	fork	%:l_4
	ld		%0, r4
	ldi		%45, r4, r2
	xor		r16, r16, r16
	zjmp	%:l_5

l_4:
	ld		%4, r4
	ldi		%24, r4, r2
	xor		r16, r16, r16
	zjmp	%:l_5

l_5:
	xor		r16, r16, r16
	live	%0
	sti		r2, r3, r4
	zjmp	%:l_1

l_6:
	live	%:l_6
	fork	%:l_6
	xor		r16, r16, r16
	fork	%:l_2
	live	%0
	fork	%:l_3
	zjmp	%:l_6

l_2:
	live	%:l_2
	fork	%:l_2
	xor		r16, r16, r16
	fork	%:l_6
	live	%0
	fork	%:l_3
	zjmp	%:l_2

; generated ;