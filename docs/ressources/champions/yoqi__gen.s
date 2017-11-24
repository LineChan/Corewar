.name		"yoqi"
.comment	"beuop beuop"

l_0:
	ld		%290, r5
	sti		r1, %:l_6, %1
	sti		r1, %:l_11, %1
	ld		0, r15
	ld		202, r15
	or		r1, r15, r1
	st		r1, 192

l_7:
	live	%42
	fork	%:l_1
	live	%42
	fork	%:l_2
	live	%42
	fork	%:l_3
	live	%42
	fork	%:l_3
	live	%42
	fork	%:l_4
	live	%42
	ld		%190054661, r1
	ld		%12, r3
	xor		r16, r16, r16
	zjmp	%:l_5

l_6:
	live	%1
	xor		r16, r16, r16
	zjmp	%:l_6

l_4:
	live	%777
	fork	%:l_4
	fork	%:l_7
	xor		r16, r16, r16
	zjmp	%:l_7

l_2:
	live	%42
	fork	%:l_8
	live	%42
	fork	%:l_3
	live	%42
	fork	%:l_3
	live	%42
	fork	%:l_1
	live	%42
	ld		%50397184, r1
	ld		%16, r3
	xor		r16, r16, r16
	zjmp	%:l_5

l_8:
	live	%42
	fork	%:l_9
	live	%42
	fork	%:l_3
	live	%42
	fork	%:l_1
	live	%42
	ld		%2305, r1
	ld		%20, r3
	xor		r16, r16, r16
	zjmp	%:l_5

l_9:
	live	%42
	fork	%:l_3
	live	%42
	fork	%:l_1
	live	%42
	ld		%570425344, r1
	ld		%24, r3
	xor		r16, r16, r16
	zjmp	%:l_5

l_3:
	xor		r16, r16, r16
	zjmp	%:l_7

l_5:
	sti		r1, r5, r3
	live	%:l_11
	zjmp	%290

l_1:
	live	%42
	xor		r16, r16, r16
	fork	%:l_10
	live	%42
	zjmp	%:l_6

l_10:
	live	%42
	xor		r16, r16, r16
	zjmp	%:l_11

l_11:
	live	%1
	xor		r16, r16, r16
	zjmp	%:l_11

; generated ;