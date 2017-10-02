.name		"Canan"
.comment	"You will die soon 42"

l_0:
	fork	%:l_1
	zjmp	%:l_2
	fork	%:l_3
	fork	%:l_4
	fork	%:l_1

l_1:
	sti		r1, %:l_3, %1
	ld		%504, r10
	ld		%1, r5
	ld		%0, r11

l_3:
	live	%1
	add		r4, r5, r4
	add		r3, r4, r3
	sub		r2, r4, r2
	ld		%0, r11
	zjmp	%:l_3

l_4:
	live	%42
	fork	%:l_5
	zjmp	%:l_4

l_5:
	ld		%-8, r5
	ld		%12, r4

l_2:
	live	%42
	fork	%:l_6
	live	%42
	fork	%:l_2
	live	%42
	zjmp	%:l_2

l_6:
	live	%42
	sti		r1, %23, %1
	and		r1, %0, r1
	and		r1, %0, r1
	live	%1
	live	%1
	live	%1
	live	%1

; generated ;