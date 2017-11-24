.name		"The Cruel"
.comment	"Dan"

l_0:
	live	%:l_0
	fork	%:l_0
	ld		%1000, r0
	st		r0, 1000
	zjmp	%:l_1

l_1:
	live	%:l_1
	fork	%:l_1
	ld		%1000, r0
	st		r0, 1000
	zjmp	%:l_2

l_2:
	live	%:l_2
	fork	%:l_2
	ld		%1000, r0
	st		r0, 1000
	zjmp	%:l_3

l_3:
	live	%:l_3
	fork	%:l_3
	ld		%1000, r0
	st		r0, 1000
	zjmp	%:l_4

l_4:
	live	%:l_4
	fork	%:l_4
	ld		%1000, r0
	st		r0, 1000
	zjmp	%:l_5

l_5:
	live	%:l_5
	fork	%:l_5
	ld		%1000, r0
	st		r0, 1000
	zjmp	%:l_6

l_6:
	live	%:l_6
	fork	%:l_6
	ld		%1000, r0
	st		r0, 1000
	zjmp	%:l_7

l_7:
	live	%:l_7
	fork	%:l_7
	ld		%1000, r0
	st		r0, 1000
	zjmp	%:l_8

l_8:
	live	%:l_8
	fork	%:l_8
	ld		%1000, r0
	st		r0, 1000
	zjmp	%:l_9

l_9:
	live	%:l_9
	fork	%:l_9
	ld		%1000, r0
	st		r0, 1000
	zjmp	%:l_10

l_10:
	live	%:l_10
	fork	%:l_10
	ld		%1000, r0
	st		r0, 1000
	zjmp	%:l_0

; generated ;