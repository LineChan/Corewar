.name "or"
.comment "pply an | (bit-to-bit OR) over the first two arguments and store the result in a registry, which is the third argument. It will change the carry."

or r0, r1, r1
or r1, r2, r2
or r2, r2, r3
or r4, r4, r1
