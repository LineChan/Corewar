.name		"DeathAngel 2"
.comment	"by Fireangel (glacha_g)"

l_0:
	st		r1, 6
	live	%1
	fork	%:l_1
	live	%1
	sti		r1, %:l_3, %1
	sti		r1, %:l_2, %1
	xor		r15, r15, r15

l_2:
	live	%1
	zjmp	%:l_2

l_3:
	live	%1
	fork	%:l_3
	zjmp	%:l_3

l_1:
	ld		%:l_1, r5
	ld		%64, r6
	ld		%8, r7
	ld		%11, r8
	ld		%4, r9
	ld		%2900, r10
	ld		%33883649, r11
	ld		%150995712, r12
	ld		%139726350, r13
	ld		%235471040, r14
	sti		r10, %:l_8, %200
	sti		r11, %:l_8, %204
	sti		r1, %:l_8, %208
	sti		r12, %:l_8, %212
	sti		r13, %:l_8, %3
	sti		r14, %:l_8, %7
	st		r1, 6

l_5:
	live	%1
	fork	%:l_4
	zjmp	%:l_5

l_4:
	st		r1, 6
	live	%1
	fork	%:l_6
	ld		%190055173, r2
	ld		%84413268, r3
	st		r1, r4
	xor		r15, r15, r15
	zjmp	%:l_7

l_6:
	ld		%118182916, r2
	ld		%33883649, r3
	ld		%151008768, r4
	xor		r15, r15, r15
	add		r5, r9, r5
	add		r15, r15, r15

l_7:
	xor		r15, r15, r15
	st		r1, 6

l_9:
	live	%1
	xor		r15, r1, r15
	fork	%:l_8
	xor		r15, r15, r15

l_8:
	zjmp	%:l_9

; generated ;