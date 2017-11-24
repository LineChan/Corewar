.name		"bigfoui2"
.comment	"meaw is reback"

l_0:
	ld		%1, r6
	sti		r1, %:l_14, r6
	fork	%:l_1
	fork	%:l_2

l_7:
	live	%:l_7
	ld		%-198, r8
	st		r1, r15
	fork	%:l_3
	fork	%:l_4
	ld		%150994945, r15
	ld		%0, r2
	ld		%0, r16
	zjmp	%:l_5

l_4:
	ld		%:l_4, r16
	ld		%4, r2
	ld		%0, r16
	zjmp	%:l_5

l_3:
	fork	%:l_6
	ld		%190058248, r15
	ld		%8, r2
	ld		%0, r16
	zjmp	%:l_5

l_6:
	ld		%34209592, r15
	ld		%12, r2
	ld		%0, r16
	zjmp	%:l_5

l_5:
	live	%:l_5
	fork	%:l_7
	sti		r15, r8, r2
	zjmp	%-200

l_1:
	live	%:l_1
	ld		%-68, r8
	st		r1, r15
	fork	%:l_8
	fork	%:l_9
	ld		%150994945, r15
	ld		%0, r2
	ld		%0, r16
	zjmp	%:l_10

l_9:
	ld		%:l_9, r16
	ld		%4, r2
	ld		%0, r16
	zjmp	%:l_10

l_8:
	fork	%:l_11
	ld		%190058248, r15
	ld		%8, r2
	ld		%0, r16
	zjmp	%:l_10

l_11:
	ld		%34209722, r15
	ld		%12, r2
	ld		%0, r16
	zjmp	%:l_10

l_10:
	live	%:l_10
	fork	%:l_10
	sti		r15, r8, r2
	zjmp	%-70

l_2:
	live	%:l_2
	ld		%127, r8
	st		r1, r15
	fork	%:l_12
	fork	%:l_13
	ld		%150994945, r15
	ld		%0, r2
	ld		%0, r16
	zjmp	%:l_14

l_13:
	ld		%:l_13, r16
	ld		%4, r2
	ld		%0, r16
	zjmp	%:l_14

l_12:
	fork	%:l_15
	ld		%190058248, r15
	ld		%8, r2
	ld		%0, r16
	zjmp	%:l_14

l_15:
	ld		%34144381, r15
	ld		%12, r2
	ld		%0, r16
	zjmp	%:l_14

l_14:
	live	%:l_14
	fork	%:l_2
	sti		r15, r8, r2
	zjmp	%125

; generated ;