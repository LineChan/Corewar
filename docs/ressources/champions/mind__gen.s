.name		"regarde moi,regarde moi bien..."
.comment	"mind control"

l_0:
	st		r1, r8
	ld		%0, r1
	st		r1, -11
	live	%42
	fork	%:l_0
	st		r8, r2
	st		r8, r3
	ld		%3, r15
	ld		%6, r14
	ld		%9, r13
	fork	%:l_1
	ld		%200, r12
	ld		%209, r11
	ld		%1, r2
	ld		%167770881, r3
	ld		%190054924, r4
	ld		%202312532, r5
	ld		%1409616656, r6
	ld		%252400647, r7
	ld		%134941961, r8
	ld		%0, r16
	zjmp	%:l_2

l_1:
	ld		%204, r12
	ld		%213, r11
	ld		%0, r16
	ld		%0, r16
	ld		%269177859, r4
	ld		%67898891, r5
	ld		%190055947, r6
	ld		%185469780, r7
	ld		%11534336, r8
	ld		%0, r16
	zjmp	%:l_2

l_2:
	zjmp	%:l_3

l_3:
	live	%42
	sti		r2, r12, r16
	sti		r3, r12, r15
	sti		r4, r12, r14
	sti		r5, r11, r16
	sti		r6, r11, r15
	sti		r7, r11, r14
	sti		r8, r11, r13
	zjmp	%176

; generated ;