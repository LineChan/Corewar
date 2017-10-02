.name		"vieille_pute"
.comment	"prog fait rapidement et sans pretention de victoire"

l_0:
	sti		r1, %:l_1, %1
	sti		r1, %:l_10, %1
	sti		r1, %:l_2, %1
	sti		r1, %:l_3, %1
	sti		r1, %:l_5, %1
	sti		r1, %:l_6, %1
	sti		r1, %:l_7, %1
	sti		r1, %:l_4, %1
	sti		r1, %:l_8, %1
	sti		r1, %:l_9, %1
	ld		0, r2
	ld		1000, r3
	and		r1, %0, r1
	zjmp	%:l_1

l_2:
	live	%1
	sti		r2, r3, %0
	sti		r2, r3, %0
	sti		r2, r3, %0
	sti		r2, r3, %0
	sti		r2, r3, %0
	sti		r2, r3, %0
	zjmp	%:l_2

l_3:
	live	%1
	sti		r2, r3, %0
	sti		r2, r3, %0
	sti		r2, r3, %0
	sti		r2, r3, %0
	sti		r2, r3, %0
	sti		r2, r3, %0
	zjmp	%:l_3

l_1:
	live	%1
	fork	%:l_4
	fork	%:l_2
	zjmp	%:l_1

l_5:
	live	%1
	sti		r2, r3, %0
	sti		r2, r3, %0
	sti		r2, r3, %0
	sti		r2, r3, %0
	sti		r2, r3, %0
	sti		r2, r3, %0
	zjmp	%:l_5

l_6:
	live	%1
	sti		r2, r3, %0
	sti		r2, r3, %0
	sti		r2, r3, %0
	sti		r2, r3, %0
	sti		r2, r3, %0
	sti		r2, r3, %0
	zjmp	%:l_6

l_7:
	live	%1
	sti		r2, r3, %0
	sti		r2, r3, %0
	sti		r2, r3, %0
	sti		r2, r3, %0
	sti		r2, r3, %0
	sti		r2, r3, %0
	zjmp	%:l_7

l_4:
	live	%1
	fork	%:l_8
	fork	%:l_9
	zjmp	%:l_4

l_8:
	live	%1
	fork	%:l_7
	fork	%:l_3
	zjmp	%:l_8

l_9:
	live	%1
	fork	%:l_5
	fork	%:l_6
	zjmp	%:l_9

l_10:
	live	%1
	zjmp	%:l_10

; generated ;