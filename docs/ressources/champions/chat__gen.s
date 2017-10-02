.name		"CHAT PERCHE"
.comment	"groupe : dartoi_o, devaux_l, joyaud_c, huline_t"

l_0:
	sti		r1, %:l_4, %1

l_3:
	xor		r2, r2, r2
	zjmp	%:l_1
	sti		r1, %:l_2, %1
	xor		r1, r1, r1

l_2:
	live	%1
	zjmp	%:l_2

l_1:
	ldi		%-20, %:l_1, r11
	ldi		%-27, %4, r12
	ldi		%-34, %8, r13
	ldi		%-41, %12, r14
	ldi		%-48, %16, r15
	ld		%67895264, r8
	ld		%27, r3
	ld		%100, r4
	ld		%1, r5

l_6:
	ld		%10, r6
	sti		r11, 0, r4
	sti		r12, -1, r4
	sti		r13, -2, r4
	sti		r14, -4, r4
	sti		r15, -8, r4
	fork	%:l_3

l_5:
	st		r2, -50
	st		r2, -60
	st		r2, 68
	sub		r5, r6, r6
	zjmp	%:l_4
	xor		r2, r2, r2
	zjmp	%:l_5

l_4:
	live	%1
	add		r3, r4, r4
	add		r4, r8, r7
	st		r7, -54
	xor		r2, r2, r2
	zjmp	%:l_6

; generated ;