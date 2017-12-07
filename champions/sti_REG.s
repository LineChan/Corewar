.name "sti REG"
.comment "Take a registry and 2 indexes (potentially registries), add the two indexes and use this result as an address where the value of the first parameter will be copied."

sti r1, %4095, %0
sti r1, %0, %0
sti r1, %3600, %94
sti r1, %4093, %4
sti r2, %0, %500
sti r1, %-300, %100
sti r1, %100, %-300
sti r3, r4, r5
sti r0, r4, r5
sti r16, r7, r8
sti r17, r1, r2
