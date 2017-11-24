.name		"Majesty of Gaia II"
.comment	"Et la Terre sera encore plus pure..."

l_0:
	sti		r1, %7, %1
	live	%0
	sti		r1, %:l_6, %1
	sti		r1, %:l_8, %1
	sti		r1, %:l_4, %1
	sti		r1, %:l_5, %1
	sti		r1, %:l_10, %1
	sti		r1, %18, %1
	fork	%:l_1

l_5:
	live	%9
	fork	%:l_2
	live	%9
	fork	%:l_3
	fork	%:l_4
	and		%0, %0, r5
	zjmp	%:l_5

l_2:
	ld		218, r0
	ld		217, r1
	ld		216, r2
	ld		215, r3
	ld		214, r4
	ld		213, r5
	ld		212, r6
	ld		211, r7
	ld		210, r8
	ld		209, r9
	ld		208, r10
	ld		207, r11
	ld		%1879769259, r13
	ld		%65540, r15

l_6:
	live	%9
	ld		%1879048319, r14

l_7:
	st		r14, 6
	st		r0, 0
	add		r15, r14, r14
	sub		r14, r13, r12
	zjmp	%:l_6
	ld		%0, r12
	zjmp	%:l_7

l_3:
	ld		-45, r0
	ld		-46, r1
	ld		-47, r2
	ld		-48, r3
	ld		-49, r4
	ld		-50, r5
	ld		-51, r6
	ld		-52, r7
	ld		-53, r8
	ld		-54, r9
	ld		-55, r10
	ld		-56, r11
	ld		%1879834507, r13
	ld		%65540, r15
	ld		%0, r12
	zjmp	%:l_8

l_4:
	live	%9
	ld		%0, r5
	zjmp	%:l_4

l_8:
	live	%9
	ld		%1879113567, r14

l_9:
	st		r14, 6
	st		r0, 0
	add		r15, r14, r14
	sub		r14, r13, r12
	zjmp	%:l_8
	ld		%0, r12
	zjmp	%:l_9

l_1:
	ld		%:l_1, r1

l_10:
	live	%9
	zjmp	%:l_10

; generated ;