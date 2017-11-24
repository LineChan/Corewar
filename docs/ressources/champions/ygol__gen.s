.name		"!"
.comment	"?"

l_0:
	xor		r16, r16, r16
	zjmp	%:l_1

l_6:
	sti		r2, %-350, r15
	sti		r3, %-348, r15
	sti		r4, %-346, r15
	sti		r5, %-344, r15
	live	%0
	zjmp	%-379

l_1:
	sti		r1, %:l_3, %1
	sti		r1, %90, %1
	sti		r1, %:l_5, %1
	sti		r1, %:l_4, %1
	sti		r1, %-36, %1
	sti		r1, %:l_7, %1
	sti		r1, %175, %1
	sti		r1, %:l_8, %1
	sti		r1, %:l_2, %1
	sti		r1, %274, %1
	fork	%:l_2

l_4:
	live	%:l_4
	fork	%:l_3
	xor		r16, r16, r16
	zjmp	%:l_4

l_3:
	live	%:l_3
	fork	%:l_5
	live	%0
	ld		%0, r15
	ldi		%:l_6, %0, r2
	ldi		%:l_6, %8, r3
	ldi		%:l_6, %16, r4
	ldi		%:l_6, %24, r5
	xor		r16, r16, r16
	zjmp	%:l_6

l_5:
	live	%:l_5
	ld		%4, r15
	ldi		%:l_6, %4, r2
	ldi		%:l_6, %12, r3
	ldi		%:l_6, %20, r4
	ldi		%:l_6, %28, r5
	xor		r16, r16, r16
	zjmp	%:l_6

l_2:
	live	%:l_2
	fork	%:l_7
	xor		r16, r16, r16
	zjmp	%:l_2

l_7:
	live	%:l_7
	fork	%:l_8
	live	%0
	ld		%0, r15
	ldi		%:l_9, %0, r2
	ldi		%:l_9, %8, r3
	ldi		%:l_9, %16, r4
	ldi		%:l_9, %24, r5
	xor		r16, r16, r16
	zjmp	%:l_9

l_8:
	live	%:l_8
	ld		%4, r15
	ldi		%:l_9, %4, r2
	ldi		%:l_9, %12, r3
	ldi		%:l_9, %20, r4
	ldi		%:l_9, %28, r5
	xor		r16, r16, r16
	zjmp	%:l_9

l_9:
	sti		r2, %350, r15
	sti		r3, %352, r15
	sti		r4, %354, r15
	sti		r5, %356, r15
	live	%0
	zjmp	%321

; generated ;