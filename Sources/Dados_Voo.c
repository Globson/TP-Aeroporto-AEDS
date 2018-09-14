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
//TODO:Colocar esse trecho no main para a leitura dos : no horario
//char p1[1];
//printf("Entre com a hora e os minutos da partida separados por dois pontos:");
//scanf("%d%c%d",&Modelo->Hora_Decola,p1,&Modelo->Minuto_Decola);}
void SetVID(TVoo* pVoo){
  srand(time(NULL));
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
//TODO:Retornar ao invez de printar os valores repassados
int GetVID(TVoo pVoo){return pVoo.VID;}
 //TODO:Verificar como retornar de forma apropriada as horas e minutos juntos


char* GetHora_Decola(TVoo pVoo){
  char* Aux;
  Aux = pVoo.Hora_Decola;
  return Aux;}


char* GetHora_Previsto(TVoo pVoo){
  char* Aux;
  Aux = pVoo.Hora_Previsto;
  return Aux;}


int GetPista(TVoo pVoo){return pVoo.Pista;}


//TODO: Verificar possivel  quebra de seguranca com o retorno do endereco do Modelo


char* GetAeroporto_Partida(TVoo pVoo){
  char* Aux;
  Aux = pVoo.Aeroporto_Partida;
  return Aux;}



char* GetAeroporto_Chegada(TVoo pVoo){
  char* Aux;
  Aux = pVoo.Aeroporto_Chegada;
  return Aux;}

//------------------------------------------------------------------------------------------------------
