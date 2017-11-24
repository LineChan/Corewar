.name		"Sida"
.comment	"Sortez couvert !"

l_0:
	ld		%1, r2
	ld		%167770880, r3
	ld		%42, r5

l_13:
	st		r1, 6
	live	%42
	fork	%:l_1
	live	%42
	fork	%:l_2

l_1:
	st		r1, 6
	live	%42
	fork	%:l_3
	st		r1, 6
	live	%42
	fork	%:l_4
	live	%42
	fork	%:l_1
	ld		%0, r15
	zjmp	%:l_5

l_3:
	live	%42
	st		r1, 14
	st		r1, 14

l_6:
	live	%42
	live	%42
	zjmp	%:l_6

l_4:
	st		r1, 6
	live	%42
	ld		%0, r15
	zjmp	%-5

l_5:
	st		r1, 6

l_7:
	live	%42
	zjmp	%:l_7

l_2:
	st		r1, 6
	live	%42
	fork	%:l_8
	live	%42
	live	%42
	sti		r2, %300, %0
	sti		r1, %297, %0
	sti		r3, %294, %0
	live	%42
	fork	%282
	ld		%0, r15
	zjmp	%:l_2

l_8:
	live	%42
	sti		r2, %-300, %0
	sti		r1, %-297, %0
	sti		r3, %-294, %0
	live	%42
	fork	%-282
	ld		%0, r15
	zjmp	%:l_8

l_10:
	live	%42
	fork	%:l_9
	live	%42
	fork	%:l_10
	live	%42
	fork	%:l_10
	live	%42
	ld		%0, r15
	zjmp	%:l_10

l_9:
	st		r1, 6
	live	%42
	fork	%:l_11
	live	%42
	fork	%:l_10
	live	%42
	ld		%0, r15
	zjmp	%:l_2

l_11:
	st		r1, 6
	live	%42
	fork	%:l_12
	live	%42
	fork	%:l_10
	live	%42
	ld		%0, r15
	zjmp	%:l_5

l_12:
	st		r1, 6
	live	%42
	fork	%:l_10
	live	%42
	fork	%:l_8
	live	%42
	zjmp	%:l_13

; generated ;