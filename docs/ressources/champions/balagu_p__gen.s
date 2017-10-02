.name		"Le Canard"
.comment	"Coin coin !"

l_0:
	fork	%:l_1
	live	%0
	zjmp	%:l_0

l_1:
	fork	%:l_0
	live	%0
	zjmp	%:l_0

; generated ;