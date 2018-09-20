#include "../Libs/Dados_Voo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//Inicializacao
void InicializaVoo(TVoo* pVoo){
  pVoo->VID = 0;
  strcpy(pVoo->Hora_Decola,"");
  strcpy(pVoo->Hora_Previsto,"");
  pVoo->Pista = 0;
  strcpy(pVoo->Aeroporto_Chegada,"");
  strcpy(pVoo->Aeroporto_Partida,"");}
//------------------------------------------------------------------------------------------------------

// SETS
void SetVID(TVoo* pVoo){     //Função gera valor de VID Aleatorio.//
pVoo->VID=(rand()%1000);}

void SetHora_Decola(TVoo* pVoo,char hora[]){ //Função realiza Set para o que foi pedido.//
  strcpy(pVoo->Hora_Decola,hora);}


void SetHora_Previsto(TVoo* pVoo,char hora[]){ //Função realiza Set para o que foi pedido.//
  strcpy(pVoo->Hora_Previsto,hora);}


void SetPista(TVoo* pVoo,int pista){ //Função realiza Set para o que foi pedido.//
  pVoo->Pista = pista;}


void SetAeroporto_Partida(TVoo* pVoo,char aeroporto[]){ //Função realiza Set para o que foi pedido.//
  strcpy(pVoo->Aeroporto_Partida,aeroporto);}


void SetAeroporto_Chegada(TVoo* pVoo,char aeroporto[]){ //Função realiza Set para o que foi pedido.//
  strcpy(pVoo->Aeroporto_Chegada,aeroporto);}
//------------------------------------------------------------------------------------------------------

// GETS
int GetVID(TVoo* pVoo){return pVoo->VID;}  //A função retorna o valor do VID do Voo.//


char* GetHora_Decola(TVoo* pVoo){return pVoo->Hora_Decola;} //Função retorna endereço para o tipo char*//


char* GetHora_Previsto(TVoo* pVoo){return pVoo->Hora_Previsto;} //Função retorna endereço para o tipo char*//


int GetPista(TVoo* pVoo){return pVoo->Pista;} //A função retorna o valor int da pista.//



char* GetAeroporto_Partida(TVoo* pVoo){return pVoo->Aeroporto_Partida;} //Função retorna endereço para o tipo char*//



char* GetAeroporto_Chegada(TVoo* pVoo){return pVoo->Aeroporto_Chegada;} //Função retorna endereço para o tipo char*//

//------------------------------------------------------------------------------------------------------
