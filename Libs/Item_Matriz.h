#ifndef ITEM_MATRIZ_H
#define ITEM_MATRIZ_H
#include "Lista_de_Voos.h"
typedef struct ItemMatriz{
    TLista Lista;
    int Numero_de_Voos;
    int Hora_Ultima_Atualizacao;
}TItem_Matriz;
//Inicializacao
void Inicializa_Item_Matriz(TItem_Matriz* pI_Matriz);          //pI_Matriz é um ponteiro para o item matriz
//------------------------------------------------------------------------------------------------------
//SETS
void SetLista_de_Voos(TItem_Matriz* pI_Matriz, TLista* pLista);
void SetNumero_de_Voos(TItem_Matriz* pI_Matriz,int numero_voos);
void SetUltima_Atualizacao(TItem_Matriz* pI_Matriz);
//------------------------------------------------------------------------------------------------------
//GETS
TLista* GetLista_de_Voos(TItem_Matriz* pI_Matriz);
int GetNumero_de_Voos(TItem_Matriz* pI_Matriz);
int GetUltima_Atualizacao(TItem_Matriz* pI_Matriz);
#endif
