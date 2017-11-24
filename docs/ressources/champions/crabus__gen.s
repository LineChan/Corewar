.name		"Crabus"
.comment	"Tout simplement Crabus"

l_0:
	sti		r1, %185, %1
	live	%42
	ld		%0, r7
	fork	%:l_1
	fork	%:l_2
	live	%42
	fork	%:l_3
	ld		147, r5
	ld		%150, r6
	xor		r7, r7, r7
	zjmp	%:l_4

l_1:
	fork	%:l_5
	live	%42
	fork	%:l_6
	ld		120, r5
	ld		%154, r6
	xor		r7, r7, r7
	zjmp	%:l_4

l_2:
	live	%42
	fork	%:l_7
	ld		96, r5
	ld		%158, r6
	xor		r7, r7, r7
	zjmp	%:l_4

l_9:
	sti		r1, %:l_8, %1
	xor		r1, r1, r1

l_8:
	live	%1
	zjmp	%:l_8

l_5:
	live	%42
	fork	%:l_9
	ld		52, r5
	ld		%162, r6
	xor		r7, r7, r7
	zjmp	%:l_4

l_3:
	ld		36, r5
	ld		%166, r6
	xor		r7, r7, r7
	zjmp	%:l_4

l_4:
	sti		r5, r6, r7
	live	%1
	sti		r5, r6, r7
	zjmp	%135

l_6:
	ld		%190055686, r5
	ld		%10, r6
	xor		r7, r7, r7
	zjmp	%:l_10

l_7:
	ld		%:l_4, r5
	ld		%14, r6
	xor		r7, r7, r7
	zjmp	%:l_10

l_10:
	sti		r5, r6, r7
	live	%1

; generated ;