#include "../Libs/Voo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//Inicializacao
void InicializaVoo(Voo* Modelo){
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
void SetVID(Voo* Modelo){
  srand(time(NULL));
  Modelo->VID=(rand()%1000);}
void SetHora_Minuto_Decola(Voo* Modelo, int hora,int minuto){
  Modelo->Hora_Decola = hora;
  Modelo->Minuto_Decola = minuto;
void SetHora_Minuto_Previsto(Voo* Modelo,int hora,int minuto){
  Modelo->Hora_Previsto = hora;
  Modelo->Minuto_Previsto = minuto;}
void SetPista(Voo* Modelo){
  Modelo->Pista;}
void SetAeroporto_Partida(Voo* Modelo){
  Modelo->Aeroporto_Partida;}
void SetAeroporto_Chegada(Voo* Modelo){
  Modelo->Aeroporto_Chegada;}
//------------------------------------------------------------------------------------------------------

// GETS
//TODO:Retornar ao invez de printar os valores repassados
void GetVID(Voo Modelo){printf("%d",Modelo.VID);}
void GetHora_Minuto_Decola(Voo Modelo){printf("%d:%d",Modelo.Hora_Decola,Modelo.Minuto_Decola);}
void GetHora_Minuto_Previsto(Voo Modelo){printf("%d:%d",Modelo.Hora_Previsto,Modelo.Minuto_Previsto);}
void GetPista(Voo Modelo){printf("%d",Modelo.Pista);}
void GetAeroporto_Partida(Voo Modelo){printf("%s",Modelo.Aeroporto_Partida);}
void GetAeroporto_Chegada(Voo Modelo){printf("%s",Modelo.Aeroporto_Chegada);}
//------------------------------------------------------------------------------------------------------
