.name "sub"
.comment "Take three registries, substract the first two, and place the result in the third, right before modifying the carry"

sub r0, r1, r1
sub r1, r2, r2
sub r1, r1, r2
