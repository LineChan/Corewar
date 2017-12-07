.name "sti IND"
.comment "Take a registry and 2 indexes (potentially registries), add the two indexes and use this result as an address where the value of the first parameter will be copied."

sti r1, 300, %600
sti r1, 9000, %100
sti r1, -400, %500
sti r1, -30, %-30
