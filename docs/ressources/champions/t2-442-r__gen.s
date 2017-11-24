.name		"jbwc t4-442-b"
.comment	"by bocal"

l_0:
	xor		r2, r2, r2
	zjmp	%:l_1

l_4:
	sti		r3, r2, r4
	sti		r5, r2, r6
	sti		r7, r2, r8
	sti		r9, r2, r10
	sti		r11, r2, r12

l_2:
	sti		r13, r2, r14
	sti		r15, r2, r16
	live	%1
	zjmp	%:l_2

l_1:
	fork	%:l_3
	ld		%190055170, r3
	ld		%-471, r4
	ld		%67851269, r5
	ld		%-472, r6
	ld		%33950548, r7
	ld		%-473, r8
	ld		%117573643, r9
	ld		%-474, r10
	ld		%1409876490, r11
	ld		%-475, r12
	ld		%190057218, r13
	ld		%-476, r14
	ld		%202069005, r15
	ld		%-477, r16
	add		r2, r2, r2
	add		r2, r2, r2
	xor		r2, r2, r2
	zjmp	%:l_4

l_3:
	ld		%34474836, r3
	ld		%-443, r4
	ld		%251793409, r5
	ld		%-444, r6
	ld		%0, r7
	or		r1, r7, r7
	ld		%-445, r8
	ld		%167641344, r9
	ld		%-446, r10
	ld		%16777216, r11
	ld		%-100, r12
	ld		%167936, r14
	or		r14, r1, r14
	sti		r14, %7, %-1
	ld		%17432571, r13
	ld		%:l_3, r14
	ld		%167770121, r15
	ld		%-102, r16
	xor		r2, r2, r2
	zjmp	%:l_4

; generated ;