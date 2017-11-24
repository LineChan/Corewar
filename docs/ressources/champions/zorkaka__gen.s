.name		"Zorkaka"
.comment	"Encore plus nul que zork. Oui, Oui, c possible"

l_0:
	sti		r1, %:l_2, %1
	sti		r1, %:l_1, %1
	sti		r1, %120, %1

l_2:
	live	%1
	ld		%0, r4
	fork	%:l_1
	zjmp	%:l_2

l_1:
	live	%1
	ld		%210, r3
	fork	%:l_3
	fork	%:l_4
	ld		%0, r2
	zjmp	%:l_5

l_3:
	fork	%:l_6
	ld		%4, r2
	ld		%0, r4
	zjmp	%:l_5

l_4:
	ld		%8, r2
	ld		%0, r4
	zjmp	%:l_5

l_6:
	ld		%12, r2
	ld		%0, r4
	zjmp	%:l_5

l_5:
	ldi		r2, %13, r6
	ld		%0, r4
	live	%1
	sti		r6, r2, r3
	zjmp	%205

; generated ;