.name		"FORK ME!"
.comment	"Fork ME"

l_0:
	st		r1, 85
	st		r1, 85
	st		r1, 85
	st		r1, 85
	st		r1, 35
	st		r1, 52

l_2:
	add		r3, r4, r3
	live	%20
	fork	%:l_1
	zjmp	%:l_1
	xor		r5, r5, r5
	zjmp	%:l_2

l_3:
	live	%1
	ld		%40, r3
	ld		%1, r4
	zjmp	%:l_2

l_1:
	live	%1
	zjmp	%:l_3

l_4:
	live	%1
	live	%1
	live	%1
	live	%1
	zjmp	%:l_4

; generated ;