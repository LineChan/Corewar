.name		"rush lurker"
.comment	"by ttt"

l_0:
	fork	%:l_0
	st		r1, 32
	st		r1, 66
	ld		%100, r4
	ld		%4, r6
	ld		%0, r3
	live	%1

l_1:
	ldi		%:l_0, r3, r2
	sti		r2, %394, r3
	add		r3, r6, r3
	sti		r1, %135, r3
	sti		r1, %-159, r3
	sub		r3, r4, r5
	live	%1
	zjmp	%319
	ld		%0, r5
	zjmp	%:l_1

; generated ;