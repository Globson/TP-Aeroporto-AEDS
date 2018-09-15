#include <stdlib.h>
#include <stdio.h>
#include "../Libs/Item_Matriz.h"
//Inicializacao//
void Inicializa_Item_Matriz(TItem_Matriz* pI_Matriz){
  pI_Matriz->Lista.pPrimeiro= NULL;
  pI_Matriz->Lista.pUltimo= NULL;
  pI_Matriz->Numero_de_Voos = 0;
  pI_Matriz->Ultima_Atualizacao = 0;}
//------------------------------------------------------------------------------------------------------
//SETS
void SetLista_de_Voos(TItem_Matriz* pI_Matriz, TLista* pLista){
    pI_Matriz->Lista = *pLista;}
void SetNumero_de_Voos(TItem_Matriz* pI_Matriz,int numero_voos){
  pI_Matriz->Numero_de_Voos = numero_voos;}
void SetUltima_AtualizacaoO(TItem_Matriz* pI_Matriz, int ultima_atualizacao){
  pI_Matriz->Ultima_Atualizacao = ultima_atualizacao;}
  //------------------------------------------------------------------------------------------------------
  //GETS
  TLista* GetLista_de_Voos(TItem_Matriz* pI_Matriz){ //Essa função retorna o endereço da Lista do item matriz do tipo TLista*.//.
    return &pI_Matriz->Lista;}
  int GetNumero_de_Voos(TItem_Matriz* pI_Matriz){
    return pI_Matriz->Numero_de_Voos;}
  int  GetUltima_Atualizacao(TItem_Matriz* pI_Matriz){
    return pI_Matriz->Ultima_Atualizacao;}
