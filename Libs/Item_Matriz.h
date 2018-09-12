#include "ListaVoos.h"
typedef struct{
    ListaVoos lista;
    int Numero_de_Voos;
    int Ultima_Atualizacao;
}Item_Matriz;
//Inicializacao
void InicializaMatriz(Item_Matriz* Modelo);
//------------------------------------------------------------------------------------------------------
//GETS
void GetLista_de_Voos(Item_Matriz* Modelo);
void GetNumero_de_Voos(Item_Matriz* Modelo);
void GetUltima_Atualizacao(Item_Matriz* Modelo);
//------------------------------------------------------------------------------------------------------
//SETS
void SetLista_de_Voos(Item_Matriz* Modelo, ListaVoos lista);
void SetNumero_de_Voos(Item_Matriz* Modelo,int numero_voos);
void SetUltima_AtualizacaoO(Item_Matriz* Modelo, int ultima_atualizacao);
