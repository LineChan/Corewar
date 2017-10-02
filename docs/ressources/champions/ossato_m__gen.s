.name		"Tyrael"
.comment	"The holy light will purify you, Demon"

l_0:
	sti		r1, %:l_2, %1
	sti		r1, %:l_1, %1
	ld		%1, r3
	ld		%16, r2
	ld		%190317826, r5
	fork	%:l_1

l_2:
	live	%1
	ldi		r2, %8, r2
	fork	%-66
	sti		r3, r2, %4
	sti		r1, r2, %2

l_1:
	live	%1
	fork	%:l_2
	zjmp	%:l_3

l_3:
	sti		r3, r2, %:l_3
	sti		r1, r2, %-2
	sti		r5, r2, %0
	zjmp	%:l_3

; generated ;