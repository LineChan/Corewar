.name		"Ebola 0.1.0"
.comment	"librement interprete by Nef"

l_0:
	ld		%:l_0, r3

l_6:
	zjmp	%:l_1
	zjmp	%0
	live	%42
	sti		r15, %0, r14
	zjmp	%-200
	live	%42
	sti		r15, %0, r14
	zjmp	%-200
	live	%42
	sti		r15, %0, r14
	zjmp	%-200
	live	%42
	sti		r15, %0, r14
	zjmp	%-200
	sti		r15, %0, r14
	zjmp	%-200
	sti		r15, %0, r14
	zjmp	%-200

l_1:
	sti		r1, %-74, %1
	sti		r1, %-81, %15
	sti		r1, %-88, %29
	sti		r1, %-95, %43
	sti		r1, %-102, %57
	sti		r1, %-109, %71

l_2:
	ld		%393216, r4
	ld		%917504, r12
	ld		%1, r11
	ld		%6, r10

l_3:
	live	%42
	sti		r4, %:l_6, %1
	add		r4, r12, r4
	sub		r10, r11, r10
	zjmp	%:l_2
	fork	%:l_3
	live	%3
	fork	%:l_4
	live	%4
	fork	%:l_5
	live	%42
	ldi		%8, %-193, r15
	ld		%-186, r14
	ld		%0, r2
	zjmp	%:l_6

l_4:
	live	%42
	fork	%:l_7
	live	%42
	ldi		%4, %-230, r15
	ld		%-190, r14
	ld		%0, r2
	zjmp	%:l_6

l_5:
	live	%42
	ldi		%12, %-259, r15
	ld		%-182, r14
	ld		%0, r2
	zjmp	%:l_6

l_7:
	live	%42
	ldi		%0, %-288, r15
	ld		%-194, r14
	ld		%0, r2
	zjmp	%:l_6

; generated ;