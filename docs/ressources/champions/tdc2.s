.name 		"dtonc v1.0pl2"
.comment	"ta mere elle fait du rodeo sur les kfar"
	
begin:
ld1:	
	ld	%15, r3 	
	ld	%195, r4	
	ld	%0, r7		
	ld	%589824, r8	
liver1:
	live	%1
	fork	%:liver1
	ld	%0, r5
	fork	%:liver2
	live	%1
	fork	%:boucle
	live	%1
	fork	%:rboucle
	zjmp	%:liver1
	
liver2:	
	live	%1
	zjmp	%:liver2

boucle:	
	live	%1
	fork	%:boucle
no:
	live	%1
	sti	r8, %:end, r2
	add	r2, r3, r2
	sub	r4, r2, r5	
	zjmp	%:boucle2
	ld	%0, r5
	zjmp	%:no
	
boucle2:
	ld	%0, r2
	zjmp	%:no




	
rboucle:
	live	%1
	fork	%:rboucle
rno:
	live	%1
	sti	r7, %:begin ,r2
	sub	r2, r3, r2
	add	r4, r2, r5	
	zjmp	%:rboucle2
	ld	%0, r5
	zjmp	%:rno

rboucle2:
	ld	%0, r2
	zjmp	%:rno
	
toto:	
	live	%0
	xor 	r1, r1, r5
	zjmp	%:toto


end:	
	xor r1, r1, r1
	











