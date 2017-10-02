.name		"kill krush 'n destroy"
.comment	"tant que vivant moi content"

l_0:
	ld		%12, r2
	ld		%3, r3
	ld		%4, r4
	ld		%5, r7
	sti		r1, %7, %1
	live	%66
	sti		r1, %:l_3, %1
	sti		r1, %64, %1
	sti		r1, %65, %1
	sti		r1, %:l_6, %1
	sti		r1, %59, %1
	sti		r1, %:l_1, %1
	sti		r1, %:l_2, %1
	sti		r1, %151, %-4
	ldi		%144, %-2, r6

l_3:
	live	%66
	fork	%:l_1
	live	%66
	fork	%:l_2
	live	%66
	fork	%:l_3
	live	%66
	ld		%0, r3
	ld		%16777216, r6
	ldi		%:l_0, %0, r6
	ld		%0, r5
	zjmp	%:l_4

l_1:
	live	%66
	ld		%3, r3
	ld		%68436, r2
	ldi		%58, %-2, r6
	ld		%0, r5
	zjmp	%:l_4

l_2:
	live	%:l_0
	ld		%6, r3
	ld		%1409680135, r6
	ldi		%17, %1, r6
	ld		%0, r5
	zjmp	%:l_4
	sti		r6, r3, r5
	sti		r1, r5, r5

l_4:
	sti		r6, r3, %:l_5

l_6:
	live	%66
	zjmp	%:l_5
	zjmp	%:l_0

l_5:
	zjmp	%:l_6

; generated ;