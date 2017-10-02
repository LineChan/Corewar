.name		"Sky"
.comment	"Ben meet Pol"

l_0:
	live	%:l_0
	st		r1, -400
	st		r1, -400
	st		r1, -400
	st		r1, -400
	st		r1, -400
	st		r1, -400
	zjmp	%:l_0
	fork	%:l_0
	sti		r1, %:l_5, %1
	sti		r1, %37, %1
	sti		r1, %120, %1
	ld		78, r2
	or		r2, r1, r1
	st		r1, 68

l_5:
	live	%1
	fork	%:l_1
	live	%1
	fork	%:l_2
	ld		%190054658, r1
	ld		%12, r3
	xor		r2, r2, r2
	zjmp	%:l_3

l_1:
	fork	%:l_4
	ld		%50397184, r1
	ld		%16, r3
	xor		r2, r2, r2
	zjmp	%:l_3

l_4:
	ld		%:l_4, r1
	ld		%20, r3
	xor		r2, r2, r2
	zjmp	%:l_3

l_2:
	xor		r2, r2, r2
	zjmp	%:l_5

l_3:
	sti		r1, r2, r3
	live	%1

; generated ;