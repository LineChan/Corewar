.name "add"
.comment "Take three registries, add the first two, and place the result in the third, right before modifying the carry."

add r0, r1, r3
add r0, r3, r1
add r1, r0, r2
add r0, r1, r3
add r3, r2, r4
