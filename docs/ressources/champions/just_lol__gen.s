.name		"Just_lol"
.comment	"Made by biberi_j, all right reserved"

l_0:
	xor		r5, r5, r5
	sti		r1, %:l_4, %1
	sti		r1, %:l_9, %1
	sti		r1, %:l_9, %6
	sti		r1, %:l_9, %11
	sti		r1, %:l_9, %16
	sti		r1, %:l_9, %21
	sti		r1, %:l_9, %26
	sti		r1, %:l_9, %31
	sti		r1, %:l_9, %36
	sti		r1, %:l_1, %1
	fork	%:l_1
	zjmp	%:l_2

l_5:
	ld		%-5, r5
	ld		%1024, r4

l_3:
	ld		%-5, r3

l_4:
	live	%:l_4
	sti		r4, %:l_5, r3
	add		r3, r5, r3
	sti		r4, %:l_5, r3
	add		r3, r5, r3
	sti		r4, %:l_5, r3
	add		r3, r5, r3
	sti		r4, %:l_5, r3
	add		r3, r5, r3
	sti		r4, %:l_5, r3
	add		r3, r5, r3
	xor		r3, %-430, r15
	zjmp	%:l_3
	and		r6, %0, r6
	zjmp	%:l_4

l_1:
	xor		r5, r5, r5
	live	%0
	fork	%:l_5
	zjmp	%:l_1

l_2:
	fork	%:l_6
	xor		r5, r5, r5

l_8:
	live	%:l_8
	fork	%:l_7
	zjmp	%:l_8

l_10:
	xor		r5, r5, r5

l_9:
	live	%:l_9
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	zjmp	%:l_9

l_7:
	fork	%:l_1
	live	%0
	fork	%:l_10
	live	%0
	fork	%:l_6
	live	%0
	xor		r5, r5, r5
	zjmp	%:l_7

l_6:
	live	%1
	fork	%:l_11
	live	%1
	fork	%:l_6
	xor		r5, r5, r5
	zjmp	%:l_6

l_11:
	fork	%:l_12
	ld		%190054658, r1
	ld		%10, r3
	xor		r5, r5, r5
	zjmp	%:l_13

l_12:
	ld		%50397184, r1
	ld		%14, r3
	xor		r5, r5, r5
	zjmp	%:l_13

l_13:
	sti		r1, r2, r3
	live	%0

; generated ;