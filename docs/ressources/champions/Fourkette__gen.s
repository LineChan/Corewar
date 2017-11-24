.name		"3lit3 f0rK4"
.comment	"no comment"

l_0:
	sti		r1, %:l_1, %1
	sti		r1, %:l_2, %1
	sti		r1, %:l_3, %1
	sti		r1, %:l_4, %1
	sti		r1, %:l_5, %1

l_1:
	live	%1
	and		%0, %0, r2
	fork	%:l_1
	fork	%:l_2
	zjmp	%:l_1

l_2:
	live	%1
	fork	%:l_2
	fork	%:l_3
	zjmp	%:l_2

l_3:
	live	%1
	fork	%:l_3
	fork	%:l_4
	zjmp	%:l_3

l_4:
	live	%1
	fork	%:l_4
	fork	%:l_5
	zjmp	%:l_4

l_5:
	live	%1
	fork	%:l_5
	fork	%:l_1
	zjmp	%:l_5

; generated ;