#include "Lista_de_Voos.h"
typedef struct ItemMatriz{
    TLista* pLista;
    int Numero_de_Voos;
    int Ultima_Atualizacao;
}Item_Matriz;
//Inicializacao
void Inicializa_Matriz(Item_Matriz* Modelo);
//------------------------------------------------------------------------------------------------------
//GETS
TLista* GetLista_de_Voos(Item_Matriz* Modelo);
int GetNumero_de_Voos(Item_Matriz* Modelo);
int GetUltima_Atualizacao(Item_Matriz* Modelo);
//------------------------------------------------------------------------------------------------------
//SETS
void SetLista_de_Voos(Item_Matriz* Modelo, TLista* pLista);
void SetNumero_de_Voos(Item_Matriz* Modelo,int numero_voos);
void SetUltima_AtualizacaoO(Item_Matriz* Modelo, int ultima_atualizacao);
