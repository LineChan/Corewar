.name		"Shake : we can win..."
.comment	":o)"

l_0:
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	fork	%:l_0
	live	%1

l_1:
	st		r8, -400
	st		r8, -900
	live	%1
	st		r8, -400
	st		r8, -400
	live	%1
	st		r8, -400
	st		r8, -400
	live	%1
	st		r8, -400
	st		r8, -400
	live	%1
	st		r8, -400
	st		r8, -400
	live	%1
	st		r8, -400
	st		r8, -400
	live	%1
	st		r8, -400
	st		r8, -400
	live	%1
	st		r8, -400
	st		r8, -400
	live	%1
	st		r8, -400
	st		r8, -400
	live	%1
	st		r8, -400
	st		r8, -400
	live	%1
	st		r8, -400
	st		r8, -400
	live	%1
	st		r8, -400
	st		r8, -400
	live	%1
	st		r8, -400
	st		r8, -400
	live	%1
	st		r8, -400
	st		r8, -400
	live	%1
	st		r8, -400
	st		r8, -400
	live	%1
	ld		%0, r15
	zjmp	%:l_1

; generated ;