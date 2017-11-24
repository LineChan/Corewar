.name		"YoYo"
.comment	"Speedy one to destroy everything"

l_0:
	st		r1, 241
	st		r1, 114
	st		r1, 117
	st		r1, 127
	st		r1, 147
	st		r1, 59
	ld		%215, r2
	ld		%-200, r10
	ld		%1, r9
	ld		%16, r12
	and		r6, %0, r6
	fork	%:l_1
	ld		%1, r8
	ld		%0, r6

l_1:
	live	%59
	fork	%:l_2
	zjmp	%:l_1

l_8:
	ldi		r12, r3, r11
	and		r6, %0, r6
	zjmp	%:l_3
	zjmp	%0

l_3:
	sti		r11, r10, r3
	live	%59
	zjmp	%-208

l_2:
	live	%59
	fork	%:l_4
	ld		%4, r3
	live	%59
	fork	%:l_5
	ld		%0, r3
	zjmp	%:l_6

l_4:
	ld		%8, r3
	live	%59
	fork	%:l_5
	ld		%12, r3
	ld		%0, r6
	zjmp	%:l_7

l_5:
	ld		%:l_5, r6
	zjmp	%:l_6

l_6:
	ld		%:l_6, r6

l_7:
	and		r8, r9, r8
	zjmp	%:l_8
	ldi		r12, r3, r7
	and		r6, %0, r6
	zjmp	%:l_9
	zjmp	%0

l_9:
	sti		r7, r2, r3
	live	%59
	zjmp	%208

; generated ;