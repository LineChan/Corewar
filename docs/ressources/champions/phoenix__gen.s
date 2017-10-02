.name		"THE PHOENIX"
.comment	"pras1 ver. bis 1"

l_0:
	sti		r1, %:l_3, %1
	sti		r10, %:l_4, %:l_1
	sti		r9, %:l_5, %-105
	sti		r13, %:l_6, %-590
	sti		r14, %:l_1, %1000
	live	%1
	ld		%0, r2
	ld		%0, r10

l_2:
	fork	%:l_1

l_1:
	live	%1
	fork	%:l_2
	and		r14, %2, r14
	and		r15, %:l_6, r15
	sub		r14, r15, r2
	live	%1
	zjmp	%:l_3

l_3:
	live	%1
	fork	%:l_2
	sti		r1, %:l_4, %10
	st		r10, 1000
	live	%1
	zjmp	%:l_4

l_4:
	live	%1
	fork	%:l_2
	sti		r1, %8000, %-150
	st		r9, -500
	live	%1
	zjmp	%:l_5

l_5:
	live	%1
	fork	%:l_2
	sti		r1, %1000, %-5001
	st		r13, 25000
	zjmp	%:l_6

l_6:
	live	%1
	fork	%:l_2
	sti		r1, %5000, %8991
	st		r14, 0
	live	%1
	ld		%0, r2
	zjmp	%:l_0

; generated ;