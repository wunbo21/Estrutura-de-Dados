#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int num;
	struct lista *prox;
}lista;

lista* insere(lista *l, int n);
lista* separa(lista *l, int x);
void imprime(lista *l);

int main(){
	
	lista* l = NULL;
	lista* l2 = NULL;
	
	int i;
	int tam, n = 0, x = 0;
	
	printf("Digite quantos valores voce quer armazenar: ");
		scanf("%d", &tam);
		
	for(i = 0; i < tam; i++){
		printf("Vet[%d]: ", i);
			scanf("%d", &n);
		l = insere(l,n);
	}
	
	imprime(l);
	
	
	printf("Digite uma valor da lista ja existente, para ser divido a partir dela: ");
		scanf("%d", &x);
		
	l2 = separa(l,x);
	
	imprime(l2);
	
	system("pause");
	return 0;
}

// #############################
// ##########         ##########
// ########## FUNÇÕES ##########
// ##########         ##########
// #############################

lista* insere(lista *l, int n){
	lista *p = (lista*)malloc(sizeof(lista));
	p->num = n;
	p->prox = l;
	return p;
}

void imprime(lista *l){
	lista *p;
	for(p = l; p !=NULL; p = p->prox){
		printf("vet: %d\n", p->num);
	}
}

lista* separa(lista *l, int x){
	lista *p = l;
	lista *aux = NULL;
	while(p->prox != NULL){
		if(p->num == x){
			aux = p->prox;
			return aux;
		}
		p = p->prox;
	}
	return NULL;
}
