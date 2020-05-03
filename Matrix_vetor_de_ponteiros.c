#include <stdio.h>
#include <stdlib.h>

//void busca(int n, int **m, int num);

int main(){
	
	int **m;
	int i=0, j=0, n, num;
	
	printf("Digite o tamanho do vetor: ");
		scanf("%d", &n);
	
	m = (int**) malloc(n*sizeof(int*));
	
	for(i = 0; i<n; i++)
		m[i]=(int*) malloc(n*sizeof(int));
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("\nMatrix[%d][%d]: ", i,j);
				scanf("%d", &m[i][j]);
		}
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	
	//printf("Digite o numero que voce quer achar:");
		//scanf("%d", &num);
	
	//busca(n, m, num);

	system("pause");
	return 0;
}

/*void busca(int n, int **m, int num){
	
}*/
