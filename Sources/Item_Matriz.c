#include <stdlib.h>
#include <stdio.h>
#include "../Libs/Item_Matriz.h"
//Inicializacao//
void Inicializa_Matriz(Item_Matriz* pI_Matriz){
  pI_Matriz->pLista = NULL;
  pI_Matriz->Numero_de_Voos = 0;
  pI_Matriz->Ultima_Atualizacao = 0;}
//------------------------------------------------------------------------------------------------------
//GETS
TLista* GetLista_de_Voos(Item_Matriz* pI_Matriz){
  return pI_Matriz->pLista;}
int GetNumero_de_Voos(Item_Matriz* pI_Matriz){
  return pI_Matriz->Numero_de_Voos;}
int  GetUltima_Atualizacao(Item_Matriz* pI_Matriz){
  return pI_Matriz->Ultima_Atualizacao;}
//------------------------------------------------------------------------------------------------------
//SETS
void SetLista_de_Voos(Item_Matriz* pI_Matriz, TLista* pLista){} //Ainda n entendi bem oq realizar com esse set com relação a lista encadeada.Att Grobs<3//
void SetNumero_de_Voos(Item_Matriz* pI_Matriz,int numero_voos){
  pI_Matriz->Numero_de_Voos = numero_voos;}
void SetUltima_AtualizacaoO(Item_Matriz* pI_Matriz, int ultima_atualizacao){
  pI_Matriz->Numero_de_Voos = ultima_atualizacao;}
