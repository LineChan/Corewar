.name		"Torpille"
.comment	"by sebc"

l_0:
	xor		r4, r4, r4
	fork	%:l_1
	st		r1, 6
	live	%0
	fork	%:l_2
	st		r1, 20
	ld		%-10, r2
	ld		%1, r3

l_4:
	live	%4
	add		r2, r3, r2
	zjmp	%:l_3
	xor		r4, r4, r4
	zjmp	%:l_4

l_3:
	fork	%:l_2
	ld		%-10, r2
	xor		r4, r4, r4
	zjmp	%:l_4

l_1:
	st		r1, 6
	live	%0
	fork	%:l_5
	st		r1, 20
	ld		%-10, r2
	ld		%1, r3

l_7:
	live	%4
	add		r2, r3, r2
	zjmp	%:l_6
	xor		r4, r4, r4
	zjmp	%:l_7

l_6:
	fork	%:l_5
	ld		%-10, r2
	xor		r4, r4, r4
	zjmp	%:l_7

l_5:
	ld		%57672192, r3
	ld		%655616, r2
	xor		r4, r4, r4
	zjmp	%:l_8

l_2:
	ld		%917760, r2
	ld		%134443011, r3
	xor		r4, r4, r4
	zjmp	%:l_9

l_9:
	st		r2, 8

l_8:
	st		r3, 10
	live	%0

; generated ;