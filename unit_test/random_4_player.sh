#!/bin/sh

make -j || return;

echo "Setup test for 4 players...";
find docs/ressources/champions -name "*.s" -exec ./docs/ressources/asm {} \; > /dev/null
find docs/ressources/champions -name "*.cor" > /tmp/.champions_list;

f1="/tmp/.$(cat /dev/random | env LC_CTYPE=C tr -cd 'a-f0-9' | head -c 8)";
f2="/tmp/.$(cat /dev/random | env LC_CTYPE=C tr -cd 'a-f0-9' | head -c 8)";

if [ $# -eq 0 ]; then
	DUMP=10000;
else
	DUMP=$1;
fi

while true; do
	c1="$(cat /tmp/.champions_list | sort -R | head -n1)";
	c2="$(cat /tmp/.champions_list | sort -R | head -n1)";
	c3="$(cat /tmp/.champions_list | sort -R | head -n1)";
	c4="$(cat /tmp/.champions_list | sort -R | head -n1)";
	printf "$(basename "$c1") vs $(basename "$c2") vs $(basename "$c3") vs $(basename "$c4"): ";
	./vm/corewar -dump $DUMP -v 31 $c1 $c2 $c3 $c4 > $f1;
	./docs/ressources/corewar -d $DUMP -v 31 $c1 $c2 $c3 $c4 > $f2;
	if [ "" == "$(diff $f1 $f2)" ]; then
		echo "\033[32;1mgood\033[0m";
	else
		echo "\033[31;1mbad\033[0m";
		echo "run \"\033[0;1mDUMP=${DUMP}; c1="$c1"; c2="$c2"; c3="$c3"; c4="$c4"; diff <(./vm/corewar -dump \$DUMP -v 31 \$c1 \$c2 \$c3 \$c4) <(./docs/ressources/corewar -d \$DUMP -v 31 \$c1 \$c2 \$c3 \$c4)\033[0m\""
		echo "see ${f1} and ${f2}";
	fi
done