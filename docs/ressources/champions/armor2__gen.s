.name		"Armor"
.comment	"coded by marcp"

l_0:
	xor		r4, r4, r4
	sti		r1, %12, %1

l_1:
	live	%1
	live	%1
	xor		r4, r4, r4
	zjmp	%:l_1

; generated ;