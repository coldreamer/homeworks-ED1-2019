
#include "listadpl.h"

struct tipoitem {

  char* nome;
  char* end;
  int mat;

};

struct tipolistadpl {

  TipoItem* aluno;
  TipoListaDpl* prox;
  TipoListaDpl* ant;

};

TipoItem* InicializaTipoItem(char* nome, int matricula, char* endereco){
  TipoItem* aluno = (TipoItem*)malloc(sizeof(TipoItem));
  aluno->nome = (char*)malloc((strlen(nome)+1)*(sizeof(char)));
  strcpy(aluno->nome, nome);

  aluno->end = (char*)malloc((strlen(endereco)+1)*sizeof(char));
  strcpy(aluno->end, endereco);

  aluno->mat = matricula;

  return aluno;


}

TipoListaDpl* Insere (TipoItem* aluno, TipoListaDpl* lista){
  TipoListaDpl* nova = (TipoListaDpl*) malloc(sizeof(TipoListaDpl));

  nova->aluno = aluno;
  nova->ant = NULL;
  nova->prox = lista;

    if (lista!=NULL)
      lista->ant = nova;

  return nova;

}

void Imprime (TipoListaDpl* lista){
  TipoListaDpl* p;


  for (p=lista; p!=NULL; p = p->prox){

    printf ("Nome: %s\n", p->aluno->nome);
    printf ("Matricula: %d\n", p->aluno->mat);
    printf ("Endereco: %s\n", p->aluno->end);
    printf("\n");

  }

}

TipoListaDpl* Retira (TipoListaDpl* lista, char* nome){
  TipoListaDpl* p = lista;

  for (p=lista; p!=NULL; p=p->prox){
    if (strcmp(p->aluno->nome, nome) == 0)
      break;
  }

  if (p == NULL)
    return NULL;

  if (p == lista)
    lista = p->prox;

  else
    p->ant->prox = p->prox;

  if (p->prox != NULL)
    p->prox->ant = p->ant;

  free (p->aluno->nome);
  free (p->aluno->end);
  free(p->aluno);
  free(p);
  return lista;

}

TipoListaDpl* libera (TipoListaDpl* lista){
  TipoListaDpl* p = lista;

  while (p != NULL){

    p = p->prox;

    free(lista->aluno->nome);
    free(lista->aluno->end);
    free(lista->aluno);
    free(lista);

    lista = p;

  }

}
