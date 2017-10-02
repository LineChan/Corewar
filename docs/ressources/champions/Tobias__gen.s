.name		" Tobias"
.comment	" Tobias_Rieper"

l_0:
	ld		%:l_0, r15
	sti		r1, %32, %1
	sti		r1, %:l_3, %1
	sti		r1, %:l_1, %1
	st		r1, r10
	st		r1, r8
	fork	%:l_1
	live	%42
	fork	%:l_2
	ld		%150995713, r7
	ld		%42, r9
	ld		%167770889, r9
	ld		%42, r11
	ld		%167770889, r11
	ld		%62, r1
	ld		%61, r2
	ld		%60, r3
	ld		%121, r4
	ld		%120, r5
	xor		r16, r16, r16
	zjmp	%:l_3

l_2:
	ld		%150995713, r7
	ld		%42, r9
	ld		%167770889, r9
	ld		%84476042, r10
	ld		%1409748737, r11
	ld		%92, r1
	ld		%91, r2
	ld		%90, r3
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
	ld		%655224, r8
	ld		%150995713, r9
	ld		%190057231, r10
	ld		%589873, r11
	ld		%9, r1
	ld		%150, r2
	ld		%122, r3
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
	zjmp	%138

; generated ;