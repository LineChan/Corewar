.name		"JE VEUX MOURIR !!"
.comment	"Skyzo 0.1b"

l_0:
	sti		r1, %:l_3, %1
	sti		r1, %:l_1, %1
	sti		r1, %:l_2, %1
	sti		r1, %:l_4, %1

l_3:
	live	%1
	and		%0, %0, r2
	fork	%:l_1
	fork	%:l_2
	zjmp	%:l_3

l_1:
	live	%1
	sti		r1, %-50, %0
	sti		r1, %-59, %0
	sti		r1, %-68, %0
	zjmp	%:l_1

l_2:
	live	%1
	sti		r1, %30, %0
	sti		r1, %29, %0
	sti		r1, %28, %0
	zjmp	%:l_2

l_4:
	live	%1
	zjmp	%:l_4

; generated ;