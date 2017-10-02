.name		"yakouza"
.comment	"born to win"

l_0:
	sti		r1, %236, %16
	sti		r1, %229, %21
	sti		r1, %222, %26
	sti		r1, %215, %31
	sti		r1, %208, %36
	sti		r1, %201, %41
	sti		r1, %194, %46
	sti		r1, %187, %51
	sti		r1, %180, %56
	sti		r1, %173, %61
	sti		r1, %166, %66
	sti		r1, %159, %71
	sti		r1, %152, %76
	sti		r1, %145, %81
	sti		r1, %138, %86
	sti		r1, %131, %91
	sti		r1, %124, %96
	sti		r1, %117, %101
	sti		r1, %110, %106
	sti		r1, %103, %111
	sti		r1, %96, %116
	ld		%48, r14
	ld		%4, r4
	ld		%48, r6
	ld		%48, r13
	ld		%330, r9
	fork	%:l_0
	add		r8, r9, r8
	sub		r12, r8, r12
	st		r1, 13
	ld		%4, r3
	live	%1
	ld		%-40, r2

l_1:
	ldi		%:l_0, r2, r4
	sti		r4, %-78, r2
	add		r2, r3, r2
	zjmp	%-129
	xor		r4, r4, r4
	zjmp	%:l_1

; generated ;