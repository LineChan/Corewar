.name		"Nestea"
.comment	"Go..."

l_0:
	st		r1, 29
	st		r1, 32
	st		r1, 6

l_1:
	live	%:l_1
	xor		r6, r6, r6
	fork	%:l_1
	live	%0
	fork	%:l_2
	live	%0
	fork	%:l_3
	ld		%0, r3
	ld		%-301, r4
	ld		%-62636, r2
	xor		r6, r6, r6
	zjmp	%:l_4

l_2:
	fork	%:l_5
	ld		%4, r3
	ld		%-301, r4
	ld		%33752065, r2
	xor		r6, r6, r6
	zjmp	%:l_4

l_3:
	ld		%8, r3
	ld		%-301, r4
	st		r1, r2
	xor		r6, r6, r6
	zjmp	%:l_4

l_5:
	ld		%12, r3
	ld		%-301, r4
	ld		%167693056, r2
	xor		r6, r6, r6
	zjmp	%:l_4

l_4:
	sti		r2, r3, r4
	live	%0
	zjmp	%-309

; generated ;