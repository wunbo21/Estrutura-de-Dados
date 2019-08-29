#include <stdio.h>
#include <stdlib.h>
void troca(int v[]);

int main(){
	
	int vet[5], i, tam;
	
	for(i = 0; i < 5; i++){
		printf("Vet[%d]: ",i);
			scanf("%d", &vet[i]);
	}
	
	troca(vet);
	
	system("pause");
	return 0;
}

void troca(int v[]){
	int f, troca = 1, i, aux;
	
	while(troca == 1){
		f = 5 - 1;
		troca = 0;
		for(i = 0; i < f; i++){
			if(v[i] > v[i+1]){
				aux = v[i+1];
				v[i+1] = v[i];
				v[i] = aux;
				troca = 1;
			}
		}
	}
	for(i = 0; i < 5; i++){
		printf("Vet[%d]: %d - ",i, v[i]);
	}
}
