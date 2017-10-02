.name		"Alesi : a fond... a fond"
.comment	"groupe : dartoi_o, devaux_l, joyaud_c, huline_t"

l_0:
	sti		r1, %49, %1
	sti		r1, %:l_4, %1
	sti		r1, %64, %1
	ld		%4, r7
	ld		%589824, r10
	ld		%0, r11
	ld		%4, r12
	live	%1
	ld		%0, r2

l_2:
	ldi		%-12, r2, r3
	sti		r3, %:l_3, r3
	add		r2, r7, r2
	live	%1
	xor		r2, %72, r6
	zjmp	%:l_1
	and		r3, %0, r3
	zjmp	%:l_2

l_1:
	and		r3, %:l_1, r3
	fork	%:l_3

l_4:
	live	%1
	sub		r11, r12, r11
	sti		r10, %:l_0, r11
	xor		r13, r13, r13
	zjmp	%:l_4

l_3:
	zjmp	%:l_4

; generated ;