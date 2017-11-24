.name		"Evil-Sister"
.comment	"Com`on and play with me!"

l_0:
	sti		r1, %162, %1
	sti		r1, %171, %1
	sti		r1, %10, %1
	fork	%:l_1
	live	%1
	fork	%:l_2
	fork	%:l_3
	ld		%0, r4
	ld		%-489, r3
	ldi		%105, %0, r2
	xor		r16, r16, r16
	zjmp	%:l_4

l_3:
	ld		%4, r4
	ld		%-489, r3
	ldi		%:l_4, %1, r2
	xor		r16, r16, r16
	zjmp	%:l_4

l_2:
	fork	%:l_5
	ld		%8, r4
	ld		%-489, r3
	ldi		%52, %0, r2
	xor		r16, r16, r16
	zjmp	%:l_4

l_5:
	ld		%12, r4
	ld		%-489, r3
	ldi		%23, %4, r2
	xor		r16, r16, r16
	zjmp	%:l_4
	zjmp	%0

l_4:
	sti		r2, r3, r4
	live	%1
	zjmp	%-496
	zjmp	%0

l_8:
	sti		r2, r3, r4
	live	%1
	zjmp	%476

l_1:
	live	%1
	fork	%:l_6
	fork	%:l_7
	ld		%0, r4
	ld		%483, r3
	ldi		%-41, %0, r2
	xor		r16, r16, r16
	zjmp	%:l_8

l_7:
	ld		%4, r4
	ld		%483, r3
	ldi		%:l_8, %1, r2
	xor		r16, r16, r16
	zjmp	%:l_8

l_6:
	fork	%:l_9
	ld		%8, r4
	ld		%483, r3
	ldi		%-94, %0, r2
	xor		r16, r16, r16
	zjmp	%:l_8

l_9:
	ld		%12, r4
	ld		%483, r3
	ldi		%-123, %4, r2
	xor		r16, r16, r16
	zjmp	%:l_8

; generated ;