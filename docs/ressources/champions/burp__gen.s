.name		"burp"
.comment	"let's buuuuuuuurppp"

l_0:
	sti		r1, %:l_2, %1
	sti		r1, %121, %1
	sti		r1, %211, %1
	ld		%:l_0, r4
	ld		%4, r5
	ld		%1, r8
	ld		%50, r3
	ld		%-1, r9
	ld		%50, r7
	fork	%:l_1
	and		%0, %0, r1

l_2:
	live	%1
	and		%0, %0, r1
	fork	%:l_1
	zjmp	%:l_2

l_1:
	ld		%16777215, r2
	sti		r2, %:l_4, r3
	sti		r2, %:l_0, r9
	add		r3, r5, r3
	sub		r9, r5, r9
	live	%1
	sub		r7, r8, r7
	zjmp	%:l_3
	and		%0, %0, r1
	zjmp	%:l_1

l_3:
	fork	%:l_4
	ld		%50, r7
	ld		%4, r5
	ld		%1, r8
	ld		%50, r3
	ld		%-1, r9
	zjmp	%:l_1

l_4:
	ld		%16777215, r2
	sti		r2, %:l_4, r3
	sti		r2, %:l_0, r9
	add		r3, r5, r3
	sub		r9, r5, r9
	live	%1
	and		%0, %0, r1
	zjmp	%:l_4
	and		%0, %0, r1
	zjmp	%:l_4
	and		%0, %0, r1

; generated ;