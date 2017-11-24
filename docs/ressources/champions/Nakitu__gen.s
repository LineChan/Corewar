.name		"Nak2"
.comment	"OdaK VishnoU Return"

l_0:
	lfork	%:l_1
	st		r1, 116
	ld		%4, r3
	live	%1
	ld		%-116, r2
	ldi		%:l_4, r2, r4
	sti		r4, %88, r2
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
	live	%1
	fork	%:l_5
	zjmp	%:l_6

l_5:
	ld		%1879179266, r2
	zjmp	%:l_6

l_6:
	xor		r0, r0, r0

l_7:
	st		r2, 1
	live	%1
	zjmp	%:l_7

l_4:
	live	%1
	fork	%0
	zjmp	%:l_4
	live	%1
	fork	%:l_7
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
	zjmp	%-98

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