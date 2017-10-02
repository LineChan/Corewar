.name		"faQUin"
.comment	"qui dit faquin dit bout en train :)"

l_0:
	sti		r1, %7, %1
	live	%1

l_5:
	sti		r1, %7, %1
	live	%1
	sti		r1, %:l_3, %1
	ld		%-10, r2
	ld		%1, r3
	fork	%:l_1

l_3:
	live	%1
	add		r2, r3, r2
	zjmp	%:l_2
	zjmp	%:l_3

l_2:
	ld		%-10, r2
	zjmp	%:l_3

l_1:
	sti		r1, %:l_6, %1
	ld		%-10, r2
	ld		%1, r3

l_6:
	live	%1
	add		r2, r3, r2
	zjmp	%:l_4
	fork	%:l_5
	zjmp	%:l_6

l_4:
	ld		%-10, r2
	fork	%:l_5
	zjmp	%:l_6

; generated ;