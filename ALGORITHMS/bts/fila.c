#include "fila.h"

Fila* criar_fila() { 
	
     Fila* f = calloc(1, sizeof(Fila));	
     return f;
}

void insere_fim(Fila* f, Arvore* a) {
	
	a->prox = NULL;
	if(f->inicio == NULL){
        f->inicio = a;
    } 
    else{
	    f->final->prox = a;
    }
    
    f->final = a;    
    f->tam += 1;
  
}

int vazia_fila(Fila *f) {
    if(f->inicio == NULL || f->tam <= 0) return 1;
    else return 0;		
}

Arvore* retirar_fila(Fila *f) {
	   Arvore *aux;
	   if(f->inicio != NULL){
		  aux = f->inicio;
		  f->inicio = f->inicio->prox;   
		  f->tam -= 1;
	   }
	   return aux;
}


void imprimir_largura(Arvore* a) {
	
	if(a == NULL) return;
	
	Fila* f = calloc(1, sizeof(Fila));
	Arvore* b;	
	insere_fim(f, a);
    printf("%d ", a->valor);
	while(!vazia_fila(f)){
		
			b = retirar_fila(f);
			if(b->esq != NULL){
				insere_fim(f, b->esq);
				printf("%d ", b->esq->valor);
			}
			if(b->dir != NULL) {
				insere_fim(f, b->dir);
				printf("%d ", b->dir->valor); 
			}	
	}
    return;
}



