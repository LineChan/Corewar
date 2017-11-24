.name		"ZE MELON"
.comment	"BEULONG"

l_0:
	ld		%:l_0, r7
	zjmp	%:l_1

l_5:
	sti		r1, r2, r7
	sti		r3, r4, r7
	sti		r5, r6, r7
	sti		r8, r9, r7
	sti		r10, r11, r7
	sti		r12, r13, r7
	sti		r14, r15, r7
	zjmp	%:l_2

l_1:
	st		r1, 200
	st		r1, 414
	live	%1
	fork	%:l_1
	live	%42
	fork	%:l_3
	live	%42
	fork	%:l_4
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
	zjmp	%:l_5

l_4:
	ld		%118182915, r1
	ld		%-196, r2
	ld		%84281099, r3
	ld		%-193, r4
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
	zjmp	%:l_5

l_3:
	fork	%:l_6
	ld		%-252645136, r1
	ld		%-144, r2
	ld		%-252645136, r3
	ld		%-146, r4
	ld		%-252645136, r5
	ld		%-148, r6
	ld		%-252645136, r8
	ld		%-150, r9
	ld		%-252645136, r10
	ld		%-152, r11
	ld		%-252645136, r12
	ld		%-154, r13
	ld		%-252645136, r14
	ld		%-158, r15
	ld		%0, r7
	zjmp	%:l_5

l_6:
	ld		%:l_6, r1
	ld		%-446, r2
	ld		%0, r3
	ld		%-455, r4
	ld		%0, r5
	ld		%-464, r6
	ld		%167770880, r8

l_2:
	ld		%-473, r9
	ld		%1, r10
	ld		%-482, r11
	ld		%1793, r12
	ld		%-491, r13
	ld		%42991616, r14
	ld		%:l_0, r15
	ld		%0, r7
	zjmp	%:l_5

; generated ;