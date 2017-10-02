.name		"Veni Vidi Vici"
.comment	"ils sont fous ces Romains !"

l_0:
	st		r1, r4
	sti		r4, %:l_2, %1

l_2:
	live	%1
	fork	%:l_1
	ld		%:l_0, r2
	ld		%0, r9
	zjmp	%:l_2

l_4:
	sti		r4, %:l_5, %1
	live	%1
	fork	%:l_3
	zjmp	%:l_4
	sti		r4, %0, %1
	live	%:l_2
	st		r4, r1
	ld		%0, r5
	zjmp	%:l_0

l_1:
	st		r1, r4
	sti		r4, %-41, %1

l_5:
	live	%1

l_6:
	fork	%:l_3
	ld		%:l_0, r2
	zjmp	%:l_5
	sti		r4, %7, %1
	live	%1
	zjmp	%:l_6
	sti		r4, %7, %1
	live	%1
	st		r4, r1
	ld		%0, r5
	zjmp	%:l_1

l_3:
	fork	%:l_7
	ld		%16000, r10
	sti		r10, %:l_3, %5000
	ld		%0, r14
	zjmp	%:l_3

l_7:
	st		r1, r4
	sti		r4, %:l_5, %1
	live	%1

l_8:
	fork	%:l_1
	fork	%16000
	ld		%:l_0, r2
	sti		r4, %-18, %1
	zjmp	%:l_8
	sti		r4, %7, %1
	live	%1
	st		r4, r1
	ld		%0, r5
	zjmp	%:l_7

; generated ;