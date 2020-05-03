#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int num;
	struct lista* prox;
	struct lista* ant;
}lista;

lst_cria();
lst_imprime(lista* l);
lista* lst_insere(lista* l, int n);
lista* ins_ultimo(lista* l, int n);

int main(){
	
	lista *l; //Declara uma lista n�o iniciada
	
	l = lst_cria(); //Implementa uma fun��o "lista* lst_cria(void)", para iniciar uma lista vazia 
	
	// Implementar a fun��o "lista* lst_insere(lista* l, int n)", que insere um novo elemento
	l = lst_insere(l, 78);
	l = lst_insere(l, 56);
	l = lst_insere(l, 45);
	l = lst_insere(l, 23);
	
	lst_imprime(l);	
	
	// Implementar a fun��o "lista* ins_ultimo(lista* l, int n)", que insere um novo elemento na �ltima posi��o
	l = ins_ultimo(l, 88);
	
	printf("\n");
	lst_imprime(l);
	
	system("pause");
	return 0;
}

lst_cria(){
	return NULL;
}

lst_imprime(lista* l){
	lista* p = l;
	while(p != NULL){
		printf("%d -> ", p->num);
		p = p->prox;
	}
}

lista* lst_insere(lista* l, int n){
	lista *novo = (lista*)malloc(sizeof(lista));
	novo->num = n;	
	novo->prox = l;
	novo->ant = NULL;
	
	if(l != NULL){
		l->ant = novo;
	}
	
	return novo;
}

lista* ins_ultimo(lista* l, int n){
	lista *p = l;
	lista *novo = (lista*)malloc(sizeof(lista));
	
	novo->num = n;
	novo->prox = NULL;
	novo->ant = NULL;
	
	if(p == NULL)
		return novo;

	while(p->prox != NULL)
		p = p->prox;
		
	p->prox = novo;
	novo->ant = p;
	
	return l;
}