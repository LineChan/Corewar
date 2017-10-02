.name		"I'm alive from MOI"
.comment	"Papy fait de la resistance..."

l_0:
	sti		r1, %:l_2, %1
	sti		r1, %:l_6, %1
	sti		r1, %:l_4, %1
	sti		r1, %:l_12, %1
	sti		r1, %:l_10, %1
	sti		r1, %:l_16, %1
	sti		r1, %:l_19, %1
	sti		r1, %:l_20, %1
	sti		r1, %:l_17, %1
	sti		r1, %:l_8, %1
	sti		r1, %:l_1, %1
	sti		r1, %:l_18, %1
	sti		r1, %:l_13, %1
	sti		r1, %:l_9, %1
	sti		r1, %:l_7, %1
	sti		r1, %:l_5, %1
	sti		r1, %:l_11, %1
	sti		r1, %:l_14, %1
	sti		r1, %:l_15, %1
	sti		r1, %:l_3, %1
	and		r1, %0, r1
	zjmp	%:l_1

l_2:
	live	%1
	zjmp	%:l_2

l_1:
	live	%1
	fork	%:l_3
	live	%0
	fork	%:l_4
	zjmp	%:l_5

l_6:
	live	%1
	zjmp	%:l_6

l_18:
	live	%1
	fork	%:l_7
	live	%0
	fork	%:l_8
	zjmp	%:l_3

l_4:
	live	%1
	zjmp	%:l_4

l_13:
	live	%1
	fork	%:l_9
	live	%0
	fork	%:l_10
	zjmp	%:l_11

l_12:
	live	%1
	zjmp	%:l_12

l_9:
	live	%1
	fork	%:l_1
	live	%0
	fork	%:l_2
	zjmp	%:l_13

l_10:
	live	%1
	zjmp	%:l_10

l_7:
	live	%1
	fork	%:l_13
	live	%0
	fork	%:l_6
	zjmp	%:l_14

l_8:
	live	%1
	zjmp	%:l_8

l_3:
	live	%1
	fork	%:l_15
	live	%0
	fork	%:l_12
	zjmp	%:l_9

l_16:
	live	%1
	zjmp	%:l_16

l_5:
	live	%1
	fork	%:l_14
	live	%0
	fork	%:l_17
	zjmp	%:l_18

l_19:
	live	%1
	zjmp	%:l_19

l_11:
	live	%1
	fork	%:l_18
	live	%0
	fork	%:l_16
	zjmp	%:l_7

l_20:
	live	%1
	zjmp	%:l_20

l_14:
	live	%1
	fork	%:l_11
	live	%0
	fork	%:l_12
	zjmp	%:l_15

l_17:
	live	%1
	zjmp	%:l_17

l_15:
	live	%1
	fork	%:l_5
	live	%0
	fork	%:l_20
	zjmp	%:l_18

; generated ;