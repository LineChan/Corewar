.name		"The_Cloqueur"
.comment	"live and fork"

l_0:
	sti		r1, %:l_1, %1
	and		r1, %0, r1
	zjmp	%:l_1

l_1:
	live	%1
	ld		10, r2
	ld		%:l_2, r3
	ld		%:l_4, r4
	ld		%:l_5, r5
	ld		%:l_6, r6
	fork	%:l_2
	live	%1
	zjmp	%:l_1

l_2:
	live	%1
	add		r2, r3, r3
	sti		r3, %:l_3, r3
	fork	%:l_3
	zjmp	%:l_2

l_4:
	live	%1
	add		r2, r4, r4
	sti		r4, %:l_3, r4
	fork	%:l_4
	zjmp	%:l_4

l_5:
	live	%1
	add		r2, r5, r5
	sti		r5, %:l_3, r5
	fork	%:l_3
	zjmp	%:l_5

l_6:
	live	%1
	add		r2, r6, r6
	sti		r6, %:l_3, r6
	fork	%:l_6
	zjmp	%:l_6

l_3:
	live	%1
	zjmp	%:l_1

; generated ;