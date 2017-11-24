.name		"rex-chien mechant"
.comment	"la vitesse du levrier"

l_0:
	xor		r2, r2, r2

l_4:
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
	zjmp	%-400
	sti		r15, %0, r14
	zjmp	%-200

l_1:
	st		r1, -73
	st		r1, -55
	st		r1, -46
	st		r1, -37
	st		r1, -28
	ld		%393216, r4
	ld		%917504, r12
	ld		%1, r10
	sti		r4, %:l_4, %1
	fork	%:l_2
	fork	%:l_3
	ldi		%8, %-133, r15
	ld		%-186, r14
	ld		%0, r2
	zjmp	%:l_4

l_2:
	fork	%:l_5
	ldi		%4, %-160, r15
	ld		%-190, r14
	ld		%0, r2
	zjmp	%:l_4

l_3:
	ldi		%12, %-184, r15
	ld		%-182, r14
	ld		%0, r2
	zjmp	%:l_4

l_5:
	ldi		%:l_5, %-208, r15
	ld		%-194, r14
	ld		%0, r2
	zjmp	%:l_4
	zjmp	%0

; generated ;