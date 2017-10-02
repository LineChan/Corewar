.name		"demis3"
.comment	"demis3"

l_0:
	sti		r1, %22, %1
	sti		r1, %:l_1, %1
	and		r1, %0, r1
	live	%2
	live	%2
	live	%2
	live	%2
	live	%2
	live	%2
	live	%2
	live	%2
	fork	%:l_1
	sti		r1, %:l_1, %1
	ldi		%-50, r2, r3
	sti		r3, r8, r2
	add		r2, r4, r2
	xor		r13, r2, r7
	live	%2
	live	%2
	live	%2
	live	%2
	ldi		%-91, r2, r3
	sti		r3, r8, r2
	ldi		%-102, r2, r3
	add		r2, r4, r2
	xor		r13, r2, r7
	ld		%0, r15
	sti		r1, %-125, %1
	zjmp	%:l_1
	ld		%0, r6

l_1:
	sti		r3, r8, r2
	add		r2, r4, r2
	ldi		%-152, r2, r3
	live	%2
	live	%2
	live	%2
	live	%2
	live	%2
	live	%2
	ldi		%-188, r2, r3
	sti		r1, %-194, %1
	live	%2
	live	%2
	live	%2
	live	%2
	sti		r1, %-221, %1
	and		r1, %0, r1
	sti		r1, %-236, %1
	zjmp	%:l_1

; generated ;