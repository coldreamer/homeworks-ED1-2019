/*********************************
* Programa testador do TAD Lista
*********************************
*/

#include "listadpl.h"

int main()
{

 TipoListaDpl* lista;
 TipoItem* i;
 lista = NULL;

  TipoItem* livia = InicializaTipoItem("Livia", 2018102878, "rua da livia");
  TipoItem* patricia = InicializaTipoItem("patricia", 950156464, "rua da patricia");
  TipoItem* gustavo = InicializaTipoItem("gustavo", 2018103052, "rua do gustavo");
  TipoItem* dionatas = InicializaTipoItem("dionatas", 2019202307, "rua do dionatas");
  TipoItem* junior = InicializaTipoItem("junior", 2018103470, "rua do junior");


  lista = Insere(livia, lista);
  lista = Insere(patricia, lista);
  lista = Insere(gustavo, lista);
  lista = Insere(dionatas, lista);
  lista = Insere(junior, lista);

  Imprime (lista);

  lista = Retira (lista, "patricia");

  printf ("\n");
  Imprime (lista);

  libera(lista);

}
