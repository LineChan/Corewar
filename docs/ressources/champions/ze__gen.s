.name		"Ze test a la con"
.comment	""

l_0:
	ld		%:l_0, r2
	zjmp	%:l_1

l_5:
	st		r1, 36
	st		r1, 39
	st		r1, 392
	zjmp	%:l_2

l_1:
	fork	%:l_3
	fork	%:l_4
	live	%42
	fork	%:l_5
	fork	%:l_2

l_6:
	live	%42
	zjmp	%:l_6

l_2:
	live	%42
	fork	%:l_7
	fork	%:l_2
	live	%42
	fork	%:l_3

l_4:
	live	%42
	fork	%:l_8
	ld		44, r3
	ld		%-145, r2
	ld		%0, r1
	zjmp	%:l_9

l_8:
	ld		26, r3
	ld		%-141, r2
	ld		%0, r1
	zjmp	%:l_9

l_9:
	sti		r3, r2, r1
	zjmp	%-150

l_7:
	live	%42

l_24:
	ld		%200, r4
	ld		%2, r11
	ld		%4, r12
	ld		%8, r13
	ld		%16, r14
	ld		%32, r15
	ld		%64, r16
	ld		%0, r3
	fork	%:l_10
	ld		%0, r5
	zjmp	%:l_11

l_10:
	add		r3, r11, r3
	add		r3, r11, r3
	ld		%0, r5

l_11:
	live	%42
	fork	%:l_12
	ld		%0, r5
	zjmp	%:l_13

l_12:
	add		r3, r12, r3
	add		r3, r12, r3
	ld		%0, r5

l_13:
	live	%42
	fork	%:l_14
	ld		%0, r5
	zjmp	%:l_15

l_14:
	add		r3, r13, r3
	add		r3, r13, r3
	ld		%0, r5

l_15:
	live	%42
	fork	%:l_16
	ld		%0, r5
	zjmp	%:l_17

l_16:
	add		r3, r14, r3
	add		r3, r14, r3
	ld		%0, r5

l_17:
	live	%42
	fork	%:l_18
	ld		%0, r5
	zjmp	%:l_19

l_18:
	add		r3, r15, r3
	add		r3, r15, r3
	ld		%0, r5

l_19:
	live	%42
	fork	%:l_20
	ld		%0, r5
	zjmp	%:l_21

l_20:
	add		r3, r16, r3
	add		r3, r16, r3
	ld		%0, r5

l_21:
	ldi		13, r3, r2
	ld		%0, r5
	live	%42
	sti		r2, r3, r4
	zjmp	%:l_7

l_3:
	live	%42
	fork	%:l_22
	ld		44, r3
	ld		%145, r2
	ld		%0, r1
	zjmp	%:l_23

l_22:
	ld		26, r3
	ld		%:l_9, r2
	ld		%0, r1
	zjmp	%:l_23

l_23:
	sti		r3, r2, r1
	zjmp	%:l_24

; generated ;