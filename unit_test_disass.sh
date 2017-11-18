#!/bin/bash

# setup constants
typeset -r FILE_IN="/tmp/test.s";
typeset -r FILE_OUT="/tmp/test.cor";
typeset -r FILE_OUT_CPY="/tmp/test.cor.bak";

# loop over test files
for i in $(find docs/ressources/champions -type f); do

	# remove temporary files
	[ -f "$FILE_IN" ] && rm -f "$FILE_IN";
	[ -f "$FILE_OUT" ] && rm -f "$FILE_OUT";
	[ -f "$FILE_OUT_CPY" ] && rm -f "$FILE_OUT_CPY";

	# copy test file to tmp
	printf "${i}: ";
	cp "$i" "$FILE_IN";
	# exec zaz asm
	./docs/ressources/asm "$FILE_IN" > /dev/null 2> /dev/null;
	if [ -f "$FILE_OUT" ]; then
		rm -f "$FILE_IN";
		# copy file.cor from zaz compiler to get a save
		cp "$FILE_OUT" "$FILE_OUT_CPY";
		# exec my disassembler
		./disass/disass "$FILE_OUT" > /dev/null 2> /dev/null;
		rm -f $FILE_OUT;
		if [ -f "$FILE_IN" ]; then
			# Try to recompile new_file.zaz with zaz asm
			./docs/ressources/asm "$FILE_IN" > /dev/null 2> /dev/null;
			# diff saved.cor and new.cor
			if [ "$(diff "$FILE_OUT" "$FILE_OUT_CPY")" == "" ]; then
				printf "\033[32;1mOK\033[0m\n"
			else
				printf "\033[31;1moutput differs\033[0m\n";
			fi
		else
			printf "\033[31;1mdisass ko\033[0m\n";
		fi
	else
		printf "\033[31;1mzaz asm ko\033[0m\n";
	fi
done
