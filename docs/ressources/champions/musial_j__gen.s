.name		"enda"
.comment	"Owned! or not..."

l_0:
	ld		%:l_0, r3
	zjmp	%10
	zjmp	%0

l_4:
	live	%77
	sti		r4, %0, r5
	zjmp	%-200
	live	%77
	fork	%-30
	sti		r4, %0, r5
	zjmp	%-200
	live	%77
	fork	%-30
	sti		r4, %0, r5
	zjmp	%:l_1
	live	%77
	fork	%-30
	sti		r4, %0, r5
	zjmp	%-200
	live	%77
	fork	%-30
	sti		r4, %0, r5
	zjmp	%-200
	live	%77
	fork	%-30
	sti		r4, %0, r5
	zjmp	%-200
	live	%77
	fork	%-30
	sti		r4, %0, r5
	zjmp	%:l_2
	sti		r1, %12345, %1
	sti		r1, %-124, %15
	sti		r1, %32486, %15
	sti		r1, %19782, %29
	sti		r1, %20545, %43
	sti		r1, %-16636, %57
	sti		r1, %1500, %71
	ld		%11223344, r6
	ld		%22233344, r7

l_1:
	live	%77
	live	%77
	live	%77
	live	%77
	live	%77
	zjmp	%-50
	fork	%-30
	live	%3
	fork	%:l_3
	live	%4
	fork	%75
	live	%77
	live	%3
	fork	%:l_4
	live	%4
	fork	%75

l_2:
	live	%77
	live	%3
	fork	%50
	live	%4

l_3:
	fork	%75
	live	%77

; generated ;