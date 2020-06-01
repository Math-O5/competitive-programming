#include "bts.h"

int vazia(Arvore* a) {
	if(a == NULL) return 1;
    return 0;	
}


void imprimir_pre_ordenada(Arvore* a) {
     if(!vazia(a)) {
		printf("%d ", a->valor);
		imprimir_pre_ordenada(a->esq);
		imprimir_pre_ordenada(a->dir);
     }	
}

void imprimir_in_ordenada(Arvore* a) {
     if(!vazia(a)) {
	    imprimir_in_ordenada(a->esq);
		printf("%d ", a->valor);
		imprimir_in_ordenada(a->dir);
     }	
}

void imprimir_pos_ordenada(Arvore* a) {
     if(!vazia(a)) {
	    imprimir_pos_ordenada(a->esq);
		imprimir_pos_ordenada(a->dir);
		printf("%d ", a->valor);
     }	
	
}

/*
 * Faz busca, verifica a existencia de
 * um elemnto. 
 * */
int buscar_pos(Arvore* b, int elem) {
    if(b == NULL) return 0;
    if(b->valor > elem) {
		return buscar_pos(b->esq, elem);	
    }
    else if(b->valor < elem) {
	    return buscar_pos(b->dir, elem);	
	}
	else return 1;	
}


Arvore* busca_maior_valor_sub_esquerda(Arvore* a) {
    Arvore* b = a;
    
    while(b->esq != NULL) {
		 b = b->esq;
	}
	return b;
}
 
Arvore* elimina(Arvore* a, int elem) {
	 
	 if(a->valor == elem) {
	       Arvore* b;
     
	       if(a->esq == NULL) {

			   b = a->dir;
			   a->valor = 0;
			   free(a);
			   return b;
		   }
	       else if(a->dir == NULL) {

			   b = a->esq;
			   a->valor = 0;
			   free(a);
			   return b;
		   }
	       b = busca_maior_valor_sub_esquerda(a->dir);
	       a->valor = b->valor;
	       
	       a->dir = elimina(a->dir, b->valor);
     }
	 else if(a->valor < elem) a->dir = elimina(a->dir, elem);
	 else if(a->valor > elem) a->esq = elimina(a->esq, elem);
	 
     return a;
}

int remove_(Arvore* a, int elem) {
	if(buscar_pos(a, elem) == 0) return 0;
	a = elimina(a, elem);
    return 1;           
}

int inserir(Arvore* a, int elem) {
	 
	if(a->valor > elem) {		
		  if(a->esq == NULL) {
		     a->esq = calloc(1, sizeof(Arvore));
		     a->esq->valor = elem;
		     return 0;
		  }
		  else return inserir(a->esq, elem);
	 }
	 else if(a->valor < elem) {
	      if(a->dir == NULL) {
		     a->dir = calloc(1, sizeof(Arvore));
		     a->dir->valor = elem;
		     return 0;
		  }
		  else return inserir(a->dir, elem);
	 }
	 else return 1;
}
