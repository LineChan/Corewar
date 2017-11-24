.name		"rex-chien mechant"
.comment	"la vitesse du levrier"

l_0:
	ld		%:l_0, r2

l_5:
	zjmp	%:l_1
	zjmp	%0
	live	%6
	sti		r15, %0, r14
	zjmp	%-200
	live	%6
	sti		r15, %0, r14
	zjmp	%-200
	live	%6
	sti		r15, %0, r14
	zjmp	%-200
	live	%6
	sti		r15, %0, r14
	zjmp	%-200
	sti		r15, %0, r14

l_2:
	zjmp	%:l_2
	sti		r15, %0, r14
	zjmp	%-200

l_1:
	st		r1, -73
	st		r1, -55
	st		r1, -46
	st		r1, -37
	st		r1, -28
	fork	%:l_1
	live	%6
	fork	%:l_1
	live	%6
	ld		%393216, r4
	ld		%917504, r12
	ld		%1, r10
	sti		r4, %:l_5, %1
	fork	%:l_3
	fork	%:l_4
	ldi		%8, %-149, r15
	ld		%-186, r14
	ld		%0, r2
	zjmp	%:l_5

l_3:
	fork	%:l_6
	ldi		%4, %-176, r15
	ld		%-190, r14
	ld		%0, r2
	zjmp	%:l_5

l_4:
	ldi		%12, %-200, r15
	ld		%-182, r14
	ld		%0, r2
	zjmp	%:l_5

l_6:
	ldi		%:l_6, %-224, r15
	ld		%-194, r14
	ld		%0, r2
	zjmp	%:l_5
	zjmp	%0

; generated ;