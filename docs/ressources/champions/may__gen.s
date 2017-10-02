.name		"might survive a bit"
.comment	"just a very very basic living prog"

l_0:
	st		r1, 81
	st		r1, 60
	st		r1, 90
	st		r1, 58
	st		r1, 21
	st		r1, 67
	ld		61, r8
	ld		60, r9

l_2:
	live	%77
	and		r1, %0, r2
	fork	%:l_1
	live	%77
	fork	%:l_2

l_3:
	live	%77
	fork	%:l_1
	live	%77
	fork	%:l_1
	live	%77
	fork	%434
	zjmp	%:l_3

l_4:
	live	%77
	zjmp	%:l_4

l_1:
	live	%77
	st		r8, 400
	st		r9, 399
	st		r8, 398
	st		r9, 397
	st		r8, 396
	st		r9, 395
	st		r8, 394
	st		r9, 393
	st		r8, 392
	st		r9, 391
	st		r8, 390
	st		r9, 389
	st		r8, 388
	st		r9, 387
	st		r8, 386
	st		r9, 385
	st		r8, 384
	st		r9, 383
	st		r8, 382
	st		r9, 381
	st		r8, 380
	st		r9, 379
	st		r8, 378
	st		r9, 377
	st		r8, 376
	st		r9, 375
	st		r8, 374
	st		r9, 373
	st		r8, 372
	st		r9, 371
	st		r8, 370
	st		r9, 369
	st		r8, 368
	st		r9, 367
	st		r8, 366
	st		r9, 365
	st		r8, 364
	st		r9, 363
	st		r8, 362
	st		r9, 361
	zjmp	%:l_1

; generated ;