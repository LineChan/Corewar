%discard        ' \t\r\f\v'
%start          <start>

'"'             T_STRING_SEP
'\n'            T_ENDLINE
','             T_PARAM_SEP
'%'             T_PERCENT
'.name'         T_PROG_NAME
'.comment'      T_COMMENT

[:ascii:]+      T_ASCII
[0-9]+          T_NUMBER

%%

<start>
     ::= <header_name> <header_comment> <instruction_list>
     ;

<header_name>
     ::= '.name' <string> '\n'
     |   '\n' <header_name>
     ;

<header_comment>
     ::= '.comment' <string> '\n'
     |   '\n' <header_comment>
     ;

<instruction_list>
     ::= <instruction> <instruction_list>
     |   <instruction>
     ;

<instruction>
     ::= '\n'
     ;

<string>
     ::= '"' T_ASCII '"'
     ;

