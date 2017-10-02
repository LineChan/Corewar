.name		"je suis debile-2-"
.comment	"ca blaste-2-"

l_0:
	sti		r1, %:l_1, %1
	sti		r1, %:l_3, %1
	sti		r1, %:l_2, %1
	sti		r1, %:l_2, %6
	ld		54, r2
	ld		53, r3
	ld		52, r4
	ld		%36, r13
	ld		%380, r15
	and		%0, %0, r5
	fork	%:l_1
	fork	%:l_2

l_3:
	live	%1
	zjmp	%:l_3

l_2:
	live	%1
	live	%1
	zjmp	%:l_2

l_1:
	live	%1
	ld		%200, r11
	live	%1
	live	%1
	fork	%:l_4

l_5:
	sti		r2, r11, %33
	sti		r3, r11, %30
	sti		r4, r11, %27
	sti		r2, r11, %24
	sti		r3, r11, %21
	sti		r4, r11, %18
	sti		r2, r11, %15
	sti		r3, r11, %12
	sti		r4, r11, %9
	sti		r2, r11, %6
	sti		r3, r11, %3
	sti		r4, r11, %0
	add		r11, r13, r11
	sub		r15, r11, r14
	zjmp	%:l_1
	and		%0, %0, r5
	zjmp	%:l_5

l_4:
	sti		r1, r2, r3

; generated ;