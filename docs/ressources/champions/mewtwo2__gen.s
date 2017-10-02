.name		"Mewtwo2"
.comment	"Vous allez mourir..."

l_0:
	st		r1, 26
	st		r1, 135
	ld		%0, r2
	zjmp	%:l_1

l_3:
	sti		r1, r2, r3

l_1:
	live	%1
	fork	%:l_2
	ld		%5, r3
	ld		%8, r5
	ld		%-140, r11
	ld		%190055426, r1
	ld		%940575572, r4
	ld		%190056194, r6
	ld		67, r7
	ld		%190056706, r8
	ld		%66979339, r9
	ld		%201327371, r10
	ld		%167641867, r12
	ld		%190057986, r13
	ld		%269486932, r14
	ld		%190056962, r15
	ld		%0, r2
	zjmp	%:l_3
	live	%1
	sti		r8, r2, r3

l_2:
	ld		%9, r3
	ld		%12, r5
	ld		%-136, r11
	ld		%84070655, r1
	ld		%100795147, r4
	ld		%83951616, r6
	ld		%134349579, r7
	ld		%84629514, r8
	ld		%1410073091, r9
	ld		%1409352195, r10
	ld		%:l_2, r12
	ld		%84431888, r13
	ld		%251790091, r14
	ld		%185204594, r15
	ld		%0, r2
	zjmp	%:l_3

; generated ;