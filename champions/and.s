.name "and"
.comment "Apply an & (bit-to-bit AND) over the first two arguments and stande the result in a registry, which is the third argument. It will change the carry"

and r3, %0, r2
st r2, 0
and 4080, r1, r3
st r3, 0
and r3, -32, r4
st r4, 0
and %4080, r1, r5
st r5, 0
and r2, %-920, r6
st r6, 0
and 758, %80, r7
st r7, 0
and %-093, %504, r8
st r8, 0
and %7000000, %-20, r9
st r9, 0
