#!/bin/sh


# [ ! -d "trash" ] && exit;
# make -j;
# for i in $(find trash -name "*.cor"); do
# 	name="$i";
#  	target="${name%".cor"}__gen.s";
#  	printf "Disass: \033[32m${name}\033[0m ";
#  	[ -f "$target" ] && rm -f "$target";
#  	./disass/disass --source="$name" --dest="$target" > "/tmp/test";
# 	if [ "$(cat "/tmp/test")" == "SUCCESS" ]; then
# 		name2="${i%".cor"}.s";
# 		name2="${name2:6}"
# 		echo "docs/ressources/champions/${name2}";
# 		if [ ! -f "docs/ressources/champions/${name2}" ]; then
# 			cp "$target" "docs/ressources/champions/${target:6}";
# 		fi
# 	fi
# done
# exit ;




make -j;
[ -d "trash" ] && rm -rf "trash";
mkdir "trash";

for i in $(find docs/ressources/champions -name "*.s"); do
 	printf "Setup unit_test with: \033[31m$i\033[0m\n";
 	./docs/ressources/asm "$i" > /dev/null;
 	cor_name="${i%".s"}.cor";
 	if [ -f "$cor_name" ]; then
 		mv "$cor_name" "trash/${cor_name:26}";
 	fi
done
for i in 1..2; do
for i in $(find trash -name "*.cor"); do
	target="${i%".cor"}.s";
	printf "\033[32m$i\033[0m to \033[32m$target\033[0m: ";
	./disass/disass --source="$i" --dest="$target";
	printf "\033[31m$target\033[0m to \033[31m$i\033[0m: ";
	./docs/ressources/asm $target;
done
done
