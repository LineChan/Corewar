.name "sub"
.comment "Take three registries, substract the first two, and place the result in the third, right before modifying the carry"

sub r0, r1, r1
sub r1, r2, r2
sub r1, r1, r2

sub r0, r1, r3
sub r0, r3, r1
sub r1, r0, r2
sub r0, r1, r3
sub r3, r2, r4


sub r1, r2, r3
sub r1, r1, r2
sub r10, r15, r1
sub r16, r17, r2
sub r1, r3, r4
