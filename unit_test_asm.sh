#!/bin/bash

# setup constants
typeset -r FILE_IN="/tmp/test.s";
typeset -r FILE_OUT="/tmp/test.cor";
typeset -r FILE_OUT_CPY="/tmp/test.cor.bak";

# set up binary
[ ! -f "asm/asm" ] && make -j asm;

# loop over test files
for i in $(find docs/ressources/champions -type f); do

	# remove temporary files
	[ -f "$FILE_IN" ] && rm -f "$FILE_IN";
	[ -f "$FILE_OUT" ] && rm -f "$FILE_OUT";
	[ -f "$FILE_OUT_CPY" ] && rm -f "$FILE_OUT_CPY";

	# copy test file to tmp
	cp "$i" "$FILE_IN";
	printf "${i}: ";

	# exec student asm
	./asm/asm "$FILE_IN" > /dev/null 2> /dev/null;
	if [ -f "$FILE_OUT" ]; then
		# make a copy and exec zaz asm
		cp "$FILE_OUT" "$FILE_OUT_CPY";
		./docs/ressources/asm "$FILE_IN" > /dev/null 2> /dev/null;
		if [ -f "$FILE_OUT" ]; then
			# diff files
			if [ "$(diff "$FILE_OUT" "$FILE_OUT_CPY")" == "" ]; then
				printf "\033[32;1mOK\033[0m\n"
			else
				printf "\033[31;1moutput differs\033[0m: [MY:$(cat $FILE_OUT_CPY | wc -c) bytes] [ZAZ:$(cat $FILE_OUT | wc -c) bytes]\n";
			fi
		else
			printf "\033[31;1mzaz asm failed\033[0m\n";
		fi
	else
		# asm failed. Try zaz asm as reference
		printf " try zaz asm: ";
		./docs/ressources/asm "$FILE_IN" > /dev/null;
		if [ -f "$FILE_OUT" ]; then
			printf "\033[31;1mour asm failed\033[0m\n";
		else
			printf "\033[31;1mzaz asm failed\033[0m\n";
		fi
	fi
done
