.name		"Fc8xDh3"
.comment	"?????"

l_0:
	ld		%:l_0, r7
	zjmp	%:l_1

l_4:
	sti		r1, r2, r7
	sti		r3, r4, r7
	sti		r5, r6, r7
	sti		r8, r9, r7
	sti		r10, r11, r7
	sti		r12, r13, r7
	sti		r14, r15, r7
	zjmp	%-240

l_1:
	st		r1, 192
	st		r1, 406
	live	%42
	fork	%:l_2
	live	%42
	fork	%:l_3
	ld		%190054658, r1
	ld		%-200, r2
	ld		%67570516, r3
	ld		%-197, r4
	ld		%1409812743, r5
	ld		%-194, r6
	ld		%118182924, r8
	ld		%-191, r9
	ld		%235865857, r10
	ld		%-188, r11
	ld		%167710720, r12
	ld		%-185, r13
	ld		%0, r14
	ld		%-182, r15
	ld		%0, r7
	zjmp	%:l_4

l_3:
	ld		%118182915, r1
	ld		%-196, r2
	ld		%84281099, r3
	ld		%:l_4, r4
	ld		%190056971, r5
	ld		%-190, r6
	ld		%218565460, r8
	ld		%-187, r9
	ld		%1, r10
	ld		%-184, r11
	ld		%0, r12
	ld		%-181, r13
	ld		%0, r14
	ld		%-178, r15
	ld		%0, r7
	zjmp	%:l_4

l_2:
	fork	%:l_5
	ld		%0, r1
	ld		%-144, r2
	ld		%0, r3
	ld		%-145, r4
	ld		%0, r5
	ld		%:l_3, r6
	ld		%0, r8
	ld		%-147, r9
	ld		%0, r10
	ld		%-148, r11
	ld		%0, r12
	ld		%-149, r13
	ld		%0, r14
	ld		%-150, r15
	ld		%0, r7
	zjmp	%:l_4

l_5:
	ld		%:l_5, r1
	ld		%-204, r2
	ld		%0, r3
	ld		%-213, r4
	ld		%0, r5
	ld		%-222, r6
	ld		%167770880, r8
	ld		%-231, r9
	ld		%1, r10
	ld		%-240, r11
	ld		%1793, r12
	ld		%-249, r13
	ld		%42991616, r14
	ld		%-258, r15
	ld		%0, r7
	zjmp	%:l_4

; generated ;