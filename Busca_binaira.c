#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int procuraBinaria(float v[], float num, int inicio, int n);
void ordena(float v[], int n);

int main(){

	int n, i, procura = 0;
	float *v, num;
	printf ("Escolha o tamanho do vetor: ");
	scanf ("%d", &n);
	
	v = (float*) malloc(n*sizeof(float));
	
	srand(time(NULL));
	for (i = 0; i < n; i++){
		v[i] = rand() % 100;
		printf ("%2.2f - ", v[i]);
	}
	
	// ORDENANDO VALORES DO VETOR
	ordena(v, n);
	printf ("\n\n");
	for (i = 0; i < n; i++){
		printf ("%2.2f - ", v[i]);
	}
	
	//VALOR A SER PROCURADO
	printf ("\nInsira o valor a ser buscado: ");
	scanf ("%f", &num);
	procura = procuraBinaria(v, num, 0, n);
	if (procura == -1) printf ("O valor não foi encontrado no vetor");
	else printf ("O valor foi encontrado na posição %d", procura);
		
	return 0;
}

void ordena(float v[], int n){
	int troca = 1, i, f = n;
	float aux;
	while (troca == 1){
		f = f - 1;
		troca = 0;
		for (i = 0; i < f; i++){ 
			if (v[i] > v[i + 1]){
				aux = v[i + 1];
				v[i + 1] = v[i];
				v[i] = aux;
				troca = 1;
			}
		}
	}
}

int procuraBinaria(float v[], float num, int inicio, int n){
	int k = (inicio + n)/2;
	if(v[k] == num) return k;
	else {
		if (k == n) return -1;
		if(num > v[k]){		
			return procuraBinaria(v, num, k+1, n);	
		}	
		else if (num < v[k]){
			return procuraBinaria(v, num, inicio, k-1);
		}	
	}
}

