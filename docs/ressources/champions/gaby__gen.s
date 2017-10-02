.name		"Just 4 U"
.comment	"Oh gaby...."

l_0:
	sti		r1, %:l_2, %1
	sti		r1, %:l_3, %1
	xor		r2, r2, r2
	zjmp	%:l_1

l_5:
	sti		r12, %17, %-1
	live	%7
	sti		r2, r3, r4
	zjmp	%-300
	live	%42

l_6:
	sti		r12, %17, %-1
	live	%7
	sti		r2, r3, r4
	zjmp	%-300
	live	%42

l_1:
	ld		%67763924, r2
	ld		%-295, r3
	ld		%4, r10
	ld		%67763924, r12

l_2:
	live	%42
	add		r2, r10, r2
	add		r3, r10, r3
	add		r12, r10, r12
	fork	%:l_2
	live	%7
	fork	%:l_3
	live	%42
	ld		%190054915, r2
	ld		%0, r4
	xor		r6, r6, r6
	fork	%:l_4
	zjmp	%:l_5

l_4:
	zjmp	%:l_6

l_3:
	live	%42
	ld		%42, r11
	ld		%4, r4
	xor		r6, r6, r6
	fork	%:l_7
	zjmp	%:l_5

l_7:
	zjmp	%:l_6

; generated ;