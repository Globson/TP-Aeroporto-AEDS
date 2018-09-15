#ifndef ITEM_MATRIZ_H
#define ITEM_MATRIZ_H
#include "Lista_de_Voos.h"
typedef struct ItemMatriz{
    TLista* pLista;
    int Numero_de_Voos;
    int Ultima_Atualizacao;
}Item_Matriz;
//Inicializacao
void Inicializa_Matriz(Item_Matriz* pI_Matriz);          //pI_Matriz é um ponteiro para o item matriz
//------------------------------------------------------------------------------------------------------
//GETS
TLista* GetLista_de_Voos(Item_Matriz* pI_Matriz);
int GetNumero_de_Voos(Item_Matriz* pI_Matriz);
int GetUltima_Atualizacao(Item_Matriz* pI_Matriz);
//------------------------------------------------------------------------------------------------------
//SETS
void SetLista_de_Voos(Item_Matriz* pI_Matriz, TLista* pLista);
void SetNumero_de_Voos(Item_Matriz* pI_Matriz,int numero_voos);
void SetUltima_AtualizacaoO(Item_Matriz* pI_Matriz, int ultima_atualizacao);
#endif
