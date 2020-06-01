#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arv {
    int valor;
    struct arv* esq, *dir;
    struct arv* prox;

}Arvore;

int vazia(Arvore* a);
void imprimir_pre_ordenada(Arvore* a);
void imprimir_in_ordenada(Arvore* a);
void imprimir_pos_ordenada(Arvore* a);
int buscar_pos(Arvore* b, int elem);
Arvore* busca_maior_valor_sub_esquerda(Arvore* a);
Arvore* elimina(Arvore* a, int elem);
int remove_(Arvore* a, int elem);
int inserir(Arvore* a, int elem);
