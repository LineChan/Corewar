#!/bin/sh
make -j;
[ -d "trash" ] && rm -rf "trash";
mkdir "trash" && cp -R docs/ressources/champions/*.s trash/.;

for i in $(find trash -name "*.s"); do
 	printf "Compile: \033[31m$i\033[0m ";
 	./docs/ressources/asm "$i";
 	name="${i%".s"}.cor";
 	target="${name%".cor"}__gen.s";
 	printf "Disass: \033[32m${name}\033[0m ";
 	[ -f "$target" ] && rm -f "$target";
	./disass/disass --source="$name" --dest="$target"
done
