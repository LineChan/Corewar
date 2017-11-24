.name		"<<<<<< KINDER SURPRISE >>>>>>>>>"
.comment	"Papa, Papa !!!!!!! tu nous offre un champion ??????????"

l_0:
	sti		r1, %59, %1

l_2:
	live	%1

l_1:
	and		r1, %:l_1, r1
	live	%1
	fork	%90
	sti		r1, %59, r1
	live	%1
	and		r1, %59, r1
	zjmp	%:l_1
	live	%1
	sti		r1, %59, r1
	fork	%:l_2
	live	%1
	zjmp	%:l_0

; generated ;