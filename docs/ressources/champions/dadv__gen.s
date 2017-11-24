.name		"DADV, coupe moi les jambes!"
.comment	"parle a mon chien"

l_0:
	fork	%:l_1
	st		r1, 14

l_1:
	fork	%:l_2

l_15:
	st		r1, 27

l_2:
	live	%1
	fork	%:l_3
	st		r1, 40

l_3:
	fork	%:l_4
	st		r1, 187

l_4:
	live	%1
	st		r1, 59
	fork	%:l_5
	st		r1, 35

l_5:
	fork	%:l_6
	st		r1, 6

l_6:
	live	%1
	fork	%:l_7
	st		r1, 30

l_7:
	fork	%:l_8
	st		r1, 22

l_8:
	live	%1
	fork	%:l_9

l_9:
	fork	%:l_10

l_10:
	st		r1, 124
	live	%1
	ld		%485, r7
	fork	%:l_11
	fork	%:l_12
	ld		%0, r8
	ldi		%:l_13, r8, r2
	ld		%0, r9
	zjmp	%:l_13

l_12:
	ld		%8, r8
	ldi		%:l_13, r8, r2
	ld		%0, r9
	zjmp	%:l_13

l_14:
	ld		%12, r8
	ldi		%:l_13, r8, r2
	ld		%0, r9
	zjmp	%:l_13

l_11:
	fork	%:l_14
	ld		%4, r8
	ldi		%:l_13, r8, r2
	ld		%0, r9
	zjmp	%:l_13

l_13:
	sti		r2, r7, r8
	live	%1
	zjmp	%:l_15
	lfork	%0

; generated ;