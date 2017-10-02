.name		"PuNkS NoT de4D"
.comment	"F34R............."

l_0:
	sti		r1, %:l_2, %1
	sti		r1, %:l_1, %1
	and		r2, %0, r2

l_1:
	live	%1
	fork	%:l_1
	fork	%:l_2
	zjmp	%:l_1

l_2:
	live	%1
	zjmp	%:l_2

; generated ;