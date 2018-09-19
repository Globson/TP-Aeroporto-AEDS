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
void SetVID(TVoo* pVoo){     //Função gera valor de VID Aleatorio no unico segundo em que ela roda.//
  srand((unsigned)time(NULL));   //ATENÇÃO!!!----SE FUNÇÃO RODAR MAIS DE UMA VEZ NO MESMO SEGUNDO PARA DOS VOOS DIFERENTES, OS 2 TERÃO O MESMO NUMERO DE VID!!!------///
  pVoo->VID=(rand()%1000);}


void SetHora_Decola(TVoo* pVoo,char hora[]){
  strcpy(pVoo->Hora_Decola,hora);}


void SetHora_Previsto(TVoo* pVoo,char hora[]){
  strcpy(pVoo->Hora_Previsto,hora);}


void SetPista(TVoo* pVoo,int pista){
  pVoo->Pista = pista;}


void SetAeroporto_Partida(TVoo* pVoo,char aeroporto[]){
  strcpy(pVoo->Aeroporto_Partida,aeroporto);}


void SetAeroporto_Chegada(TVoo* pVoo,char aeroporto[]){
  strcpy(pVoo->Aeroporto_Chegada,aeroporto);}
//------------------------------------------------------------------------------------------------------

// GETS
int GetVID(TVoo* pVoo){return pVoo->VID;}


char* GetHora_Decola(TVoo* pVoo){return pVoo->Hora_Decola;} //Função retorna endereço para o tipo char*//


char* GetHora_Previsto(TVoo* pVoo){return pVoo->Hora_Previsto;}


int GetPista(TVoo* pVoo){return pVoo->Pista;} //A função retorna o valor int da pista.// 



char* GetAeroporto_Partida(TVoo* pVoo){return pVoo->Aeroporto_Partida;} //Função retorna endereço para o tipo char*//



char* GetAeroporto_Chegada(TVoo* pVoo){return pVoo->Aeroporto_Chegada;} //Função retorna endereço para o tipo char*//

//------------------------------------------------------------------------------------------------------
