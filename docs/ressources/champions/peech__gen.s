.name		"peech"
.comment	"no comment.."

l_0:
	ld		%72, r2
	ld		%0, r3
	ld		%2, r4
	ld		%1, r5
	fork	%:l_1
	fork	%:l_1
	sti		r1, %:l_4, %1
	sti		r1, %:l_3, %1
	sti		r1, %175, %-4

l_4:
	live	%42
	add		r2, r3, r2
	sub		r4, r5, r4
	and		r4, %1, r5
	zjmp	%:l_2
	fork	%:l_3

l_2:
	fork	%:l_1
	and		r1, %0, r9
	zjmp	%:l_4

l_1:
	ld		%50921472, r5
	ld		%5, r3
	ld		%190056962, r7
	ld		%50921472, r8
	sti		r7, %97, %0
	sti		r8, %90, %4
	sub		r2, r3, r3
	add		r5, r3, r5
	sti		r5, %78, %-1
	fork	%:l_5
	ld		%0, r3
	and		r1, %0, r9
	zjmp	%:l_6

l_5:
	ld		%4, r3
	and		r1, %0, r9
	zjmp	%:l_6

l_3:
	live	%42
	zjmp	%:l_3

l_6:
	ldi		%19, r3, r10
	and		r1, %0, r9
	live	%42
	sti		r10, r2, r3
	zjmp	%-3

; generated ;