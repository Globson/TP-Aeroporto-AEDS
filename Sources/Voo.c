
#include "../Libs/Voo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void InicializaVoo(Voo* Modelo) {
  Modelo->VID = 0;
  Modelo->Hora_Decola = 0;
  Modelo->Minuto_Decola = 0;
  Modelo->Hora_Previsto = 0;
    Modelo->Minuto_Previsto= 0;
  Modelo->Pista = 0;
  strcpy(Modelo->Aeroporto_Chegada,"");
  strcpy(Modelo->Aeroporto_Partida,"");

}
void SetVID(Voo* Modelo,int Hora_decolagem,int Hora_de_pouso,int Hora_previsto,int Numero_Pista){
int i;
  srand(time(NULL));
  Modelo->VID(%d,rand()%1000);
  printf("Horario do voo, Horas,Minutos\n");
  scanf("%d, %d\n",Modelo->Hora_Decola, Modelo->Minuto_Decola );
  printf("Horario previsto de chegada, Horas,Minutos\n");
  scanf("%d, %d\n",Modelo->Hora_Previsto, Modelo->Minuto_Previsto );
  printf("Aeroporto de partida?\n");
  scanf("30%s\n", Aeroporto_Partida );
  printf("Aeroporto de chegada?\n");
  scanf("30%s\n", Aeroporto_Chegada );
  printf("Pista de decolagem?\n");
  scanf("%d\n",Modelo->Pista );

}  //Variaveis declaradas para atribuições dentro da struct.
void GetVID(Voo Modelo){printf("%d",Modelo.VID);}
void GetHora_Decola(Voo Modelo){printf("%d",Modelo.Hora_Decola);}
void GetHora_Decola(Voo Modelo){printf("%d",Modelo.Minuto_Decola);}
void GetHora_Previsto(Voo Modelo){printf("%d",Modelo.Hora_Previsto);}
void GetHora_Decola(Voo Modelo){printf("%d",Modelo.Minuto_Previsto);}
void GetPista(Voo Modelo){printf("%d",Modelo.Pista);}
void GetHora_Partida(Voo Modelo){printf("%s",Modelo.Aeroporto_Partida);}
void GetAeroporto_Chegada(Voo Modelo){printf("%s",Modelo.Aeroporto_Chegada);}
