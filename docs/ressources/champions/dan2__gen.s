.name		"The Cruel"
.comment	"Dan"

l_0:
	sti		r1, %:l_1, %1
	sti		r1, %:l_2, %1
	sti		r1, %:l_3, %1
	sti		r1, %:l_4, %1
	sti		r1, %:l_5, %1
	sti		r1, %:l_6, %1
	sti		r1, %:l_7, %1
	sti		r1, %:l_8, %1
	sti		r1, %:l_9, %1
	sti		r1, %:l_10, %1
	sti		r1, %:l_11, %1
	xor		r16, r16, r16

l_1:
	live	%:l_1
	fork	%:l_1
	zjmp	%:l_2

l_2:
	live	%:l_2
	fork	%:l_2
	zjmp	%:l_3

l_3:
	live	%:l_3
	fork	%:l_3
	zjmp	%:l_4

l_4:
	live	%:l_4
	fork	%:l_4
	zjmp	%:l_5

l_5:
	live	%:l_5
	fork	%:l_5
	zjmp	%:l_6

l_6:
	live	%:l_6
	fork	%:l_6
	zjmp	%:l_7

l_7:
	live	%:l_7
	fork	%:l_7
	zjmp	%:l_8

l_8:
	live	%:l_8
	fork	%:l_8
	zjmp	%:l_9

l_9:
	live	%:l_9
	fork	%:l_9
	zjmp	%:l_10

l_10:
	live	%:l_10
	fork	%:l_10
	zjmp	%:l_11

l_11:
	live	%:l_11
	fork	%:l_11
	zjmp	%:l_1

; generated ;