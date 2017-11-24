.name		"HA BON ?"
.comment	"?"

l_0:
	sti		r1, %:l_2, %1
	sti		r1, %:l_2, %6
	sti		r1, %:l_2, %11
	sti		r1, %:l_2, %16
	sti		r1, %:l_2, %21
	sti		r1, %:l_2, %26
	sti		r1, %:l_2, %31
	sti		r1, %:l_2, %36
	sti		r1, %:l_2, %41
	sti		r1, %:l_2, %46
	sti		r1, %:l_2, %51
	sti		r1, %:l_2, %56
	sti		r1, %:l_2, %61
	sti		r1, %:l_2, %66
	sti		r1, %:l_2, %71
	sti		r1, %:l_2, %76
	sti		r1, %:l_2, %81
	sti		r1, %:l_2, %86
	sti		r1, %:l_2, %91
	sti		r1, %:l_2, %96
	sti		r1, %:l_2, %101
	sti		r1, %:l_1, %1
	sti		r1, %:l_1, %6
	sti		r1, %:l_1, %11
	sti		r1, %:l_1, %16
	sti		r1, %:l_1, %21
	sti		r1, %:l_1, %26
	sti		r1, %:l_1, %31
	sti		r1, %:l_1, %36
	sti		r1, %:l_1, %41
	sti		r1, %:l_1, %46
	sti		r1, %:l_1, %51
	sti		r1, %:l_1, %56
	sti		r1, %:l_1, %61
	sti		r1, %:l_1, %66
	sti		r1, %:l_1, %71
	sti		r1, %:l_1, %76
	sti		r1, %:l_1, %81
	sti		r1, %:l_1, %86
	sti		r1, %:l_1, %91
	sti		r1, %:l_1, %96
	sti		r1, %:l_1, %101
	and		r1, %0, r1

l_2:
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%:l_1
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	fork	%:l_1
	zjmp	%:l_2

l_1:
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	live	%51
	zjmp	%:l_1

; generated ;