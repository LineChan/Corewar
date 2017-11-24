.name		"poney"
.comment	"et le poney fait... bliiiiii !!!"

l_0:
	sti		r1, %:l_3, %1
	and		r1, %0, r1

l_2:
	sti		r1, %:l_3, %1
	ld		%:l_3, r2
	ld		%:l_3, r3

l_3:
	live	%1
	zjmp	%:l_1

l_1:
	live	%2
	fork	%:l_2
	zjmp	%:l_3

; generated ;