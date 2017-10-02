.name		"bigfoui"
.comment	"meaw is back"

l_0:
	ld		%1, r6
	sti		r1, %:l_13, r6
	fork	%:l_1
	fork	%:l_2
	live	%0
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
	fork	%:l_5
	sti		r15, r8, r2
	zjmp	%-200

l_1:
	live	%:l_1
	ld		%-68, r8
	st		r1, r15
	fork	%:l_7
	fork	%:l_8
	ld		%150994945, r15
	ld		%0, r2
	ld		%0, r16
	zjmp	%:l_9

l_8:
	ld		%:l_8, r16
	ld		%4, r2
	ld		%0, r16
	zjmp	%:l_9

l_7:
	fork	%:l_10
	ld		%190058248, r15
	ld		%8, r2
	ld		%0, r16
	zjmp	%:l_9

l_10:
	ld		%34209722, r15
	ld		%12, r2
	ld		%0, r16
	zjmp	%:l_9

l_9:
	live	%:l_9
	fork	%:l_9
	sti		r15, r8, r2
	zjmp	%-70

l_2:
	live	%:l_2
	ld		%127, r8
	st		r1, r15
	fork	%:l_11
	fork	%:l_12
	ld		%150994945, r15
	ld		%0, r2
	ld		%0, r16
	zjmp	%:l_13

l_12:
	ld		%:l_12, r16
	ld		%4, r2
	ld		%0, r16
	zjmp	%:l_13

l_11:
	fork	%:l_14
	ld		%190058248, r15
	ld		%8, r2
	ld		%0, r16
	zjmp	%:l_13

l_14:
	ld		%34144381, r15
	ld		%12, r2
	ld		%0, r16
	zjmp	%:l_13

l_13:
	live	%:l_13
	fork	%:l_13
	sti		r15, r8, r2
	zjmp	%125

; generated ;