.name "or"
.comment "Apply an | (bit-to-bit OR) over the first two arguments or store the result in a registry, which is the third argument. It will change the carry."

or r3, %0, r2
st r2, 0
or 4080, r1, r3
st r3, 0
or r3, -32, r4
st r4, 0
or %4080, r1, r5
st r5, 0
or r2, %-920, r6
st r6, 0
or 758, %80, r7
st r7, 0
or %-093, %504, r8
st r8, 0
or %7000000, %-20, r9
st r9, 0

or r2, 4096, r4
or r2, 4096, r5
or r2, 4096, r6
or r2, 4095, r7
or r2, 4094, r8
or r2, 4093, r9
or r2, 4096, r10
or r1, -300, r11
or r1, %-300, r12
or 4095, r2, r4
or 4095, r2, r5
or 4095, r2, r6
or 4095, r2, r7
or 4094, r2, r8
or 4093, r2, r9
or 4096, r2, r10
or 4096, r2, r11
or 4095, r2, r12
or -150, r3, r13
or %-200, 600, r14
or 10, 10, r15
or 0, r16, r16
or r16, 50, r1
or r17, 40, r1
or r1, %4096, r2
or r2, -30, r3
or r4, -40, r1
or %4093, 0, r5
or -10000, 50, r1
or 90, r3, r1
