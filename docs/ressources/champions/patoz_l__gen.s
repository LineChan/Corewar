.name		"Champi"
.comment	"Euh..."

l_0:
	sti		r1, %:l_1, %1
	sti		r1, %:l_2, %1
	sti		r1, %:l_3, %1
	sti		r1, %:l_3, %2
	xor		r2, r2, r2

l_1:
	live	%12
	xor		r2, r2, r2
	zjmp	%:l_0
	fork	%:l_1

l_2:
	live	%12
	sti		r1, r2, r4
	add		r1, r2, r4
	xor		r1, r4, r4
	sti		r1, %1, %1
	sti		r1, r2, r4
	add		r1, r2, r4
	xor		r1, r4, r4
	sti		r1, %1, %1
	sti		r1, r2, r4
	add		r1, r2, r4
	xor		r1, r4, r4
	sti		r1, %1, %1
	live	%12
	zjmp	%:l_2

l_3:
	live	%12
	live	%12
	lfork	%:l_3
	sti		r1, %1, %1

; generated ;