.name		"ch'ti"
.comment	"toupouri"

l_0:
	st		r1, r13

l_2:
	sti		r13, %:l_3, %1
	xor		r1, r1, r1

l_3:
	live	%1
	fork	%:l_1
	live	%1
	ld		%0, r3
	fork	%:l_2
	ld		%0, r3
	zjmp	%:l_3

l_1:
	ld		%200, r2
	fork	%:l_4
	ldi		%:l_5, %0, r1
	ld		%0, r3
	ldi		%:l_5, %8, r4
	ld		%3, r5
	xor		r16, r16, r16
	ld		%0, r3
	fork	%:l_2
	zjmp	%:l_3
	zjmp	%:l_5

l_4:
	ldi		%:l_5, %4, r1
	ld		%4, r3
	ldi		%:l_5, %12, r4
	ld		%7, r5
	ld		%0, r3
	zjmp	%:l_3
	fork	%:l_2
	xor		r16, r16, r16
	zjmp	%:l_5

l_5:
	sti		r1, r2, r3
	sti		r4, r2, r5
	ld		%0, r3
	fork	%:l_2
	zjmp	%190

; generated ;