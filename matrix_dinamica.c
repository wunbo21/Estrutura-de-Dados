#include <stdio.h>
#include <stdlib.h>

void procura(int *m, int n, int num);

int main(){
	
	int i, j, num, n;
	int *m;
	
	printf("Entre com o tamanho da matrix: ");
		scanf("%d", &n);
		
	m=(int*) malloc(n*n*sizeof(int));
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("\nMatrix[%d][%d]: ", i,j);
				scanf("%d", &m[i*n+j]);
		}
	}
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%6d",m[i*n+j]);
		}
		printf("\n");
	}
	
	printf("Digite o numero que vai ser buscado: ");
		scanf("%d", &num);
	
	procura(m,n, num);
	
	system("pause");
	return 0;
}

void procura(int *m, int n, int num){
	int i, j, achou = 0;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(m[i*n+j] == num){
				achou = 1;
				printf("\n\nAchou o valor. Ele esta na posicao mat[%d][%d]\n\n",i,j);
			}
		}
	}
	if(achou == 0)
			printf("\n\nNao achou.\n\n");
}

