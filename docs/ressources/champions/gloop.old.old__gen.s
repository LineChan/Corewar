.name		"Je veux mourrir!"
.comment	"No comment"

l_0:
	sti		r1, %:l_1, %1
	sti		r1, %:l_2, %1
	sti		r1, %:l_3, %1
	sti		r1, %:l_4, %1
	sti		r1, %372, %1
	fork	%:l_1

l_1:
	live	%1
	and		%0, %0, r4
	fork	%:l_2
	fork	%:l_3
	zjmp	%:l_1

l_3:
	live	%1
	st		r1, 450
	st		r1, 449
	st		r1, 448
	st		r1, 447
	st		r1, 446
	st		r1, 445
	st		r1, 444
	st		r1, 443
	st		r1, 442
	st		r1, 441
	st		r1, 440
	st		r1, 439
	st		r1, 438
	st		r1, 437
	st		r1, 436
	st		r1, 435
	st		r1, 434
	st		r1, 433
	st		r1, 432
	st		r1, 431
	st		r1, 430
	st		r1, 429
	st		r1, 426
	st		r1, 425
	st		r1, 424
	st		r1, 423
	st		r1, 423
	st		r1, 421
	st		r1, 420
	fork	%:l_3

l_2:
	live	%1
	st		r1, -400
	st		r1, -409
	st		r1, -418
	st		r1, -427
	st		r1, -436
	st		r1, -445
	st		r1, -454
	st		r1, -463
	st		r1, -472
	st		r1, -481
	st		r1, -490
	st		r1, -499
	st		r1, -508
	st		r1, -517
	st		r1, -526
	st		r1, -535
	st		r1, -544
	st		r1, -553
	st		r1, -562
	st		r1, -571
	st		r1, -580
	st		r1, -589
	st		r1, -598
	st		r1, -607
	st		r1, -616
	st		r1, -625
	st		r1, -634
	st		r1, -643
	st		r1, -652
	st		r1, -661
	st		r1, -670
	st		r1, -679
	st		r1, -688
	fork	%:l_2

l_4:
	live	%1
	fork	%:l_3
	zjmp	%:l_4
	live	%1
	fork	%:l_1
	zjmp	%:l_4

l_5:
	live	%1
	st		r1, -400
	st		r1, -409
	st		r1, -418
	st		r1, -427
	st		r1, -436
	st		r1, -445
	st		r1, -454
	st		r1, -463
	st		r1, -472
	zjmp	%:l_5

; generated ;