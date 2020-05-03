#include <stdio.h>
#include <stdlib.h>

struct lista {
int info;
struct lista* prox;
};
typedef struct lista Lista;

Lista* lst_cria(){
	return NULL;
}

Lista* lst_insere(Lista* l, int i){
	Lista* novo =(Lista*)malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}

void lst_imprime(Lista* l){
	Lista* p;
	for(p = l; p != NULL; p = p->prox){
		printf("Valor: %d\n", p->info);
	}
}

Lista* busca(Lista* l, int num){
	Lista* p;
	for(p = l; p != NULL; p = p->prox){
		if(p->info == num){
			return p;
		}
	}
	return NULL;
}

Lista* ins_ultimo(Lista* l, int n){
	Lista* p = l;
	Lista* ant = NULL;
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = n;
	while(p!=NULL){
		ant = p;
		p = p->prox;
	}
	if(ant == NULL){
		novo->prox = l;
		l = novo;
	}
		else{
			novo->prox = ant->prox;
			ant->prox = novo;
		}
	return l;
}

Lista* retira_ultimo(Lista* l){
	Lista* p = l;
	Lista* aux = NULL;
	if(p == NULL)
		return NULL;
	while(p->prox!=NULL){
		aux = p;
		p = p->prox;
	}
	if(aux == NULL)
		l = NULL;
		else
			aux->prox = NULL;
	free(p);
	
	return l;
}



Lista* ins_ultimo_cond(Lista* l, int n){
	Lista* p;
	for(p = l; p != NULL; p = p->prox){
		if(p->info == n)
			return l;	
	}
	p = l;
	Lista* aux = NULL;
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = n;
	while(p != NULL){
		aux = p;
		p = p->prox;
	}
	if(aux == NULL){
		novo->prox = l;
		l = novo;
	}
		else{
			novo->prox = aux->prox;
			aux->prox = novo;
		}
	return l;
}

void lst_libera(Lista* l){
	Lista* p = l;
	while(p != NULL){
		Lista* t = p->prox;
		free(p);
		p = t;		
	}
}

int main (void)
{
Lista* l; /* declara uma lista não iniciada */
l = lst_cria(); /* inicia lista vazia */

/* vai inserir no início da lista */
l = lst_insere(l, 23); /* insere na lista o elemento 23 */
l = lst_insere(l, 45); /* insere na lista o elemento 45 */
l = lst_insere(l, 56); /* insere na lista o elemento 56 */
l = lst_insere(l, 78); /* insere na lista o elemento 78 */
lst_imprime(l); /* imprimirá: 78 56 45 23 */
printf("\n");
printf("\n");

/*vai buscar um ponteiro para o nó com a informação 45*/
Lista* k = busca(l,45);
printf("Info = %d\n", k->info);
printf("\n");
printf("\n");

/*vai inserir um elemento no final da lista*/
l = ins_ultimo(l,82);
lst_imprime(l); /* imprimirá: 78 56 45 23 82 */
printf("\n");
printf("\n");

/*vai retirar o elemento do final da lista*/
l = retira_ultimo(l);
printf("Aqui");
lst_imprime(l); /* imprimirá: 78 56 45 23 */

/*vai inserir o elemento no final da lista, se ele ainda não existe como informação em algum nó*/
l = ins_ultimo_cond(l,82);
printf("\n");
printf("\n");
//lst_imprime(l); /* imprimirá: 78 56 45 23 82 */

l = ins_ultimo_cond(l,45);
printf("\n");
printf("\n");
//lst_imprime(l); /* imprimirá: 78 56 45 23 82 */


/*vai liberar a lista */ 
lst_libera(l);
return 0;
}
