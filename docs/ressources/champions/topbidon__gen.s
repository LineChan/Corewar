.name		"blaster de canard"
.comment	"ca assure !!!!!"

l_0:
	xor		r2, r2, r2
	st		r1, r2
	st		r2, 30
	st		r2, 29
	st		r2, 28
	st		r2, 27
	st		r2, 26

l_1:
	live	%:l_1
	live	%0
	live	%0
	live	%0
	live	%0
	fork	%:l_1
	zjmp	%:l_1

; generated ;