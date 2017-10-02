.name		"Eddy"
.comment	"Le virus mort vivant"

l_0:
	st		r1, r4
	sti		r4, %:l_2, %1

l_2:
	live	%1
	fork	%:l_1
	ld		%:l_0, r2
	ld		%0, r9
	zjmp	%:l_2

l_3:
	sti		r4, %:l_4, %1
	live	%1
	fork	%:l_1
	zjmp	%:l_3
	sti		r4, %0, %1
	live	%:l_2
	st		r4, r1
	ld		%0, r5
	zjmp	%:l_0

l_1:
	st		r1, r4
	sti		r4, %-41, %1

l_4:
	live	%:l_0
	fork	%:l_0
	ld		%:l_0, r2
	zjmp	%:l_4

l_5:
	sti		r4, %7, %1
	live	%1
	zjmp	%:l_5
	sti		r4, %7, %1
	live	%-15
	st		r4, r1
	ld		%0, r5
	zjmp	%:l_1

; generated ;