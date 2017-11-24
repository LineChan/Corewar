.name		"YoYo v0.4"
.comment	"Slower one but enough strong to destroy everything"

l_0:
	st		r1, 289
	st		r1, 162
	st		r1, 165
	st		r1, 175
	st		r1, 195
	st		r1, 82
	ld		%141, r2
	st		r2, r15
	ld		%-153, r10
	st		r10, r16
	ld		%1, r9
	ld		%16, r12
	ld		%13, r13
	and		r6, %0, r6
	fork	%:l_1
	ld		%1, r8

l_1:
	ld		%3, r14
	st		r15, r2
	st		r16, r10

l_3:
	live	%59
	fork	%:l_2
	add		r2, r13, r2
	add		r10, r13, r10
	sub		r14, r9, r14
	zjmp	%:l_1
	ld		%0, r6
	zjmp	%:l_3

l_9:
	ldi		r12, r3, r11
	and		r6, %0, r6
	zjmp	%:l_4
	zjmp	%:l_4

l_4:
	sti		r11, r10, r3
	live	%59
	zjmp	%-160

l_2:
	live	%59
	fork	%:l_5
	ld		%4, r3
	live	%59
	fork	%:l_6
	ld		%0, r3
	zjmp	%:l_7

l_5:
	ld		%8, r3
	live	%59
	fork	%:l_6
	ld		%12, r3
	ld		%0, r6
	zjmp	%:l_8

l_6:
	ld		%:l_6, r6
	zjmp	%:l_7

l_7:
	ld		%:l_7, r6

l_8:
	and		r8, r9, r8
	zjmp	%:l_9
	ldi		r12, r3, r7
	and		r6, %0, r6
	zjmp	%:l_10
	zjmp	%:l_10

l_10:
	sti		r7, r2, r3
	live	%59
	zjmp	%134

; generated ;