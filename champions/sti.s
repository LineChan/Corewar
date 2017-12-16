.name "sti"
.comment "Take a registry and 2 indexes (potentially registries), add the two indexes and use this result as an address where the value of the first parameter will be copied."

sti r3, 4095, %0
sti r1, %4000, %94
sti r1, %4093, r6
sti r1, %-764, r6
sti r2, r2, %4092
sti r3, 4095, r6
sti r3, -200, r6
sti r3, r1, r5
