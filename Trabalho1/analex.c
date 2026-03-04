#include "analex.h"
#include <ctype.h>

//Atenção ao #define no arquivo analex.h. Por que eu defini um valor 256 para NUM? O que isso significa?

int tokenval; //O que é tokenval? Como ele é diferente de token?
int linha, coluna; //A variável linha é que deve ser modificada para ser capaz de identificar o número da linha onde occoreu o erro.
int linha = 1, coluna = 1;

int analex(){
    int ch;
    tokenval = -1;
    while(1) {
    ch = getchar();

    while (ch == ' ') {
        ch = getchar();
        coluna++;
    }

    while (ch == '\t') {
        ch = getchar();
        coluna += 4;
    }

    while (ch == '\n') {
        ch = getchar();
        coluna=1;
        linha++;
    }

    if (ch == '+')
        return '+';

    if (ch == '-')
        return '-';

    if (ch == '*')
        return '*';

    if (ch == '/')
        return '/';

    if (ch == '(')
        return '(';

    if (ch == ')')
        return ')';	 
        
    if (ch == ';')
        return ';';

        //Seja capaz de entender o bloco de código abaixo. Você consegueria explicar o que ele faz?
    if (isdigit(ch)) {	    
        tokenval = ch -'0';
        ch = getchar();
        while(isdigit(ch)) {
            tokenval = tokenval*10 + ch-'0';
            ch = getchar();
        }
        ungetc(ch,stdin); //Essa função devolve o último caractere lido para o fluxo de entrada. Por que?
        return NUM;
    }

    if (ch == EOF) {
        return EOF;
    }

    printf("Erro lexico na linha %d!!\n", linha);  
    }
        
}