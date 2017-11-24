.name		"Baton de surimi (selon Gonzo)"
.comment	"Gonzo le matin, l'est pas fin"

l_0:
	sti		r1, %:l_10, %1
	sti		r1, %:l_11, %1
	sti		r1, %:l_9, %1
	st		r1, 16
	ld		%0, r15
	zjmp	%:l_1

l_8:
	live	%666
	ld		%-100, r5
	fork	%:l_2
	ld		41, r4

l_6:
	ld		%:l_6, r14
	ld		%0, r2
	zjmp	%:l_3

l_2:
	ld		23, r4
	ld		%4, r14
	ld		%0, r2

l_3:
	sti		r4, r5, r14
	zjmp	%-105

l_10:
	live	%666
	ld		%-100, r5
	fork	%:l_4
	ld		41, r4
	ld		%0, r14
	ld		%0, r2
	zjmp	%:l_5

l_4:
	ld		23, r4
	ld		%4, r14
	ld		%0, r2

l_5:
	sti		r4, r5, r14
	zjmp	%:l_6

l_13:
	sti		r1, %:l_7, %1
	and		r1, %0, r1

l_7:
	live	%666
	zjmp	%:l_7

l_1:
	fork	%:l_8
	st		r1, 39
	st		r1, 42
	st		r1, 45
	st		r1, 48
	st		r1, 51
	st		r1, 54
	st		r1, 57

l_12:
	fork	%:l_8
	live	%666
	fork	%:l_9
	live	%666
	fork	%:l_10
	live	%666
	fork	%:l_11
	live	%666
	fork	%:l_8
	live	%666
	fork	%:l_12
	live	%666
	fork	%:l_13
	live	%666
	fork	%:l_14
	zjmp	%:l_12

l_14:
	sti		r1, %-51, %1
	and		r1, %0, r1

l_15:
	live	%:l_3
	zjmp	%:l_15

l_11:
	live	%:l_10
	ld		%100, r5
	fork	%:l_16
	ld		41, r4
	ld		%0, r14
	ld		%0, r2
	zjmp	%:l_17

l_16:
	ld		23, r4
	ld		%4, r14
	ld		%0, r2

l_17:
	sti		r4, r5, r14
	zjmp	%95

l_9:
	live	%:l_13
	ld		%100, r5
	fork	%:l_18
	ld		41, r4
	ld		%0, r14
	ld		%0, r2
	zjmp	%:l_19

l_18:
	ld		23, r4
	ld		%4, r14
	ld		%0, r2

l_19:
	sti		r4, r5, r14
	zjmp	%:l_3

; generated ;