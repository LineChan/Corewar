.name "xor"
.comment "Apply an ^ (bit-to-bit XOR) over the first two arguments and store the result in a registry, which is the third argument. It will change the carry."

xor 4095, r1, r2
xor r0, r1, r1
xor r1, r0, r1
