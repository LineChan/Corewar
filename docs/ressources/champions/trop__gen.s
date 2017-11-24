.name		"Torpille anti crabe"
.comment	""

l_0:
	st		r1, 40
	st		r1, 27
	ld		%100, r2
	and		r1, %0, r15
	fork	%:l_1
	zjmp	%:l_2

l_1:
	live	%42
	zjmp	%:l_1

l_2:
	add		r3, r2, r3
	sti		r1, %:l_0, r3
	zjmp	%:l_2

; generated ;