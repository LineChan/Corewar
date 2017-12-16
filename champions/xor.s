.name "xor"
.comment "Apply an ^ (bit-to-bit XOR) over the first two arguments and store the result in a registry, which is the third argument. It will change the carry."

xor r3, %0, r2
st r2, 0
xor 4080, r1, r3
st r3, 0
xor r3, -32, r4
st r4, 0
xor %4080, r1, r5
st r5, 0
xor r2, %-920, r6
st r6, 0
xor 758, %80, r7
st r7, 0
xor %-093, %504, r8
st r8, 0
xor %7000000, %-20, r9
st r9, 0
xor r0, 0, r1
xor r17, r1, r1
xor 4095, r1, r2
xor r1, 4095, r2
xor r1, -300, r1
xor r1, %-300, r2
xor -150, r3, r1
xor %-200, 600, r2
xor 10, 10, r10
