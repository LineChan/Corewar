.name		"BANANA COMBO"
.comment	"Just a basic Winner Program"

l_0:
	sti		r1, %:l_1, %1

l_1:
	live	%1
	and		r2, r3, r4
	fork	%:l_1
	zjmp	%:l_1

; generated ;