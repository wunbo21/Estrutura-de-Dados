#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 127

// Estruturas //
typedef struct aluno {
  int mat;
  char nome[64];
  struct aluno* prox;
}Aluno;

typedef Aluno* Hash[N];

// Declarações de funções //
Aluno* busca(Hash* tab, int mat);
Aluno* insere(Hash* tab, int mat, char* nome);
int hash(int mat);

// Menu Principal //
int main() {

  Hash tab;
  Hash tab2;

  int i = 0;
  char nome[64];

  for(i = 0; i < N; i++)
    tab[i] = NULL;

  for(i = 0; i < N; i++)
    tab2[i] = NULL;

  strcpy(nome,"Marco");
  i = insere (&tab, 127, nome);

  strcpy(nome,"Maria");
  i = insere (&tab, 254, nome);

  strcpy(nome,"Carlos");
  i = insere (&tab, 381, nome);

  strcpy(nome,"Sueli");
  i = insere (&tab, 508, nome);

  i = insere (&tab, 508, nome);

  if (i == 1) 
    printf ("Aluno(a) %s ja existe! - nao inserido(a)", nome);
  printf("\n\n");


  Aluno* k = busca(&tab,381);
   if(k==NULL) 
    printf("Aluno(a) nao encontrado(a)!");
   else 
    printf("Aluno(a) %s pertence a tabela!", k->nome);
  printf("\n\n");

  /*i = retira(tab,381);
  k = busca(tab,381);
  if(k==NULL) printf("Aluno(a) nao encontrado(a)!");
  else printf("Aluno(a) %s pertence a tabela!", k->nome);*/

  return 0;
}


// Funções //
int hash(int mat){
  printf("%d", mat % N);
  return (mat % N);
}

Aluno* busca(Hash* tab, int mat) {
  int h = hash(mat);
  Aluno* a = *tab[h];
  while (a != NULL){
    if(a->mat == mat)
      return a;
    a = a->prox;
  }
  return NULL;
}

Aluno* insere(Hash* tab, int mat, char* nome) {
  int h = hash(mat);

  Aluno* a = *tab[h];
  while(a != NULL){
    if(a->mat == mat) //Verificando se existe a matricula
      break;
    a = a->prox;
  }

  if(a == NULL) { //Não encontrou o elemento, vai inserir ele no primeiro da fila
    a = (Aluno*) malloc(sizeof(Aluno));
    a->mat = mat;
    a->prox = *tab[h];
    *tab[h] = a;
  }

  // Atribui o modifica informação
  strcpy(a->nome, nome);
  return a;
}
