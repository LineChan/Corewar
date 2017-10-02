.name		"notre zork"
.comment	"desole"

l_0:
	sti		r1, %:l_1, %1
	and		r1, %0, r1

l_1:
	live	%1
	zjmp	%:l_1

; generated ;