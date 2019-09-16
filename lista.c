#include "lista.h"

typedef struct cel TCelula;

struct tipoitem{
  char* nome;
  char* endereco;
  int matricula;
};

struct cel{
  TipoItem* aluno;
  TCelula* prox;
};

struct tipolista{
  TCelula* ini;
  TCelula* fim;
};


TipoItem* InicializaTipoItem (char* nome, int matricula, char* endereco){
  TipoItem* aluno = (TipoItem*)malloc(sizeof(TipoItem));
  aluno->nome = (char*)malloc((strlen(nome)+1)*(sizeof(char)));
  strcpy(aluno->nome, nome);

  aluno->endereco = (char*)malloc((strlen(endereco)+1)*sizeof(char));
  strcpy(aluno->endereco, endereco);

  aluno->matricula = matricula;

  return aluno;


}

TipoLista* InicializaLista(){
  TipoLista* lista = (TipoLista*) malloc (sizeof(TipoLista));

  lista->ini = NULL;
  lista->fim = NULL;

  return lista;
}

void Insere (TipoItem* aluno, TipoLista* lista){
  TCelula* nova = (TCelula*) malloc (sizeof(TCelula));


  nova->prox = lista->ini;
  nova->aluno = aluno;
  lista->ini = nova;

  if (lista->fim == NULL)
    lista->fim = nova;

}


void Imprime (TipoLista* lista){
  TCelula* p;

  for (p=lista->ini; p!=NULL; p = p->prox){

    printf ("%s\n", p->aluno->nome);
    printf ("%d\n", p->aluno->matricula);
    printf ("%s\n", p->aluno->endereco);

  }

}

TipoItem* Retira (TipoLista* lista, int mat){
  TCelula* ant = NULL;
  TCelula* p = lista->ini;

  //procura elemento na lista, preservando o ponteiro anterior para nao perder o encadeamento
  while (p!= NULL && p->aluno->matricula != mat){
    ant = p;
    p = p->prox;
  }

  if (p == NULL){
    return NULL;
  }

  if(p == lista->ini && p == lista->fim){
    lista->ini = lista->fim = NULL;
    TipoItem* a = p->aluno;
    free(p);
    return a;
  }

  if (p == lista->fim){
    lista->fim = ant;
    ant->prox = NULL;
    TipoItem* a = p->aluno;
    free(p);
    return a;
  }

  else{
    ant->prox = p->prox;

  TipoItem* a = p->aluno;
  free(p);
  return a;
  }

}


TipoLista* Libera (TipoLista* lista){
  TCelula* p = lista->ini;

  while (p!=NULL){
    TCelula* t = p->prox;
    LiberaAluno (p->aluno);
    free (p);
    p = t;

  }

  free(lista);

}

void LiberaAluno (TipoItem* aluno){

  if (aluno != NULL){
    free(aluno->nome);
    free(aluno->endereco);
    free(aluno);
  }

}
