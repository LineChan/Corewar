.name		"Salameche3"
.comment	"sala..."

l_0:
	st		r1, 21
	st		r1, 135
	st		r1, 140
	st		r1, 258
	live	%1
	fork	%:l_1
	ld		%5, r3
	ld		%8, r5
	ld		%190055426, r1
	ld		93, r4
	ld		%190056194, r6
	ld		%34147156, r7
	ld		%33554432, r8
	ld		%33, r9
	ld		%190057218, r10
	ld		%34409300, r11
	ld		55, r12
	ld		%26, r13
	ld		%190058242, r14
	ld		%190054658, r15
	ld		%-200, r16
	ld		%0, r2
	zjmp	%:l_2
	live	%1
	sti		r6, r2, r3

l_3:
	live	%1
	zjmp	%:l_3

l_1:
	ld		%9, r3
	ld		%12, r5
	ld		%83951616, r1
	ld		%100795147, r4
	ld		%84628488, r6
	ld		%167904011, r7
	ld		%65792, r8
	ld		%37, r9
	ld		%84628492, r10
	ld		%235012875, r11
	ld		%-327680, r12
	ld		%30, r13
	ld		%269090611, r14
	ld		%50331648, r15
	ld		%-196, r16
	ld		%0, r2
	zjmp	%:l_2

l_2:
	live	%1
	fork	%:l_4
	zjmp	%:l_2

l_4:
	sti		r1, r2, r3

; generated ;