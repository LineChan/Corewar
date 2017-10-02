.name		"Isabelle"
.comment	""

l_0:
	live	%6969
	fork	%:l_1
	fork	%:l_2
	live	%6969
	ld		%190056714, r9

l_3:
	ld		%200, r11
	ld		%0, r10

l_4:
	sti		r9, r10, r11
	zjmp	%:l_3

l_2:
	live	%6969
	ld		%185139395, r9
	ld		%204, r11
	ld		%0, r10
	zjmp	%:l_4

l_1:
	fork	%:l_5
	live	%6969
	fork	%:l_6
	live	%6969
	ld		%190056714, r9
	ld		%470, r11
	ld		%0, r10

l_8:
	sti		r9, r10, r11
	zjmp	%:l_7

l_6:
	live	%6969
	ld		%185139655, r9
	ld		%474, r11
	ld		%0, r10
	zjmp	%:l_8

l_5:
	live	%6969

l_7:
	fork	%:l_0
	live	%6969
	fork	%:l_1
	st		r1, 13
	ld		%0, r10

l_9:
	live	%6969
	st		r1, 16
	st		r1, 16
	st		r1, 16
	live	%6969
	live	%6969
	live	%6969
	zjmp	%:l_9

; generated ;