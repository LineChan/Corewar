.name		"StarShit Shooter"
.comment	"Meuh!"

l_0:
	sti		r1, %:l_1, %1

l_1:
	live	%1
	ld		%1, r2
	ld		%9, r3
	ld		%:l_0, r4
	sti		r2, %:l_0, %1
	sti		r1, %:l_0, %5
	sti		r3, %:l_0, %9
	sti		r4, %:l_0, %13
	fork	%:l_1
	and		%0, %0, r6

; generated ;