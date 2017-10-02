.name		"Nak"
.comment	"OdaK VishnoU"

l_0:
	lfork	%:l_1
	st		r1, 13
	ld		%4, r3

l_5:
	live	%1
	ld		%-77, r2
	ldi		%:l_4, r2, r4
	sti		r4, %49, r2
	add		r2, r3, r2
	fork	%:l_2
	live	%1
	fork	%:l_3
	zjmp	%-50
	live	%1
	xor		r4, r4, r4
	zjmp	%:l_4

l_2:
	ld		%368, r2
	ld		%0, r3
	ld		%4, r4

l_4:
	live	%1
	fork	%0
	zjmp	%:l_4
	live	%1
	fork	%:l_5
	zjmp	%:l_2
	fork	%:l_4

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
	live	%1
	fork	%:l_1
	zjmp	%-162

l_3:
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	zjmp	%:l_3

; generated ;