.name "sti"
.comment "Take a registry and 2 indexes (potentially registries), add the two indexes and use this result as an address where the value of the first parameter will be copied."

sti     r1, 0, %5
sti     r4, r4, r4
sti     r5, 120, %0
sti     r5, -90, %10
sti     r5, 100000, %-768
sti     r6, %4096, %0
sti     r7, 4096, %0
sti		r1, r2, r2
sti		r2, r2, r3
sti		r0, r1, r2
sti		r17, r1, r2
sti		r3, r3, r4
sti     r5, %0, %-1
sti     r2, %-41, %0
sti     r3, %132, %0

sti r3, 4095, %0
sti r1, %4000, %94
sti r1, %4093, r6
sti r1, %-764, r6
sti r2, r2, %4092
sti r3, 4095, r6
sti r3, -200, r6
sti r3, r1, r5
