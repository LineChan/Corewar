<start>             ::=     <program>
                    ;

<program>           ::=     <header> <content_list>
                    ;

<header>            ::=     <header_name> <header_comment>
                    ;

<header_name>       ::=     '.name' <stringify> '\n'
                    ;

<header_comment>    ::=     '.comment' <stringify> '\n'
                    ;

<stringify>         ::=     '"' { <letter> } '"'
                    ;

<content_list>      ::=     <content> '\n' <content_list>
                    |       <content> '\n'
                    ;

<content>            ::=    <label_chars_list> ':'
                    |       '#' { <letter> }
                    |       <instruction>
                    |
                    ;

<instruction>       ::=     <live>
                    |       <ld>
                    |       <st>
                    |       <add>
                    |       <sub>
                    |       <and>
                    |       <or>
                    |       <xor>
                    |       <zjmp>
                    |       <ldi>
                    |       <sti>
                    |       <fork>
                    |       <lld>
                    |       <lldi>
                    |       <lfork>
                    |       <aff>
                    ;

<live>              ::=     'live' <direct>
                    ;

<ld>                ::=     'ld' <direct> ',' <register>
                    |       'ld' <indirect> ',' <register>
                    ;

<st>                ::=     'st' <register> ',' <direct>
                    |       'st' <register> ',' <indirect>
                    ;

<add>               ::=     'add' <register> ',' <register> ',' <register>
                    ;

<sub>               ::=     'sub' <register> ',' <register> ',' <register>
                    ;

<and>               ::=     'and' <register> ',' <register> ',' <register>
                    |       'and' <register> ',' <direct>   ',' <register>
                    |       'and' <register> ',' <indirect> ',' <register>
                    |       'and' <direct>   ',' <register> ',' <register>
                    |       'and' <direct>   ',' <direct>   ',' <register>
                    |       'and' <direct>   ',' <indirect> ',' <register>
                    |       'and' <indirect> ',' <register> ',' <register>
                    |       'and' <indirect> ',' <direct>   ',' <register>
                    |       'and' <indirect> ',' <indirect> ',' <register>
                    ;

<or>                ::=     'or' <register> ',' <register> ',' <register>
                    |       'or' <register> ',' <direct>   ',' <register>
                    |       'or' <register> ',' <indirect> ',' <register>
                    |       'or' <direct>   ',' <register> ',' <register>
                    |       'or' <direct>   ',' <direct>   ',' <register>
                    |       'or' <direct>   ',' <indirect> ',' <register>
                    |       'or' <indirect> ',' <register> ',' <register>
                    |       'or' <indirect> ',' <direct>   ',' <register>
                    |       'or' <indirect> ',' <indirect> ',' <register>
                    ;

<xor>               ::=     'xor' <register> ',' <register> ',' <register>
                    |       'xor' <register> ',' <direct>   ',' <register>
                    |       'xor' <register> ',' <indirect> ',' <register>
                    |       'xor' <direct>   ',' <register> ',' <register>
                    |       'xor' <direct>   ',' <direct>   ',' <register>
                    |       'xor' <direct>   ',' <indirect> ',' <register>
                    |       'xor' <indirect> ',' <register> ',' <register>
                    |       'xor' <indirect> ',' <direct>   ',' <register>
                    |       'xor' <indirect> ',' <indirect> ',' <register>
                    ;

<zjmp>              ::=     'zjmp' <direct>
                    ;

<ldi>               ::=     'ldi' <register> ',' <register>
                    |       'ldi' <register> ',' <direct>
                    |       'ldi' <register> ',' <indirect>
                    |       'ldi' <direct>   ',' <register>
                    |       'ldi' <direct>   ',' <direct>
                    |       'ldi' <direct>   ',' <indirect>
                    |       'ldi' <indirect> ',' <register>
                    |       'ldi' <indirect> ',' <direct>
                    |       'ldi' <indirect> ',' <indirect>
                    ;

<sti>               ::=     'sti' <register> ',' <register> ',' <register>
                    |       'sti' <register> ',' <register> ',' <direct>
                    |       'sti' <register> ',' <direct>   ',' <register>
                    |       'sti' <register> ',' <direct>   ',' <direct>
                    |       'sti' <register> ',' <indirect> ',' <register>
                    |       'sti' <register> ',' <indirect> ',' <direct>
                    ;

<fork>              ::=     'fork' <direct>
                    ;

<lld>               ::=     'lld' <direct>   ',' <register>
                    |       'lld' <indirect> ',' <register>
                    ;

<lldi>              ::=     'lldi' <register> ',' <register> ',' <register>
                    |       'lldi' <register> ',' <direct>   ',' <register>
                    |       'lldi' <direct>   ',' <register> ',' <register>
                    |       'lldi' <direct>   ',' <direct>   ',' <register>
                    |       'lldi' <indirect> ',' <register> ',' <register>
                    |       'lldi' <indirect> ',' <direct>   ',' <register>
                    ;

<lfork>             ::=     'lfork' <direct>
                    ;

<aff>               ::=     'aff' <register>
                    ;

<register>          ::=     'r1' | 'r2'  | 'r3'  | 'r4'  | 'r5'  | 'r6'  | 'r7'  | 'r8'
                    |       'r9' | 'r10' | 'r11' | 'r12' | 'r13' | 'r14' | 'r15' | 'r16'
                    ;

<direct>            ::=     '%' <number>
                    |       '%' ':' <label_chars_list>
                    ;

<indirect>          ::=     <number>
                    |       ':' <label_chars_list>
                    ;

<label_chars_list>  ::=     <label_chars> <label_chars_list>
                    |       <label_chars>
                    ;

<label_chars>       ::=     'a' .. 'z'
                    |       '0' .. '9'
                    |       '_'
                    ;       

<number>            ::=     <digit> <number>
                    |       <digit>

<letter>            ::=     ' ' .. '~'
                    ;
