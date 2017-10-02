.name		"la moissoneuse prot"
.comment	"batteuse"

l_0:
	sti		r1, %:l_3, %1
	sti		r1, %:l_5, %1
	sti		r1, %:l_4, %1
	sti		r1, %:l_2, %1
	xor		r1, r1, r1

l_3:
	live	%1
	fork	%:l_1
	live	%1
	fork	%:l_2
	zjmp	%:l_3

l_2:
	live	%1
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	st		r2, -490
	zjmp	%:l_2

l_1:
	ld		%10, r2
	fork	%:l_4
	live	%1
	ldi		%:l_5, %0, r1
	ld		%0, r3
	ldi		%:l_5, %8, r4
	ld		%3, r5
	xor		r16, r16, r16
	zjmp	%:l_5

l_4:
	live	%1
	ldi		%:l_5, %4, r1
	ld		%4, r3
	ldi		%:l_5, %12, r4
	ld		%7, r5
	xor		r16, r16, r16
	zjmp	%:l_5

l_5:
	live	%1
	sti		r1, r2, r3
	sti		r4, r2, r5

; generated ;