.name		"Marvin:"
.comment	"'J'ai un mal de tete maintenant.'"

l_0:
	sti		r1, %:l_1, %1
	fork	%:l_1
	fork	%:l_2

l_1:
	live	%1
	ld		%1, r3
	ld		%1000, r4
	sti		r1, %:l_3, %1
	sti		r1, %35, %1
	fork	%:l_3
	zjmp	%:l_1

l_3:
	live	%1
	ld		%1, r2
	ld		%355, r5
	fork	%:l_4
	live	%1
	ld		%-1, r2
	fork	%:l_5
	and		r15, %0, r15
	zjmp	%:l_3

l_4:
	sti		r1, %:l_6, %1
	sti		r4, %:l_4, %0

l_6:
	live	%1
	sti		r4, %:l_2, r2
	add		r2, r3, r2
	sub		r5, r3, r5
	zjmp	%:l_3
	and		r15, %0, r15
	zjmp	%:l_6

l_5:
	sti		r1, %:l_7, %1
	sti		r4, %:l_5, %0

l_7:
	live	%1
	sti		r4, %:l_1, r2
	sub		r2, r3, r2
	sub		r5, r3, r5
	zjmp	%:l_3
	and		r15, %0, r15
	zjmp	%:l_7

l_2:
	sti		r1, %:l_8, %1

l_8:
	live	%1
	and		r15, %0, r15
	fork	%:l_0
	zjmp	%:l_8

; generated ;