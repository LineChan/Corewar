.name		"Prout"
.comment	"Bah quoi ?"

l_0:
	sti		r1, %:l_2, %1
	sti		r1, %:l_4, %1
	xor		r2, r2, r2
	zjmp	%:l_1

l_6:
	sti		r12, %17, %-1
	live	%7
	sti		r2, r3, r4
	zjmp	%-300
	live	%42

l_7:
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

l_3:
	live	%7
	fork	%:l_3
	live	%7
	fork	%:l_4
	live	%42
	ld		%190054915, r2
	ld		%0, r4
	xor		r6, r6, r6
	fork	%:l_5
	zjmp	%:l_6

l_5:
	zjmp	%:l_7

l_4:
	live	%42
	ld		%42, r11
	ld		%4, r4
	xor		r6, r6, r6
	fork	%:l_8
	zjmp	%:l_6

l_8:
	zjmp	%:l_7

; generated ;