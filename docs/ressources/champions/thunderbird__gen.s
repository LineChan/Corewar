.name		"L'oiseau du tonnere et son guano foudroyant"
.comment	"Ptites torpilles..."

l_0:
	st		r1, 232
	ld		%488, r14
	fork	%:l_1
	live	%42
	fork	%:l_2
	fork	%:l_3
	ld		209, r12
	ld		%16, r13
	ld		%0, r15
	zjmp	%:l_4

l_3:
	ld		175, r12
	ld		%4, r13
	ld		%0, r15
	zjmp	%:l_4

l_2:
	fork	%:l_5
	ld		154, r12
	ld		%8, r13
	ld		%0, r15
	zjmp	%:l_4

l_5:
	ld		136, r12
	ld		%12, r13
	ld		%0, r15
	zjmp	%:l_4

l_1:
	live	%42
	fork	%:l_6
	fork	%:l_7
	ld		%0, r15
	ld		%0, r15
	live	%42
	zjmp	%:l_0

l_7:
	ld		%:l_7, r15
	live	%42
	zjmp	%:l_0

l_6:
	fork	%:l_8
	ld		51, r12
	ld		%0, r13
	ld		%0, r15
	zjmp	%:l_4

l_8:
	ld		%:l_8, r15
	ld		%0, r15
	ld		%0, r15
	live	%42
	zjmp	%:l_0

l_4:
	sti		r12, r13, r14
	ld		%0, r15
	live	%42
	zjmp	%470

; generated ;