.name		"Long comment"
.comment	"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean id justo et est vestibulum ultrices vel a arcu. Nulla ligula nibh, imperdiet quis luctus in, commodo in dui. Donec tincidunt mi fermentum commodo aliquam. Integer quis turpis sit amet sapien consectetur pretium a eget turpis. Nullam faucibus, elit eget aliquet consectetur, ante felis egestas lacus, sit amet imperdiet lorem urna et leo. Curabitur porta fringilla sollicitudin. Nunc enim justo, aliquam vitae elit nec, fringilla mollis lorem. In quis justo libero.

Fusce volutpat tempor dolor, quis ultricies tellus mollis at. Praesent in aliquam dolor, eget hendrerit orci. Nulla et risus pharetra, dapibus felis sit amet, vulputate est. Cras lacinia facilisis turpis tincidunt venenatis. Proin molestie eleifend porttitor. Sed volutpat posuere lorem. Aenean aliquet porttitor sem, nec blandit tellus feugiat eu.

Donec lobortis eros tortor, sit amet hendrerit elit sodales non. Mauris finibus tortor ac dolor dictum mattis. Nulla sit amet sapien pellentesque, dictum sem a, ultrices massa. Ut dapibus ante ac dui pretium fermentum. Quisque vel mauris nec erat congue consectetur. Cras condimentum consequat vulputate. Nulla vitae lectus fringilla, commodo tellus ut, facilisis nunc. Donec maximus posuere dui vel consectetur.

In luctus tortor nec magna interdum dignissim. Quisque hendrerit rutrum ante, vitae iaculis leo faucibus sed. Fusce vitae tristique purus, quis bibendum sem. Nunc in turpis vitae libero gravida dictum. Donec quis nibh et dolor cursus pharetra. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Cras nisl nisl, gravida sed facilisis vitae, tempor et velit. Integer nec lectus eu felis eleifend porta.

Sed vel ipsum non mi venenatis volutpat sit amet id massa. Curabitur malesuada elit tortor, id suscipit tortor pretium vel. Ut sodales lorem sit amet nulla hendrerit, vel interdum ipsum vulputate. Nulla fringilla libero at turpis ullamcorper molestie. Vestibulum facilisis nunc eleifend ullamcorper finibus. Proin sodales eros vel pulvinar accumsa"
l_0:
	sti		r1, %140, %1
	fork	%:l_1
	fork	%:l_2
	ld		%0, r4
	ld		%-471, r3
	ldi		%105, %0, r2
	xor		r16, r16, r16
	zjmp	%:l_3

l_2:
	ld		%4, r4
	ld		%-471, r3
	ldi		%:l_3, %1, r2
	xor		r16, r16, r16
	zjmp	%:l_3

l_1:
	fork	%:l_4
	ld		%8, r4
	ld		%-471, r3
	ldi		%52, %0, r2
	xor		r16, r16, r16
	zjmp	%:l_3

l_4:
	ld		%12, r4
	ld		%-471, r3
	ldi		%23, %4, r2
	xor		r16, r16, r16
	zjmp	%:l_3
	zjmp	%0

l_3:
	sti		r2, r3, r4
	live	%1
	zjmp	%-479

; generated ;
