.name		"La FoUiNe !!!"
.comment	"?????????????"

l_0:
	st		r1, 19
	st		r1, 113
	st		r1, 116
	fork	%:l_1

l_7:
	live	%42
	fork	%:l_2
	fork	%:l_3
	ld		83, r2
	ld		%300, r3
	xor		r4, r4, r4
	zjmp	%:l_4

l_2:
	fork	%:l_5
	ld		64, r2
	ld		%304, r3
	xor		r4, r4, r4
	zjmp	%:l_4

l_3:
	ld		48, r2
	ld		%308, r3
	xor		r4, r4, r4
	zjmp	%:l_4

l_5:
	ld		32, r2
	ld		%312, r3
	xor		r4, r4, r4
	zjmp	%:l_4

l_4:
	sti		r2, r3, r4
	live	%:l_7
	zjmp	%:l_6

l_1:
	live	%42

l_6:
	fork	%:l_7
	xor		r5, r5, r5
	zjmp	%:l_1

; generated ;