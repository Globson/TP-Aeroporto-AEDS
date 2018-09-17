#include "Item_Matriz.h"
#include "Lista_de_Voos.h"
#include "Dados_Voo.h"
#ifndef MATRIZ_VOO_H
#define MATRIZ_VOO_H
typedef struct {
  TItem_Matriz* M[24][24];
  int Total_De_Voos;
  int Data;
  int Hora_Ultima_Atualizacao_Matriz;
}tMatriz;



//------------------------------------------------------------------------------------------------------

// SETS
void SetData(tMatriz* pMatriz);
void SetTotal_De_Voos(tMatriz* pMatriz);
void SetHora_Ultima_Atualizacao_Matriz(tMatriz* pMatriz);


// GETS
int GetData(tMatriz* pMatriz);
int GetHora_Ultima_Atualizacao_Matriz(tMatriz* pMatriz);

//------------------------------------------------------------------------------------------------------
//Funcoes
void Inicia_Matriz(tMatriz* pMatriz);
int Insere_Voo_Matriz(tMatriz* pMatriz,TVoo* Voo);
TVoo Remove_Voo_Matriz(tMatriz* pMatriz,int VID);
TVoo* Procurar_Voo_Matriz(tMatriz* pMatriz,int VID);
void Imprimir_Voos_Decolagem_Pouso(tMatriz* pMatriz,char* Hora_Decola,char* Hora_Pouso);
void Imprimir_Voos_Decolagem(tMatriz* pMatriz,char* Hora_Decola);
void Imprimir_Voos_Pouso(tMatriz* pMatriz,char* Hora_Previsto);
void Imprimir_Matriz(tMatriz* pMatriz);
void Encontrar_Faixa_Voos_Maior(tMatriz* pMatriz);//Faixa que tem a maior quantidade de voos
void Encontrar_Faixa_Voos_Menor(tMatriz* pMatriz);//Faixa que tem a menor quantidade de voos
void Encontrar_Lista_Voos_Mais_Recente(tMatriz* pMatriz);
void Encontrar_Lista_Voos_Menos_Recente(tMatriz* pMatriz);
void Matriz_Esparca(tMatriz* pMatriz);
/*Verificar se o numero de posicoes da matriz sem voos
cadastrados e,no minimo,o dobro daquelas com 1 voo
cadastrado*/
#endif
