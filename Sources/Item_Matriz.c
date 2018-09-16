#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../Libs/Item_Matriz.h"
//Inicializacao//
void Inicializa_Item_Matriz(TItem_Matriz* pI_Matriz){
  Inicia_Lista(&pI_Matriz->Lista);
  pI_Matriz->Numero_de_Voos = 0;
  SetUltima_Atualizacao(pI_Matriz);}
//------------------------------------------------------------------------------------------------------
//SETS
void SetLista_de_Voos(TItem_Matriz* pI_Matriz, TLista* pLista){ //Entra com o ponteiro para o Item Matriz o qual vc quer inserir a Lista(pra qual o ponteiro pLista aponta).//
    pI_Matriz->Lista = *pLista;}
void SetNumero_de_Voos(TItem_Matriz* pI_Matriz,int numero_voos){ //Entra com o ponteiro para o Item Matriz o qual vc quer inserir o inteiro Numero de voos.//
  pI_Matriz->Numero_de_Voos = numero_voos;}
void SetUltima_Atualizacao(TItem_Matriz* pI_Matriz){ //Entra com o ponteiro para o Item Matriz o qual vc quer inserir o inteiro Ultima_Atualizacao.//
    time_t tp;
    struct tm lt;
    time(&tp);
    lt = *localtime(&tp);
    int hora=100*lt.tm_hour+lt.tm_min;
    pI_Matriz->Hora_Ultima_Atualizacao = hora;}
  //------------------------------------------------------------------------------------------------------
  //GETS
  TLista* GetLista_de_Voos(TItem_Matriz* pI_Matriz){ //Essa função retorna o endereço da Lista do item matriz do tipo TLista*.//.
    return &pI_Matriz->Lista;}
  int GetNumero_de_Voos(TItem_Matriz* pI_Matriz){ //Essa função retorna o o valor inteiro do numero de voos do *Item Matriz passado por parametro.//.
    return pI_Matriz->Numero_de_Voos;}
  int  GetUltima_Atualizacao(TItem_Matriz* pI_Matriz){//Essa função retorna o ponteiro char da hora da Ultima Atualização do *Item Matriz passado por parametro.//
    return pI_Matriz->Hora_Ultima_Atualizacao;}
