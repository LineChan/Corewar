.name		"alaric"
.comment	"bof mais bon...."

l_0:
	fork	%:l_1
	sti		r1, %:l_2, %1
	sti		r1, %55, %1
	sti		r1, %78, %1
	sti		r1, %111, %1
	sti		r1, %239, %1

l_2:
	live	%:l_2
	fork	%:l_1
	and		r5, %0, r5
	fork	%:l_1
	zjmp	%:l_2

l_1:
	st		r2, 290
	live	%0
	st		r2, 300
	st		r2, 305
	st		r2, 310
	st		r2, 315
	st		r2, 320
	live	%0
	st		r2, 325
	st		r2, 330
	st		r2, 335
	st		r2, 340
	st		r2, 345
	st		r2, 350
	st		r2, 355
	live	%0
	st		r2, 360
	st		r2, 365
	st		r2, 370
	st		r2, 375
	st		r2, 380
	st		r2, 385
	st		r2, 390
	st		r2, 395
	st		r2, 400
	st		r2, 405
	st		r2, 410
	st		r2, 415
	st		r2, 420
	st		r2, 425
	st		r2, 430
	st		r2, 435
	st		r2, 440
	st		r2, 445
	st		r2, 450
	st		r2, 455
	st		r2, 460
	st		r2, 465
	st		r2, 470
	st		r2, 475
	st		r2, 480
	st		r2, 485
	live	%0
	st		r2, 490
	st		r2, 495
	st		r2, 497
	st		r2, 498
	st		r2, 499
	st		r2, 500
	st		r2, 505
	st		r2, 510
	st		r2, 511
	and		r3, %0, r3
	zjmp	%:l_1

; generated ;