.name		"Sunday"
.comment	"Bloody Sunday"

l_0:
	ld		%:l_0, r9
	zjmp	%:l_1

l_2:
	st		r1, 6
	live	%0
	fork	%:l_2
	fork	%:l_3
	live	%0
	fork	%:l_4

l_4:
	fork	%-10
	live	%0
	fork	%:l_5
	ld		%0, r9
	zjmp	%:l_3

l_5:
	ld		%:l_5, r2
	st		r1, 6

l_6:
	live	%:l_6
	zjmp	%:l_6

l_1:
	sti		r1, %:l_10, %1
	st		r1, 6

l_3:
	live	%:l_3
	sti		r2, %200, r4
	fork	%:l_7
	fork	%:l_8
	ld		-17, r2
	ldi		%:l_3, %4, r3
	ld		%0, r4
	ld		%0, r7
	ld		%0, r7
	live	%0
	fork	%:l_9
	zjmp	%:l_10

l_7:
	fork	%:l_2
	ld		%8, r4
	ld		%16778251, r2
	ld		%1677918462, r3

l_11:
	ldi		%:l_3, %-20, r5
	ld		%0, r6
	live	%0
	fork	%:l_9
	zjmp	%:l_10

l_8:
	ld		%16, r4
	ld		%:l_3, r2
	ldi		%:l_3, %1, r5
	ld		%0, r3
	ld		%0, r7
	live	%0
	fork	%:l_9
	zjmp	%:l_10

l_10:
	live	%:l_10
	sti		r2, %256, r4
	sti		r3, %254, r4
	fork	%:l_3
	ld		%0, r9
	zjmp	%:l_11

l_9:
	sti		r2, %128, r4
	sti		r3, %126, r4
	fork	%:l_3
	ld		%0, r9
	zjmp	%120

; generated ;