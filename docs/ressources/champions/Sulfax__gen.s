.name		"SULFAX II"
.comment	"Et Vlan ..."

l_0:
	ld		%495, r8
	fork	%:l_1
	fork	%:l_2
	ld		%150994945, r15
	ld		%0, r2
	ld		%0, r16
	zjmp	%:l_3

l_2:
	st		r1, r15
	ld		%4, r2
	ld		%0, r16
	zjmp	%:l_3

l_1:
	fork	%:l_4
	ld		%190058248, r15
	ld		%8, r2
	ld		%0, r16
	zjmp	%:l_3

l_4:
	ld		%34144749, r15
	ld		%12, r2
	ld		%0, r16
	zjmp	%:l_3

l_3:
	live	%:l_3
	sti		r15, r8, r2
	zjmp	%493

; generated ;