.name "ldi"
.comment "It use 2 indexes and 1 registry, adding the first two, treating that like an address, reading value of a registry's size and putting in the third."

ldi     %-41, %0, r2
ldi     %132, %0, r3
ldi     0, %120, r4
ldi     120, %0, r5
ldi     %4096, %0, r6
ldi     4096, %0, r7
