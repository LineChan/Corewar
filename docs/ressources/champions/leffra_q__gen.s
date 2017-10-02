.name		"Baal"
.comment	"I'm the Lord of Destruction"

l_0:
	sti		r1, %7, %1
	live	%1
	add		r2, r2, r2
	fork	%:l_1
	sti		r1, %:l_2, %1
	sti		r1, %:l_1, %1
	sti		r1, %:l_3, %1
	sti		r1, %181, %1
	sti		r1, %179, %1
	sti		r1, %177, %1
	sti		r1, %175, %1
	sti		r1, %173, %1
	sti		r1, %171, %1
	sti		r1, %169, %1
	sti		r1, %167, %1
	sti		r1, %165, %1
	sti		r1, %163, %1
	sti		r1, %161, %1
	sti		r1, %159, %1
	sti		r1, %157, %1
	sti		r1, %155, %1
	sti		r1, %153, %1
	sti		r1, %151, %1
	sti		r1, %149, %1
	sti		r1, %147, %1
	sti		r1, %145, %1
	sti		r1, %143, %1
	sti		r1, %141, %1
	sti		r1, %139, %1
	sti		r1, %137, %1
	sti		r1, %135, %1

l_2:
	live	%1
	fork	%:l_2

l_3:
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	zjmp	%:l_3

l_1:
	live	%1
	fork	%:l_1
	zjmp	%:l_3

; generated ;