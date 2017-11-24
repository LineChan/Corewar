.name		"Jeanne Calment"
.comment	"Jean Machline & Romain Morau-Gobard presentent..."

l_0:
	sti		r1, %:l_2, %1
	sti		r1, %149, %1
	sti		r1, %147, %1
	sti		r1, %145, %1
	sti		r1, %143, %1
	sti		r1, %141, %1
	sti		r1, %139, %1
	sti		r1, %137, %1
	sti		r1, %135, %1
	sti		r1, %133, %1
	sti		r1, %131, %1
	sti		r1, %129, %1
	sti		r1, %127, %1
	sti		r1, %125, %1
	sti		r1, %123, %1
	sti		r1, %121, %1
	sti		r1, %119, %1
	sti		r1, %117, %1
	sti		r1, %115, %1
	sti		r1, %:l_1, %1
	fork	%:l_1
	and		r2, %0, r2

l_2:
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

l_1:
	live	%1
	zjmp	%:l_2

; generated ;