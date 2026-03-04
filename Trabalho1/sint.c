#include <stdio.h>
#include <stdlib.h>
#include "analex.h"

int token;

//Implemente todas as funções cujas assinaturas estão abaixo. Algumas já estão implementadas, mas talvez com partes faltando.

void E();
void T();
void E_linha();
void T_linha();
void F();

void erro() {
	printf("Erro sintatico na linha %d\n", linha);
	exit(1);
}

void consome(int t) {
	if (t == token)
	  token = analex();
	else 
	  erro();   
}
void E(){
	T();
	E_linha();
}

void E_linha() {
	if (token == '+') {
		consome('+');
		T();
		E_linha();
        printf("+ ");
	}
	else if (token == '-') {
		consome('-');
		T();
		E_linha();
        printf("- ");
	}
	else ;
}

void T(){
	F();
	T_linha();
}

void T_linha() {
	if (token == '*') {
		consome('*');
		T();
		E_linha();
        printf("* ");
	}
	else if (token == '/') {
		consome('/');
		T();
		E_linha();
        printf("/ ");
	}
	else ;
}


void F() {
	if(token == NUM) {
      printf("%d ", tokenval);
	  consome(NUM);
    }
    else if (token == '(') {
        //Implementar
	}
	else erro();
}

int main() {
    token = analex();
    E();
    if (token != ';')
        erro();  
    return 0;
}

