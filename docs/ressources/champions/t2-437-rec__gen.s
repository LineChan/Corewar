.name		"jbwc t2-437-rec"
.comment	"by bocal"

l_0:
	fork	%:l_1
	ld		%190055170, r3
	ld		%477, r4
	ld		%67851269, r5
	ld		%476, r6
	ld		%33950548, r7
	ld		%475, r8
	ld		%117573643, r9
	ld		%474, r10
	ld		%1409876490, r11
	ld		%473, r12
	ld		%190057218, r13
	ld		%472, r14
	ld		%202069005, r15
	ld		%471, r16
	xor		r2, r2, r2
	zjmp	%:l_2

l_1:
	ld		%34474836, r3
	ld		%505, r4
	ld		%251793409, r5
	ld		%504, r6
	ld		%0, r7
	or		r1, r7, r7
	ld		%503, r8
	ld		%151106816, r9
	ld		%502, r10
	ld		%16777216, r11
	ld		%-50, r12
	ld		%167936, r14
	or		r14, r1, r14
	sti		r14, %7, %-1
	ld		%17432571, r13
	ld		%-51, r14
	ld		%167770113, r15
	ld		%-52, r16
	xor		r2, r2, r2
	zjmp	%:l_2

l_2:
	sti		r3, r2, r4
	sti		r5, r2, r6
	sti		r7, r2, r8
	sti		r9, r2, r10
	sti		r11, r2, r12
	sti		r13, r2, r14
	sti		r15, r2, r16
	live	%1
	zjmp	%437

; generated ;