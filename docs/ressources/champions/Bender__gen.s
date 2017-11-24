.name		"bender"
.comment	"Bending Unit No 42"

l_0:
	sti		r1, %:l_1, %1
	sti		r1, %:l_2, %1
	sti		r1, %:l_3, %1
	sti		r1, %:l_3, %6
	or		r2, r2, r2
	fork	%:l_1
	fork	%:l_2

l_3:
	live	%1
	live	%1
	zjmp	%:l_3

l_1:
	live	%1
	sti		r1, %:l_3, %-140
	sti		r1, %:l_3, %-141
	sti		r1, %:l_3, %-142
	sti		r1, %:l_3, %-143
	sti		r1, %:l_3, %-144
	sti		r1, %:l_3, %-145
	sti		r1, %:l_3, %-146
	sti		r1, %:l_3, %-147
	sti		r1, %:l_3, %-148
	sti		r1, %:l_3, %-149
	sti		r1, %:l_3, %-150
	sti		r1, %:l_3, %-152
	sti		r1, %:l_3, %-153
	zjmp	%:l_1

l_2:
	live	%1
	sti		r1, %:l_3, %-140
	sti		r1, %:l_3, %-141
	sti		r1, %:l_3, %-142
	sti		r1, %:l_3, %-143
	sti		r1, %:l_3, %-144
	sti		r1, %:l_3, %-145
	sti		r1, %:l_3, %:l_1
	sti		r1, %:l_3, %-147
	sti		r1, %:l_3, %-148
	sti		r1, %:l_3, %-149
	sti		r1, %:l_3, %-150
	sti		r1, %:l_3, %-152
	sti		r1, %:l_3, %-153
	zjmp	%:l_2

; generated ;