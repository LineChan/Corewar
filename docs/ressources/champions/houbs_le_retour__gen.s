.name		"houbs ' warrior est de retour"
.comment	"hehehe"

l_0:
	ld		%56, r2
	ld		%4, r16

l_2:
	fork	%:l_1
	st		r1, 6
	live	%1
	zjmp	%:l_2

l_6:
	sti		r1, %39, %1
	ld		%0, r3

l_3:
	ldi		r3, %:l_6, r4
	sti		r4, %-384, r3
	add		r3, r16, r3
	sub		r3, r2, r15
	zjmp	%-400
	live	%1
	and		r1, %0, r10
	zjmp	%:l_3

l_5:
	sti		r1, %39, %1
	ld		%0, r3

l_4:
	ldi		r3, %:l_5, r4
	sti		r4, %316, r3
	add		r3, r16, r3
	sub		r3, r2, r15
	zjmp	%300
	live	%1
	and		r1, %0, r10
	zjmp	%:l_4

l_1:
	live	%:l_1
	fork	%:l_5
	live	%0
	fork	%:l_6
	st		r1, 6
	live	%1
	and		r1, %0, r10
	zjmp	%:l_1

; generated ;