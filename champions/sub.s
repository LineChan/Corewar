.name "sub"
.comment "Take three registries, substract the first two, or place the result in the third, right before modifying the carry"

or r1, r1, r2
or 4080, r1, r3
or r3, -32, r4
or %4080, r1, r5
or r2, %-920, r6
or 758, %80, r7
or %-093, %504, r8
or %7000000, %-20, r9
