.name		"Dwarf2 0.0.1"
.comment	"dev by Nef"

l_0:
	fork	%:l_1
	ld		%1, r3
	ld		%286331153, r4
	and		%0, %0, r14
	zjmp	%:l_2
	zjmp	%0

l_3:
	sti		r4, %:l_0, r2
	sti		r4, %:l_0, r5
	add		r2, r3, r2
	sub		r5, r3, r5
	live	%1
	and		r14, %0, r14
	zjmp	%:l_3

l_2:
	sti		r1, %-16, %1
	sti		r1, %7, %1
	live	%1
	and		r14, %0, r14
	zjmp	%:l_3
	zjmp	%0

l_1:
	sti		r1, %:l_6, %1
	sti		r1, %:l_5, %1
	ld		%4, r4
	ld		%:l_0, r13

l_7:
	ld		%:l_7, r2
	ld		%108, r6
	add		r6, r13, r6

l_6:
	live	%1
	ldi		%:l_1, r2, r3
	sti		r3, r13, r2
	add		r2, r4, r2
	sub		r6, r2, r7
	zjmp	%:l_4
	fork	%:l_5
	ld		%0, r14
	zjmp	%:l_6

l_5:
	live	%2
	and		r1, %0, r1
	zjmp	%:l_5

l_4:
	fork	%:l_0
	and		r1, %0, r1
	zjmp	%:l_7

; generated ;