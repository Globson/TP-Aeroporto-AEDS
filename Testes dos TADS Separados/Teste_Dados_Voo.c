#include <stdio.h>
#include <stdlib.h>
#include "../Libs/Dados_Voo.h"
int main(int argc, char const *argv[]) {
  TVoo Voo1,*pVoo1,Voo2,*pVoo2;
  char horad[10]="13:50",horap[10]="14:50",aeroc[10]="CPD",aerop[10]="ADC";
  char horad2[10]="14:33",horap2[10]="16:55",aeroc2[10]="ASD",aerop2[10]="ASP";
  int pista=2,pista2,VID1,pista3=3,pista4,VID2;
  pVoo1=&Voo1;
  pVoo2=&Voo2;
  char* pchar,*pchar2,*pchar3,*pchar4;
  char* pchar5,*pchar6,*pchar7,*pchar8;

  InicializaVoo(pVoo1);
  SetVID(pVoo1);
  SetPista(pVoo1,pista);
  SetHora_Decola(pVoo1,horad);
  SetHora_Previsto(pVoo1,horap);
  SetAeroporto_Partida(pVoo1,aerop);
  SetAeroporto_Chegada(pVoo1,aeroc);
  pista2=GetPista(pVoo1);
  pchar=GetHora_Decola(pVoo1);
  pchar2=GetHora_Previsto(pVoo1);
  pchar3=GetAeroporto_Chegada(pVoo1);
  pchar4=GetAeroporto_Partida(pVoo1);
  VID1=GetVID(pVoo1);
  printf("VID: %d\n",VID1);
  printf("Hora de decolagem: %s\nHora de pouso previsto: %s\n",pchar,pchar2);
  printf("Pista: %d\n",pista2);
  printf("Aeroporto de chegada: %s\nAeroporto de partida: %s\n\n\n",pchar3,pchar4);


  InicializaVoo(pVoo2);
  SetVID(pVoo2);
  SetPista(pVoo2,pista3);
  SetHora_Decola(pVoo2,horad2);
  SetHora_Previsto(pVoo2,horap2);
  SetAeroporto_Partida(pVoo2,aerop2);
  SetAeroporto_Chegada(pVoo2,aeroc2);
  pista4=GetPista(pVoo2);
  pchar5=GetHora_Decola(pVoo2);
  pchar6=GetHora_Previsto(pVoo2);
  pchar7=GetAeroporto_Chegada(pVoo2);
  pchar8=GetAeroporto_Partida(pVoo2);
  VID2=GetVID(pVoo2);
  printf("VID: %d\n",VID2);
  printf("Hora de decolagem: %s\nHora de pouso previsto: %s\n",pchar5,pchar6);
  printf("Pista: %d\n",pista4);
  printf("Aeroporto de chegada: %s\nAeroporto de partida: %s\n",pchar7,pchar8);

//////////////////COOOOOMPILOU PORRAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/////////////////////////
  return 0;
}
