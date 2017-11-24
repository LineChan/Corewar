.name		" Meuh "
.comment	" veau "

l_0:
	fork	%:l_1

l_1:
	live	%1
	fork	%:l_0
	ld		%-3000, r4
	ld		%1, r5

l_2:
	ld		%-3000, r3
	add		r4, r5, r4

l_3:
	st		r1, 6
	live	%1
	add		r3, r5, r3
	zjmp	%:l_2
	sti		r1, r4, r3
	and		r2, %0, r2
	zjmp	%:l_3

; generated ;