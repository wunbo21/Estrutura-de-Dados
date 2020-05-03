#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int val;
	struct lista* prox;
}lista;

lista* InsereValores(lista* l, int n);
void Imprime(lista* l);

int main(){
	
	lista *l;
	int n=0, i = 0;
	
	for(i = 0; i < 10; i++){
		printf("Digite o valor da lista: ");
			scanf("%d", &n);
		l = InsereValores(l,n);
	}
	
	Imprime(l);
	
	system("pause");
	return 0;
}

lista* InsereValores(lista* l, int n){
	lista* novo = (lista*)malloc(sizeof(lista));
	novo->val=n;
	novo->prox=l;
	return novo;
}

void Imprime(lista* l){
	lista*p;
	for(p = l; p != NULL; p = p->prox){
		printf("%d\n", p->val);
	}
	printf("\n");
}
