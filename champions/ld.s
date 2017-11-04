.name "ld"
.comment "Take a random argument and a registry. Load the value of the first argument in the registry. It will change the carry."

sti     r1, %4095, %0
ld		%4095, r1
