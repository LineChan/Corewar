.name		"Team43"
.comment	"le numero 2"

l_0:
	ld		10, r2
	live	%1
	fork	%:l_1
	fork	%:l_2
	fork	%:l_3
	fork	%:l_1
	lfork	%:l_4
	live	%1
	zjmp	%:l_0

l_5:
	live	%1
	sti		r1, %:l_6, %200
	live	%1
	zjmp	%:l_5

l_1:
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	zjmp	%:l_1

l_2:
	live	%1
	st		r1, -100
	live	%1
	st		r1, -120
	live	%1
	st		r1, -140
	live	%1
	st		r1, -160
	live	%1
	st		r1, -180
	live	%1
	st		r1, -200
	live	%1
	st		r1, -220
	live	%1
	st		r1, -240
	live	%1
	st		r1, -260
	live	%1
	and		r6, %0, r8
	zjmp	%:l_2

l_3:
	live	%1
	live	%1

l_4:
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	zjmp	%:l_3

l_6:
	live	%1
	zjmp	%:l_1
	zjmp	%:l_6
	live	%1
	zjmp	%:l_0
	live	%1
	and		r4, %0, r5
	zjmp	%:l_6

; generated ;