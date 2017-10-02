.name		"Jmp"
.comment	"Jmp Jmp Jmp ..."

l_0:
	sti		r1, %:l_3, %1
	sti		r1, %:l_5, %1
	sti		r1, %:l_12, %1
	xor		r2, r2, r2
	zjmp	%:l_1

l_7:
	sti		r12, %17, %-1
	live	%7
	sti		r2, r3, r4
	zjmp	%-300
	live	%42

l_8:
	sti		r12, %17, %-1
	live	%7
	sti		r2, r3, r4
	zjmp	%-300
	live	%42

l_1:
	fork	%:l_2
	live	%42
	ld		%67763924, r2
	ld		%-295, r3
	ld		%4, r10
	ld		%67763924, r12

l_3:
	live	%42
	add		r2, r10, r2
	add		r3, r10, r3
	add		r12, r10, r12
	fork	%:l_3

l_4:
	live	%7
	fork	%:l_2
	live	%7
	fork	%:l_4
	live	%7
	fork	%:l_5
	live	%42
	ld		%190054915, r2
	ld		%0, r4
	xor		r6, r6, r6
	fork	%:l_6
	zjmp	%:l_7

l_6:
	zjmp	%:l_8

l_5:
	live	%42
	ld		%42, r11
	ld		%4, r4
	xor		r6, r6, r6
	fork	%:l_9
	zjmp	%:l_7

l_9:
	zjmp	%:l_8

l_2:
	ld		%589824, r5
	live	%7
	fork	%:l_2
	live	%7
	fork	%:l_10
	fork	%:l_11
	live	%7
	ld		%0, r4
	xor		r2, r2, r2
	zjmp	%:l_12

l_10:
	fork	%:l_13
	live	%7
	ld		%24, r4
	xor		r2, r2, r2
	zjmp	%:l_12

l_11:
	ld		%12, r4
	xor		r2, r2, r2
	zjmp	%:l_12

l_13:
	ld		%36, r4
	xor		r2, r2, r2
	zjmp	%:l_12

l_12:
	live	%7
	sti		r5, r4, %70
	sti		r5, r4, %110
	sti		r5, r4, %150
	sti		r5, r4, %190
	sti		r5, r4, %230
	sti		r5, r4, %270
	sti		r5, r4, %310
	sti		r5, r4, %350
	sti		r5, r4, %390
	sti		r5, r4, %430
	zjmp	%:l_12

; generated ;