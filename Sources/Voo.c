
#include "../Libs/Voo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void InicializaVoo(Voo* Modelo){
  Modelo->VID = 0;
  Modelo->Hora_Decola = 0;
  Modelo->Minuto_Decola = 0;
  Modelo->Hora_Previsto = 0;
    Modelo->Minuto_Previsto= 0;
  Modelo->Pista = 0;
  strcpy(Modelo->Aeroporto_Chegada,"");
  strcpy(Modelo->Aeroporto_Partida,"");}
void SetVID(Voo* Modelo){Modelo->VID=(rand()%1000);}
void SetHora_Minuto_Decola(Voo* Modelo){
  printf("Horas da partida:");
  scanf("%d",&Modelo->Hora_Decola);
  printf("\nMinutos da partida:");
  scanf("%d",&Modelo->Minuto_Decola);}
void SetHora_Minuto_Previsto(Voo* Modelo){
  printf("Horas da chegada prevista:");
  scanf("%d",&Modelo->Hora_Previsto);
  printf("\nMinutos da chegada prevista:");
  scanf("%d",&Modelo->Minuto_Previsto);}
void SetPista(Voo* Modelo){
  printf("\nPista de decolagem?:");
  scanf("%d",&Modelo->Pista );}
void SetAeroporto_Partida(Voo* Modelo){
  printf("\nAeroporto de partida:");
  fgets(Modelo->Aeroporto_Partida,30,stdin);}
void SetAeroporto_Chegada(Voo* Modelo){
  printf("\nAeroporto de chegada:");
  fgets(Modelo->Aeroporto_Chegada,30,stdin);}
void GetVID(Voo Modelo){printf("\n%d",Modelo.VID);}
void GetHora_Minuto_Decola(Voo Modelo){printf("\n%d:%d",Modelo.Hora_Decola,Modelo.Minuto_Decola);}
void GetHora_Minuto_Previsto(Voo Modelo){printf("\n%d:%d",Modelo.Hora_Previsto,Modelo.Minuto_Previsto);}
void GetPista(Voo Modelo){printf("\nPista:%d",Modelo.Pista);}
void GetAeroporto_Partida(Voo Modelo){printf("\n%s",Modelo.Aeroporto_Partida);}
void GetAeroporto_Chegada(Voo Modelo){printf("\n%s",Modelo.Aeroporto_Chegada);}
