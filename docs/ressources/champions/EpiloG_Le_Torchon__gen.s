.name		"EpiloG Le Torchon"
.comment	"un vrai torchon"

l_0:
	fork	%:l_1

l_1:
	ld		%100, r10
	ld		%4, r4
	ld		%0, r2
	sti		r1, %:l_3, %1

l_3:
	live	%1
	ldi		r2, %:l_1, r15
	sti		r15, %:l_0, r2
	add		r2, r4, r2
	sub		r10, r4, r10
	zjmp	%:l_2
	xor		r12, r12, r12
	zjmp	%:l_3

l_2:
	fork	%:l_0
	xor		r12, r12, r12
	zjmp	%:l_1

; generated ;