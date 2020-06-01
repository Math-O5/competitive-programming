/*REFERENCIAS:
 *    https://br.spoj.com/problems/PREEMPOS/
 *    https://www.youtube.com/watch?v=3zmjQlJhBLM
 * */

#include "fila.h"

int main(){
	char op[5];
	Arvore* a = NULL;
    int elem;
	while(1) {
	    scanf("%s", op);
	    switch(op[0]) {	      
		      case 'I':
		            scanf("%d", &elem);
		            if(a == NULL) {
		               a = calloc(1, sizeof(Arvore));
		               a->valor = elem;		 
	                } 
	                else if(inserir(a, elem)){
					     printf("Chave existente\n");	
					};
		      break;     
		      case 'N':
		           printf("InOrdem: ");
				   imprimir_in_ordenada(a);
				   printf("\n");
		      break;     
		      case 'O':
		           printf("PosOrdem: ");
				   imprimir_pos_ordenada(a);
				   printf("\n");
		      break;     
		      case 'E':
		           printf("PreOrdem: ");
				   imprimir_pre_ordenada(a);
				   printf("\n");
		      break;      
		      case 'L':
		           printf("Largura: ");
				   imprimir_largura(a);
				   printf("\n");
		      break;	      
		      case 'Y':
		           
		           printf("InOrdem: ");
				   imprimir_in_ordenada(a);
				   printf("\n");
		           
		           printf("PreOrdem: ");
				   imprimir_pre_ordenada(a);
				   printf("\n");
				   
		           printf("PosOrdem: ");
				   imprimir_pos_ordenada(a);
				   printf("\n");
				   
				   printf("Largura: ");
				   imprimir_largura(a);
				   printf("\n");
				   
		      break;  
		      case 'B':
		            scanf("%d", &elem);
		            if(buscar_pos(a, elem) == 1) printf("Encontrado\n");
		            else printf("Nao encontrado\n");
		      break;  
		      case 'D':
		            scanf("%d", &elem);
		            if(remove_(a, elem) == 0) printf("Nao encontrado\n");
		            else printf("%d\n", elem);
		      break;
		      default: return 0;	
		}	
	}

return 0;	
}
