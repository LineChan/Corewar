.name "xor"
.comment "Apply an ^ (bit-to-bit XOR) over the first two arguments and store the result in a registry, which is the third argument. It will change the carry."

xor r0, 0, r1
xor r17, r1, r1
xor 4095, r1, r2
xor r1, 4095, r2
xor r1, -300, r1
xor r1, %-300, r2
xor -150, r3, r1
xor %-200, 600, r2
xor 10, 10, r10
