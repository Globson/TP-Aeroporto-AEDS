
#include "../Libs/Voo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void InicializaVoo(Voo* Modelo) {
  Modelo->VID = 0;
  Modelo->Hora_Decola = 0;
  Modelo->Hora_Pouso = 0;
  Modelo->Hora_Previsto = 0;
  Modelo->Pista = 0;
  strcpy(Modelo->Aeroporto_Chegada,"");
  strcpy(Modelo->Aeroporto_Partida,"");

}
void SetVID(Voo* Modelo,int Hora_decolagem,int Hora_de_pouso,int Hora_previsto,int Numero_Pista){

}  //Variaveis declaradas para atribuições dentro da struct.
void GetVID(Voo Modelo){printf("%d",Modelo.VID);}
void GetHora_Decola(Voo Modelo){printf("%d",Modelo.Hora_Decola);}
void GetHora_Pouso(Voo Modelo){printf("%d",Modelo.Hora_Pouso);}
void GetHora_Previsto(Voo Modelo){printf("%d",Modelo.Hora_Previsto);}
void GetPista(Voo Modelo){printf("%d",Modelo.Pista);}
void GetHora_Partida(Voo Modelo){printf("%s",Modelo.Aeroporto_Partida);}
void GetAeroporto_Chegada(Voo Modelo){printf("%s",Modelo.Aeroporto_Chegada);}
