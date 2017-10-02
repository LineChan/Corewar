.name		"Sapuntu"
.comment	"busina_b n'ayant pas d'imagination, il n'y a pas de commentaire"

l_0:
	fork	%2342

l_2:
	ld		%200, r5
	ld		%1, r4
	sti		r1, %19, %1

l_1:
	st		r5, r3
	sub		r3, r4, r5
	zjmp	%:l_1
	live	%-1
	xor		r1, r1, r1
	zjmp	%:l_2

; generated ;