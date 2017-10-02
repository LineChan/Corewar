.name		"Imp 0.0.1"
.comment	"dev by Nef"

l_0:
	sti		r1, %:l_3, %1
	sti		r1, %:l_2, %1
	ld		%4, r4

l_4:
	ld		%:l_4, r2
	ld		%108, r6

l_3:
	live	%1
	ldi		%:l_0, r2, r3
	sti		r3, %:l_0, r2
	add		r2, r4, r2
	sub		r6, r2, r7
	zjmp	%:l_1
	fork	%:l_2
	ld		%0, r14
	zjmp	%:l_3

l_2:
	live	%2
	and		r1, %0, r1
	zjmp	%:l_2

l_1:
	fork	%:l_0
	and		r1, %0, r1
	zjmp	%:l_4

; generated ;