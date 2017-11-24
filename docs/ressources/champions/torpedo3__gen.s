.name		"large torpedo"
.comment	"by Phil"

l_0:
	sti		r1, %:l_2, %1
	fork	%:l_1
	ld		%0, r2
	ldi		%:l_2, %0, r5
	ldi		%:l_2, %8, r6
	ldi		%:l_2, %16, r7
	ldi		%:l_2, %24, r8
	ldi		%:l_2, %32, r9
	ldi		%:l_2, %40, r10
	ldi		%:l_2, %48, r11
	ldi		%:l_2, %56, r12
	ldi		%:l_2, %64, r13
	ldi		%:l_2, %72, r14
	ldi		%:l_2, %80, r15
	and		r1, %0, r1
	zjmp	%:l_2

l_1:
	ld		%4, r2
	ldi		%:l_2, %4, r5
	ldi		%:l_2, %12, r6
	ldi		%:l_2, %20, r7
	ldi		%:l_2, %28, r8
	ldi		%:l_2, %36, r9
	ldi		%:l_2, %44, r10
	ldi		%:l_2, %52, r11
	ldi		%:l_2, %60, r12
	ldi		%:l_2, %68, r13
	ldi		%:l_2, %76, r14
	ldi		%:l_2, %84, r15
	and		r1, %0, r1
	zjmp	%:l_2

l_2:
	live	%42
	sti		r5, r2, %400
	sti		r6, r2, %402
	sti		r7, r2, %404
	sti		r8, r2, %406
	sti		r9, r2, %408
	sti		r10, r2, %410
	sti		r11, r2, %412
	sti		r12, r2, %414
	sti		r13, r2, %:l_1
	sti		r14, r2, %418
	sti		r15, r2, %420
	and		r1, %0, r1
	zjmp	%326

; generated ;