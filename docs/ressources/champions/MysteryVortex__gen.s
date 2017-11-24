.name		"Mystery Vortex"
.comment	"youpiyoupi!"

l_0:
	ld		%-494, r8
	fork	%:l_1
	live	%0
	fork	%:l_2
	fork	%:l_3
	ld		%0, r15
	ld		%0, r2
	ld		%0, r16
	zjmp	%:l_4

l_3:
	ld		%42991616, r15
	ld		%4, r2
	ld		%0, r16
	zjmp	%:l_4

l_2:
	fork	%:l_5
	ld		%257, r15
	ld		%8, r2
	ld		%0, r16
	zjmp	%:l_4

l_5:
	st		r1, r15
	ld		%12, r2
	ld		%0, r16
	zjmp	%:l_4

l_1:
	live	%:l_1
	fork	%:l_6
	fork	%:l_7
	ld		%167770881, r15
	ld		%16, r2
	ld		%0, r16
	zjmp	%:l_4

l_7:
	st		r1, r15
	ld		%20, r2
	ld		%0, r16
	zjmp	%:l_4

l_6:
	fork	%:l_8
	ld		%190058248, r15
	ld		%24, r2
	ld		%0, r16
	zjmp	%:l_4

l_8:
	ld		%34209311, r15
	ld		%28, r2
	ld		%0, r16
	zjmp	%:l_4

l_4:
	sti		r15, r2, r8
	zjmp	%-481

; generated ;