.name		"Vash the Stampede"
.comment	"made by -=SLY=-"

l_0:
	sti		r1, %:l_2, %1
	sti		r1, %:l_6, %6
	sti		r1, %:l_3, %1

l_2:
	live	%1
	fork	%:l_1
	ld		%0, r15
	zjmp	%:l_2

l_3:
	live	%1
	xor		r2, r2, r2
	zjmp	%:l_3

l_1:
	live	%1
	fork	%:l_4
	live	%1
	fork	%:l_5
	ld		%190054658, r1
	ld		%12, r3
	xor		r2, r2, r2
	zjmp	%:l_6

l_5:
	xor		r2, r2, r2
	fork	%:l_3
	zjmp	%:l_1

l_4:
	fork	%:l_7
	ld		%50397184, r1
	ld		%16, r3
	xor		r2, r2, r2
	zjmp	%:l_6

l_7:
	ld		28, r1
	ld		%20, r3
	xor		r2, r2, r2
	zjmp	%:l_6

l_6:
	sti		r1, r2, r3
	live	%1

; generated ;