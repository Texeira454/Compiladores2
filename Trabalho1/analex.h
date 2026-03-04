#include <stdio.h>
#include <ctype.h>


#define NUM 256
extern int tokenval;
extern int linha, coluna; //A variável linha é que deve ser modificada para ser capaz de identificar o número da linha onde occoreu o erro.

int analex();