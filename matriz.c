#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz {
  int linhas;
  int colunas;
  int** ppMat;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas){
  int i;
  Matriz* mat = (Matriz*) malloc (sizeof(Matriz));

  mat->linhas = nlinhas;
  mat->colunas = ncolunas;
  mat->ppMat = (int**) malloc (nlinhas*sizeof(int*));

  for (i=0; i<nlinhas; i++)
    mat->ppMat[i] = (int*) malloc (ncolunas*sizeof(int));

  return mat;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
  mat->ppMat[linha][coluna] = elem;

}

int recuperaElemento(Matriz* mat, int linha, int coluna){
  return mat->ppMat[linha][coluna];

}

int recuperaNColunas (Matriz* mat){
  return mat->colunas;
}

int recuperaNLinhas (Matriz* mat){
  return mat->linhas;
}

void imprimeMatriz (Matriz* mat){
  int i=0, j=0;

  for (i=0; i < mat->linhas; i++){
    for (j=0; j < mat->colunas; j++){
      printf ("%d ", mat->ppMat[i][j]);
    }
      printf ("\n");
  }


}

Matriz* transposta (Matriz* mat){
  int i=0, j=0;
  Matriz* trp = inicializaMatriz (mat->colunas, mat->linhas);

  for (i=0; i < mat->linhas; i++)
    for (j=0; j < mat->colunas; j++)
      trp->ppMat [j][i] = mat->ppMat[i][j];

    return trp;


}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
  int i=0, j=0, k=0;

  Matriz* mlt = inicializaMatriz (mat1->linhas, mat2->colunas);

  for (i=0; i<mat1->linhas; i++){
    for (j=0; j<mat2->colunas; j++){
      mlt->ppMat[i][j] = 0;

      for (k=0; k<mat1->colunas; k++)
        mlt->ppMat[i][j] += ((mat1->ppMat[i][k])*(mat2->ppMat[k][j]));
    }
  }

  return mlt;
}


void destroiMatriz(Matriz* mat){
  int i=0;

  for (i=0; i < mat->linhas; i++)
    free(mat->ppMat[i]);

  free(mat->ppMat);
  free(mat);


}
