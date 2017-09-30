#!/bin/sh

[ ! -f "disass/disass" ] && make -j disass;
[ ! -d "trash" ] && mkdir "trash" && cp -R docs/ressources/champions/cor/*.cor trash/.;
for i in $(find trash -name "*.cor"); do
 	name="${i%".cor"}.s"
 	printf "Disass: \033[32m${name}\033[0m: ";
 	[ -f "$name" ] && rm -f "$name";
	./disass/disass --source="$i" --dest="$name" 2> /dev/null;
	echo;
done
