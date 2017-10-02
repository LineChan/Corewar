.name		"Beyoung"
.comment	"Kill him if you want"

l_0:
	ld		%100, r4
	sti		r7, %:l_1, %1
	ld		%100, r4
	sti		r7, %:l_1, %1
	ld		%100, r4
	sti		r7, %:l_1, %1
	ld		%100, r4
	sti		r7, %:l_1, %1
	ld		%100, r4
	sti		r7, %:l_1, %1
	ld		%100, r4
	sti		r7, %:l_1, %1
	ld		%100, r4
	sti		r7, %:l_1, %1
	ld		%100, r4
	sti		r7, %:l_1, %1
	ld		%100, r4
	sti		r7, %:l_1, %1
	ld		%100, r4
	sti		r7, %:l_1, %1
	ld		%100, r4
	sti		r7, %:l_1, %1
	ld		%100, r4
	sti		r7, %:l_1, %1
	ld		%100, r4
	sti		r7, %:l_1, %1
	ld		%100, r4
	and		r7, %0, r7
	sti		r7, %:l_1, %1

l_1:
	live	%1
	live	%1
	live	%2
	live	%3
	live	%4
	zjmp	%:l_1

; generated ;