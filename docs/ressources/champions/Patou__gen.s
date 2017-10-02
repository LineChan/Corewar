.name		" Patou"
.comment	" Patou"

l_0:
	ld		%:l_0, r15
	sti		r1, %21, %1
	sti		r1, %:l_1, %1
	st		r1, r10
	fork	%:l_1
	live	%42
	fork	%:l_2
	ld		%655329, r7
	ld		%655224, r8
	ld		%654979, r9
	ld		%654874, r10
	ld		%654884, r11
	ld		%50, r1
	ld		%150, r2
	ld		%390, r3
	ld		%430, r4
	ld		%470, r5
	xor		r16, r16, r16
	zjmp	%:l_3

l_2:
	ld		%655279, r7
	ld		%655184, r8
	ld		%655029, r9
	ld		%84476402, r10
	ld		%1409748737, r11
	ld		%100, r1
	ld		%190, r2
	ld		%340, r3
	ld		%14, r4
	ld		%504, r5
	xor		r16, r16, r16
	zjmp	%:l_3

l_1:
	live	%42
	fork	%:l_4
	ld		%190056463, r7
	ld		%251857748, r8
	ld		%168756225, r9
	ld		%0, r11
	ld		%151000843, r11
	ld		%5, r1
	ld		%8, r2
	ld		%7, r3
	ld		%6, r4
	ld		%500, r5
	xor		r16, r16, r16
	zjmp	%:l_3

l_4:
	ld		%34296841, r7
	ld		%655134, r8
	ld		%655079, r9
	ld		%190057231, r10
	ld		%167770880, r11
	ld		%9, r1
	ld		%240, r2
	ld		%290, r3
	ld		%10, r4
	ld		%0, r5
	xor		r16, r16, r16
	zjmp	%:l_3

l_3:
	sti		r11, r15, r5
	zjmp	%498

; generated ;