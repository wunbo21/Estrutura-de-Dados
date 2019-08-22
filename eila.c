#include<stdio.h>
#include<stdlib.h>

int soma(float v[], int n);
int procura(int n,int proc, float* v);

int main(){
	
	int i, n, achou;
	float *v;
	float proc;
	/* Leitura do número de valores */
	printf("\nEntre com o numero de valores do vetor: ");
		scanf("%d", &n);
	/* Alocação Dinâmica */
	v = (float*) malloc(n*sizeof(float));
	if(v==NULL){
		printf("Memoria Insuficiente.\n");
		return 1;
	}
	/* Leitura dos valores */
	printf("\nEntre com os valores: ");
	for(i = 0; i < n; i++)
		scanf("%f", &v[i]);
		
	printf("\nCalcula a media: ");
	printf("\n A media e: %f", soma(v,n)/(float)n);
	
	printf("\nEntre com o valor que deseja saber a posicao no vetor: ");
	scanf("%f", &proc);
	achou = procura(n,proc,v);
	if(achou == -1){
		printf("\n O numero digita nao existe no vetor!");	
	}
	else{
		printf("\n O numero esta na posicao %d\n\n", achou);
	}

	free(v);
	system("pause");
	return 0;
}

int soma(float v[], int n){
	if(n==0) 
		return 0;
	else
		return (v[n-1] + soma(v, n-1));
}

int procura(int n,int proc, float* v){
	if(n == 0) return -1;
	else if(proc == v[n - 1]) return n - 1;
	else
		return procura(n-1, proc, v);
}
