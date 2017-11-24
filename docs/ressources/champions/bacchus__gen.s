.name		"Bacchus"
.comment	"Come and drink some"

l_0:
	sti		r1, %155, %1
	sti		r1, %:l_6, %1
	fork	%:l_1

l_6:
	live	%1
	fork	%:l_2
	fork	%:l_3
	ld		%0, r4
	ld		%-447, r3
	ldi		%105, %0, r2
	xor		r16, r16, r16
	zjmp	%:l_4

l_3:
	ld		%4, r4
	ld		%-447, r3
	ldi		%:l_4, %1, r2
	xor		r16, r16, r16
	zjmp	%:l_4

l_2:
	fork	%:l_5
	ld		%8, r4
	ld		%-447, r3
	ldi		%52, %0, r2
	xor		r16, r16, r16
	zjmp	%:l_4

l_5:
	ld		%12, r4
	ld		%-447, r3
	ldi		%23, %4, r2
	xor		r16, r16, r16
	zjmp	%:l_4
	zjmp	%0

l_4:
	sti		r2, r3, r4
	live	%1
	zjmp	%-454

l_1:
	fork	%:l_6
	live	%1
	xor		r16, r16, r16
	zjmp	%:l_1

; generated ;