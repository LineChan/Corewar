.name		"GASTRO"
.comment	"I m Too Young To die"

l_0:
	sti		r1, %29, %1
	sti		r1, %:l_1, %1
	sti		r1, %:l_2, %1
	and		r1, %0, r1
	live	%1
	fork	%:l_1

l_1:
	live	%1
	fork	%:l_2
	ld		%0, r1
	fork	%:l_3
	ld		%0, r2
	sti		r1, 250, %1
	zjmp	%:l_1

l_2:
	live	%2
	ld		%0, r2
	zjmp	%:l_2

l_3:
	live	%2
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	st		r2, -400
	ld		%0, r1
	zjmp	%:l_3

; generated ;