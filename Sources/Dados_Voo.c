#include "../Libs/Dados_Voo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//Inicializacao
void InicializaVoo(TVoo* Modelo){
  Modelo->VID = 0;
  Modelo->Hora_Decola = 0;
  Modelo->Minuto_Decola = 0;
  Modelo->Hora_Previsto = 0;
  Modelo->Minuto_Previsto= 0;
  Modelo->Pista = 0;
  strcpy(Modelo->Aeroporto_Chegada,"");
  strcpy(Modelo->Aeroporto_Partida,"");}
//------------------------------------------------------------------------------------------------------

// SETS
//TODO:Colocar esse trecho no main para a leitura dos : no horario
//char p1[1];
//printf("Entre com a hora e os minutos da partida separados por dois pontos:");
//scanf("%d%c%d",&Modelo->Hora_Decola,p1,&Modelo->Minuto_Decola);}
void SetVID(TVoo* pVoo){
  srand(time(NULL));
  pVoo->VID=(rand()%1000);}
void SetHora_Minuto_Decola(TVoo* pVoo, int hora,int minuto){
  pVoo->Hora_Decola = hora;
  pVoo->Minuto_Decola = minuto;}
void SetHora_Minuto_Previsto(TVoo* pVoo,int hora,int minuto){
  pVoo->Hora_Previsto = hora;
  pVoo->Minuto_Previsto = minuto;}
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
void GetHora_Minuto_Decola(TVoo pVoo){printf("%d:%d",pVoo.Hora_Decola,pVoo.Minuto_Decola);}
void GetHora_Minuto_Previsto(TVoo pVoo){printf("%d:%d",pVoo.Hora_Previsto,pVoo.Minuto_Previsto);}
int GetPista(TVoo pVoo){return pVoo.Pista;}
//TODO: Verificar possivel  quebra de seguranca com o retorno do endereco do Modelo
char* GetAeroporto_Partida(TVoo pVoo){return pVoo.Aeroporto_Partida;}
char* GetAeroporto_Chegada(TVoo pVoo){return pVoo.Aeroporto_Chegada;}
//char* GetCiaAerea(TVoo Modelo){return Modelo.CiaAerea;}
//char* GetStatus(TVoo Modelo){return Modelo.Status;}
//------------------------------------------------------------------------------------------------------
