.name "and"
.comment "Apply an & (bit-to-bit AND) over the first two arguments and store the result in a registry, which is the third argument. It will change the carry"

and r0, r0, r1
and r1, r1, r2
and r1, r3, r1
