#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct fila{
	int n;
	int ini;
	float vet[N];
}Fila;

Fila* fila_cria();
Fila* fila_insere(Fila* f1, float v);
Fila* fila_imprime(Fila* f1);
float fila_retira(Fila* f1);

int main(){
	
	float v;
	Fila* f1;
	
	// Criando a fila
	f1 = fila_cria();
	
	// Inserindo valores na fila
	fila_insere(f1, 10.0);
	fila_insere(f1, 20.0);
	fila_insere(f1, 30.0);
	fila_insere(f1, 40.0);
	
	fila_imprime(f1); // Imprimindo a Fila
	
	v = fila_retira(f1); // Retira da Fila
	printf("\nO elemento retirado e %.2f\n", v);
	
	fila_imprime(f1); // Imprimindo a Fila
	
	/* Considerando que todas as funções que manipulam filas estão disponíveis,
		 crie uma função que receba como parâmetro três filas (f1, f2, f3) e 
		 retir alternadamente os elementos de f1 e f2, enchendo f3 ao final da 
		 função as filas f1 e f2 devem estar vazias
	*/
	
	system("pause");
	return 0;
}

Fila* fila_cria(){
	Fila* f=(Fila*)malloc(sizeof(Fila));
	f->n = 0;
	f->ini = 0;
	return f;
}

Fila* fila_insere(Fila* f1, float v){
	int fim;

	if(f1->n == N){ // Verifico se a fila está cheia
		printf("Fila cheia.");
		exit(1);
	}
	
	fim = (f1->ini + f1->n) % N;
	f1->vet[fim] = v;
	f1->n++;
}

Fila* fila_imprime(Fila* f1){
	int i;
	for(i = 0; i < f1->n; i++){
		printf("%.2f\n", f1->vet[(f1->ini + i) % 100]);
	}
}

float fila_retira(Fila* f1){
	float v;
	if(f1->n == 0){ // Verifico se a fila está vazia
		printf("Fila vazia.");
		exit(1);
	}
	
	v = f1->vet[f1->ini];
	f1->ini = (f1->ini + 1) % N;
	f1->n--;
	return v;
}
