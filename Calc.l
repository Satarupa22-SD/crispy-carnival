%{
#include <stdio.h>
%}

%token NUM

%%

calc: expr { printf("%d\n", $1); }

expr: expr '+' expr { $$ = $1 + $3; }
    | expr '-' expr { $$ = $1 - $3; }
    | expr '*' expr { $$ = $1 * $3; }
    | expr '/' expr { $$ = $1 / $3; }
    | '(' expr ')' { $$ = $2; }
    | NUM { $$ = $1; }

%%

int main() {
    yyparse();
    return 0;
}

int yyerror(char *s) {
    printf("error: %s\n", s);
    return 0;
}
