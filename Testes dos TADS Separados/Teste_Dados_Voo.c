#include <stdio.h>
#include <stdlib.h>
#include "../Libs/Dados_Voo.h"
int main(int argc, char const *argv[]) {
  TVoo Voo1,*pVoo1;
  char horad[10]="13:50",horap[10]="14:50",aeroc[10]="CPD",aerop[10]="ADC";
  int pista=5,pista2;
  pVoo1=&Voo1;
  char* pchar,*pchar2,*pchar3,*pchar4;

  InicializaVoo(pVoo1);
  SetVID(pVoo1);
  SetPista(pVoo1,pista);
  SetHora_Decola(pVoo1,horad);
  SetHora_Previsto(pVoo1,horap);
  SetAeroporto_Partida(pVoo1,aerop);
  SetAeroporto_Chegada(pVoo1,aeroc);
  pista2=GetPista(Voo1);
  pchar=GetHora_Decola(Voo1);
  pchar2=GetHora_Previsto(Voo1);
  pchar3=GetAeroporto_Chegada(Voo1);
  pchar4=GetAeroporto_Partida(Voo1);
  printf("VID: %d\n",Voo1.VID);
  printf("Hora de decolagem: %s\nHora de pouso previsto: %s\n",pchar,pchar2);
  printf("Pista: %d\n",pista2);
  printf("Aeroporto de chegada: %s\nAeroporto de partida: %s\n",pchar3,pchar4);

//////////////////COOOOOMPILOU PORRAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/////////////////////////
  return 0;
}
