.name		"YoUrY >-`-'-<"
.comment	"Il est trop NUL ... Creve pourriture de communiste"

l_0:
	xor		r5, r5, r5
	zjmp	%:l_1

l_26:
	fork	%:l_2
	st		r1, 6

l_3:
	live	%1
	zjmp	%:l_3

l_2:
	st		r1, 6

l_4:
	live	%1
	zjmp	%:l_4

l_27:
	fork	%:l_5
	st		r1, 6

l_6:
	live	%1
	zjmp	%:l_6

l_5:
	st		r1, 6

l_7:
	live	%1
	zjmp	%:l_7

l_28:
	fork	%:l_8
	st		r1, 6

l_9:
	live	%1
	zjmp	%:l_9

l_8:
	st		r1, 6

l_10:
	live	%1
	zjmp	%:l_10

l_29:
	fork	%:l_11
	st		r1, 6

l_12:
	live	%1
	zjmp	%:l_12

l_11:
	st		r1, 6

l_13:
	live	%1
	zjmp	%:l_13

l_30:
	fork	%:l_14
	st		r1, 6

l_15:
	live	%1
	zjmp	%:l_15

l_14:
	st		r1, 6

l_16:
	live	%1
	zjmp	%:l_16

l_31:
	fork	%:l_17
	st		r1, 6

l_18:
	live	%1
	zjmp	%:l_18

l_17:
	st		r1, 6

l_19:
	live	%1
	zjmp	%:l_19

l_32:
	fork	%:l_20
	st		r1, 6

l_21:
	live	%1
	zjmp	%:l_21

l_20:
	st		r1, 6

l_22:
	live	%1
	zjmp	%:l_22

l_33:
	fork	%:l_23
	st		r1, 6

l_24:
	live	%1
	zjmp	%:l_24

l_23:
	st		r1, 6

l_25:
	live	%1
	zjmp	%:l_25

l_1:
	fork	%:l_26
	live	%1
	fork	%:l_27
	live	%1
	fork	%:l_28
	live	%1
	fork	%:l_29
	live	%1
	fork	%:l_30
	live	%1
	fork	%:l_31
	live	%1
	fork	%:l_32
	live	%1
	fork	%:l_33
	live	%1
	zjmp	%:l_1

; generated ;