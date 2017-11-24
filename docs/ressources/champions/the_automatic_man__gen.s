.name		"The Automatic Man"
.comment	"Bouge pas ... j arrive"

l_0:
	st		r1, 6
	live	%1
	fork	%:l_1
	fork	%:l_2
	st		r1, 6
	live	%1
	fork	%:l_3
	ld		%16777216, r2
	ld		%5, r3
	ld		%0, r7
	zjmp	%:l_4

l_1:
	fork	%:l_5
	st		r1, 6
	live	%1
	fork	%:l_6
	st		r1, r2
	ld		%6, r3
	ld		%0, r7
	zjmp	%:l_4

l_2:
	st		r1, 6
	live	%1
	fork	%:l_7
	ld		%190054915, r2
	ld		%10, r3
	ld		%0, r7
	zjmp	%:l_4

l_3:
	ld		%67276800, r2
	ld		%14, r3
	ld		%0, r7
	zjmp	%:l_4

l_5:
	st		r1, 6
	live	%1
	fork	%:l_8
	ld		%7, r2
	ld		%18, r3
	ld		%0, r7
	zjmp	%:l_4

l_6:
	ld		%151115818, r2
	ld		%22, r3
	ld		%0, r7
	zjmp	%:l_4

l_7:
	fork	%-210
	ld		%0, r7
	zjmp	%-8

l_8:
	ld		%:l_8, r7
	zjmp	%-5

l_4:
	ld		%7, r4
	sti		r2, r3, r4
	ld		%479, r4

; generated ;