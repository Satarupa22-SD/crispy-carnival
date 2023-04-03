#include <stdio.h>
#include "y.tab.h"

int main() {
    yyparse();
    return 0;
}

int yyerror(char *s) {
    printf("error: %s\n", s);
    return 0;
}

int yylex() {
    static int c = ' ';
    while (c == ' ' || c == '\t' || c == '\n') {
        c = getchar();
    }
    if (c >= '0' && c <= '9') {
        int num = 0;
        while (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
            c = getchar();
        }
        return NUM;
    }
    int token = c;
    c = getchar();
    return token;
}
