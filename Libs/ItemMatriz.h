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
void GetListadeVoos(Item_Matriz* Modelo);
void GetNumerodeVoos(Item_Matriz* Modelo);
void GetUltimaAtualizacao(Item_Matriz* Modelo);
//------------------------------------------------------------------------------------------------------
//SETS
void SetListadeVoos(Item_Matriz* Modelo, ListaVoos lista);
void SetNumerodeVoos(Item_Matriz* Modelo,int numero_voos);
void SetUltimaAtualizacaoO(Item_Matriz* Modelo, int ultima_atualizacao);
