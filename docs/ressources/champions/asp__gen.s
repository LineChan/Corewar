.name		"Aggressive Skating Panda"
.comment	"Aggressive Skating Panda"

l_0:
	sti		r1, %65, %1
	sti		r1, %68, %1
	sti		r1, %71, %1
	sti		r1, %74, %1
	sti		r1, %77, %1
	sti		r1, %80, %1
	sti		r1, %83, %1
	and		r1, %0, r1
	zjmp	%:l_1

l_1:
	st		r1, 400
	live	%1
	st		r1, 1500
	live	%1
	st		r1, 100
	live	%1
	st		r1, 400
	live	%1
	st		r1, 1500
	live	%1
	st		r1, 100
	live	%1
	st		r1, 400
	live	%1
	zjmp	%:l_1
	live	%1
	zjmp	%:l_0

; generated ;