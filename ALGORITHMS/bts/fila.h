#include "bts.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fila {
	Arvore *inicio, *final;
	int tam;
}Fila;

Fila* criar_fila();
void insere_fim(Fila* f, Arvore* a);
int vazia_fila(Fila *f);
Arvore* retirar_fila(Fila *f);
void imprimir_largura(Arvore* a);

