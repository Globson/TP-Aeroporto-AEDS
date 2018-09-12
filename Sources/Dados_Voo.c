#include "../Libs/Dados_Voo.h"
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
  strcpy(Modelo->Aeroporto_Partida,"");
  //strcpy(Modelo->CiaAerea,"");
  //strcpy(Modelo->Status,"");}
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
  Modelo->Minuto_Decola = minuto;}
void SetHora_Minuto_Previsto(Voo* Modelo,int hora,int minuto){
  Modelo->Hora_Previsto = hora;
  Modelo->Minuto_Previsto = minuto;}
void SetPista(Voo* Modelo,int pista){
  Modelo->Pista = pista;}
void SetAeroporto_Partida(Voo* Modelo,char aeroporto[]){
  strcpy(Modelo->Aeroporto_Partida,aeroporto);}
void SetAeroporto_Chegada(Voo* Modelo,char aeroporto[]){
  strcpy(Modelo->Aeroporto_Chegada,aeroporto);}
//void SetCiaAerea(Voo* Modelo,char ciaaerea[]){
  //strcpy(Modelo->CiaAerea,ciaaerea);}
//void SetStatus(Voo* Modelo,char status[]){
  //strcpy(Modelo->Status,status);}
//------------------------------------------------------------------------------------------------------

// GETS
//TODO:Retornar ao invez de printar os valores repassados
int GetVID(Voo Modelo){return Modelo.VID;}
 //TODO:Verificar como retornar de forma apropriada as horas e minutos juntos
void GetHora_Minuto_Decola(Voo Modelo){printf("%d:%d",Modelo.Hora_Decola,Modelo.Minuto_Decola);}
void GetHora_Minuto_Previsto(Voo Modelo){printf("%d:%d",Modelo.Hora_Previsto,Modelo.Minuto_Previsto);}
int GetPista(Voo Modelo){return Modelo.Pista;}
//TODO: Verificar possivel  quebra de seguranca com o retorno do endereco do Modelo
char* GetAeroporto_Partida(Voo Modelo){return Modelo.Aeroporto_Partida;}
char* GetAeroporto_Chegada(Voo Modelo){return Modelo.Aeroporto_Chegada;}
//char* GetCiaAerea(Voo Modelo){return Modelo.CiaAerea;}
//char* GetStatus(Voo Modelo){return Modelo.Status;}
//------------------------------------------------------------------------------------------------------
