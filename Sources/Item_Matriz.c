#include <stdlib.h>
#include <stdio.h>
#include "../Libs/Item_Matriz.h"
//Inicializacao//
void Inicializa_Matriz(Item_Matriz* Modelo){
  Modelo->pLista = NULL;
  Modelo->Numero_de_Voos = 0;
  Modelo->Ultima_Atualizacao = 0;}
//------------------------------------------------------------------------------------------------------
//GETS
TLista* GetLista_de_Voos(Item_Matriz* Modelo){
  return Modelo->pLista;}
int GetNumero_de_Voos(Item_Matriz* Modelo){
  return Modelo->Numero_de_Voos;}
int  GetUltima_Atualizacao(Item_Matriz* Modelo){
  return Modelo->Ultima_Atualizacao;}
//------------------------------------------------------------------------------------------------------
//SETS
void SetLista_de_Voos(Item_Matriz* Modelo, TLista* pLista){} //Ainda n entendi bem oq realizar com esse set com relação a lista encadeada.Att Grobs<3//
void SetNumero_de_Voos(Item_Matriz* Modelo,int numero_voos){
  Modelo->Numero_de_Voos = numero_voos;}
void SetUltima_AtualizacaoO(Item_Matriz* Modelo, int ultima_atualizacao){
  Modelo->Numero_de_Voos = ultima_atualizacao;}
