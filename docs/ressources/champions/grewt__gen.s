.name		"Les doigts dans le CUL !!!! 0.01pre alpha6"
.comment	"sOdOmitic pheng and pratt challenger"

l_0:
	sti		r1, %44, %1
	sti		r1, %:l_4, %1
	sti		r1, %:l_1, %1
	live	%2
	fork	%:l_1
	live	%2
	fork	%:l_2
	ld		%0, r3
	live	%1
	fork	%:l_3

l_4:
	live	%1
	st		r3, -50
	zjmp	%:l_4

l_1:
	live	%4993
	ld		%0, r2

l_5:
	st		r2, -128
	ld		%0, r2
	zjmp	%:l_5
	live	%98

l_3:
	live	%1
	ld		%0, r2
	fork	%:l_2
	zjmp	%:l_3

l_2:
	live	%4
	ld		%57672192, r2
	st		r2, 257
	ld		%33554432, r2
	st		r2, 249
	ld		%50333187, r2
	ld		%1879179266, r3
	ld		%0, r8
	fork	%:l_6
	live	%4
	zjmp	%211

l_6:
	live	%2
	zjmp	%203

; generated ;