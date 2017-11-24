.name		" Paki"
.comment	" Paki"

l_0:
	ld		%:l_0, r15
	sti		r1, %28, %1
	sti		r1, %:l_3, %1
	sti		r1, %:l_1, %1
	st		r1, r10
	fork	%:l_1
	live	%42
	fork	%:l_2
	ld		%655339, r7
	ld		%655329, r8
	ld		%655319, r9
	ld		%655309, r10
	ld		%655299, r11
	ld		%40, r1
	ld		%45, r2
	ld		%50, r3
	ld		%55, r4
	ld		%55, r5
	xor		r16, r16, r16
	zjmp	%:l_3

l_2:
	ld		%655289, r7
	ld		%655279, r8

l_6:
	ld		%655269, r9
	ld		%84476042, r10
	ld		%1409748737, r11
	ld		%90, r1
	ld		%95, r2
	ld		%100, r3
	ld		%14, r4
	ld		%144, r5
	xor		r16, r16, r16
	zjmp	%:l_3

l_1:
	live	%42
	fork	%:l_4
	ld		%190056463, r7
	ld		%251857748, r8
	ld		%168756225, r9
	ld		%42, r11
	ld		%151000843, r11
	ld		%5, r1
	ld		%8, r2
	ld		%7, r3
	ld		%6, r4
	ld		%140, r5
	xor		r16, r16, r16
	zjmp	%:l_3

l_4:
	ld		%34296841, r7
	ld		%655259, r8
	ld		%655249, r9
	ld		%190057231, r10
	ld		%167770889, r11
	ld		%9, r1
	ld		%115, r2
	ld		%120, r3
	ld		%10, r4
	ld		%0, r5
	xor		r16, r16, r16
	zjmp	%:l_3

l_3:
	live	%42
	fork	%:l_3
	zjmp	%:l_5

l_5:
	sti		r10, r15, r4
	live	%42
	sti		r11, r15, r5
	zjmp	%:l_6

; generated ;