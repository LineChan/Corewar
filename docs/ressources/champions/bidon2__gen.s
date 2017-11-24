.name		"bidon2"
.comment	"rosell_o,soulad_c,ranvie_s,hamel_r le nom est a la hauteur de nos esperances"

l_0:
	xor		r2, r2, r2
	ld		%10, r4
	ld		%1, r8
	ld		%1000, r9
	ld		%4, r11
	ld		%980, r12
	ld		%20, r13
	st		r1, r2
	st		r2, 44
	st		r2, 43
	st		r2, 42
	st		r2, 41
	st		r2, 40

l_2:
	fork	%:l_1
	sub		r4, r8, r4

l_3:
	live	%:l_3
	live	%0
	live	%0
	live	%0
	live	%0
	and		r4, r5, r5
	zjmp	%:l_2
	xor		r6, r6, r6
	zjmp	%:l_3

l_1:
	ldi		%:l_1, %:l_3, r3
	ldi		%4, %:l_3, r4
	ldi		%8, %:l_3, r5
	ldi		%12, %:l_3, r6
	ldi		%16, %:l_3, r7

l_4:
	st		r3, r9
	add		r9, r11, r9
	st		r4, r9
	add		r9, r11, r9
	st		r5, r9
	add		r9, r11, r9
	st		r6, r9
	add		r9, r11, r9
	st		r7, r9
	add		r9, r11, r9
	xor		r10, r10, r10
	add		r12, r13, r12
	zjmp	%:l_4

; generated ;