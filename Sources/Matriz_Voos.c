#include "../Libs/Item_Matriz.h"
#include "../Libs/Lista_de_Voos.h"
#include "../Libs/Dados_Voo.h"
#include "../Libs/Matriz_Voos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define count  24



//------------------------------------------------------------------------------------------------------

// SETS
void SetData(tMatriz* pMatriz){
    strcpy(pMatriz->Data,__DATE__);
}
void SetHora_Ultima_Atualizacao(tMatriz* pMatriz){
    strcpy(pMatriz->Hora_Ultima_Atualizacao,__TIME__);
}
//------------------------------------------------------------------------------------------------------

// GETS
char* GetData(tMatriz* pMatriz){
    return pMatriz->Data;
}
char* GetHora_Ultima_Atualizacao(tMatriz* pMatriz){
    return pMatriz->Hora_Ultima_Atualizacao;
}
//------------------------------------------------------------------------------------------------------

void Inicia_Matriz(tMatriz* pMatriz){
    SetData(pMatriz);
    pMatriz->Total_De_Voos = 0;
    strcpy(pMatriz->Hora_Ultima_Atualizacao,"");
    int i = 0,j = 0;

    for ( i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            Inicializa_Matriz(pMatriz->M[i][j]);
        }
    }
}
int Insere_Voo_Matriz(tMatriz* pMatriz,TVoo* Voo){
    //Vai ser pego a hora para achar a posicao na matriz e
    // dps chamar a funcao da lista daquela posicao da matriz
    SetHora_Ultima_Atualizacao(pMatriz);
    char Decolagem[3];
    char Previsto[3];
    memcpy( Decolagem, &Voo->Hora_Decola[0], 2);
    memcpy( Previsto, &Voo->Hora_Previsto[0], 2);
    Decolagem[2] = '\0'; // adiciona o terminador de linha
    Previsto[2] = '\0'; // adiciona o terminador de linha
    int Hora_Decola = atoi(Decolagem);
    int Hora_Previsto = atoi(Previsto);
    Insere_Voo(pMatriz->M[Hora_Decola][Hora_Previsto]->pLista,Voo);
}
TVoo* Remove_Voo_Matriz(tMatriz* pMatriz,int VID){
    TVoo* Voo;
    for ( size_t i = 0; i < count; i++) {
        for ( size_t j = 0; j < count; j++) {
            Voo=Remove_Voo(pMatriz->M[i][j]->pLista,VID);
        }
    }
    return Voo;
}
TVoo* Procurar_Voo_Matriz(tMatriz* pMatriz,int VID){
    TVoo* Voo;
    for (size_t i = 0; i < count; i++) {
        for (size_t j = 0; j < count; j++) {
            Voo = Procura_Voo(pMatriz->M[i][j]->pLista,VID);
        }
    }
    return Voo;
}
void Imprimir_Voos_Decolagem_Pouso(tMatriz* pMatriz,char Hora_Decola,char Hora_Pouso){
    // TODO:Retirar o for's e usar hora_decola e hora_Chegada como especificado //tirei os GETS dos prints e aprece funcionar agr.ARYELS
    TCelula* Aux;
    int i,j;
    for ( i = 0; i < count; i++) {
        for ( j = 0; j < count; j++) {
            Aux= pMatriz->M[i][j]->pLista->pPrimeiro->pProx;
            printf("|Partida: %d /n Previsao: %d\n|",i,j );
            while(Aux != NULL){
                printf("|VID: %d\n",(Aux->Item->VID) );
                printf("|Pista: %d\n",(Aux->Item->Pista));
                printf("|Aeroporto Partida: %s\n",(Aux->Item->Aeroporto_Partida));
                printf("|Aeroporto Chegada: %s/n",(Aux->Item->Aeroporto_Chegada));
                Aux=Aux->pProx;
            }
        }
    }
}
void Imprimir_Voos_Decolagem(tMatriz* pMatriz, char Hora_Decola){//decola =i pouso=j, imprimir de acordo com a hora de decolagem passando por todos os horarios de pouso
  TCelula* Aux;
  int i,j;
  i=(int)Hora_Decola;
  for(j = 0;j < count; j++){
    Aux = pMatriz->M[i][j]->pLista->pPrimeiro->pProx;
    printf("|Partida: %d\n Previsao: %d\n|",i,j );
    while (Aux != NULL) {
      printf("|VID: %d\n",(Aux->Item->VID) );
      printf("|Pista: %d\n",(Aux->Item->Pista));
      printf("|Aeroporto Partida: %s\n",(Aux->Item->Aeroporto_Partida));
      printf("|Aeroporto Chegada: %s/n",(Aux->Item->Aeroporto_Chegada));
    }
  }
}

void Imprimir_Voos_Pouso(tMatriz* pMatriz,char Hora_Previsto){
  TCelula* Aux;
  int i,j;
  j=(int)Hora_Previsto;
  for(i = 0; i < count; i++){
    Aux = pMatriz->M[i][j]->pLista->pPrimeiro->pProx;
    printf("|Partida: %d\n Previsao: %d\n|",i,j );
    while (Aux != NULL) {
      printf("|VID: %d\n",(Aux->Item->VID) );
      printf("|Pista: %d\n",(Aux->Item->Pista));
      printf("|Aeroporto Partida: %s\n",(Aux->Item->Aeroporto_Partida));
      printf("|Aeroporto Chegada: %s/n",(Aux->Item->Aeroporto_Chegada));
    }
  }
}

void Imprimir_Matriz(tMatriz* pMatriz){
    TCelula* Aux;
    int i,j;
    for ( i = 0; i < count; i++) {
        for ( j = 0; j < count; j++) {
            Aux= pMatriz->M[i][j]->pLista->pPrimeiro->pProx;
            printf("|Partida: %d\n Previsao: %d\n|",i,j );
            while(Aux != NULL){
              printf("|VID: %d\n",(Aux->Item->VID) );
              printf("|Pista: %d\n",(Aux->Item->Pista));
              printf("|Aeroporto Partida: %s\n",(Aux->Item->Aeroporto_Partida));
              printf("|Aeroporto Chegada: %s\n",(Aux->Item->Aeroporto_Chegada));
            }
        }
    }
}
/*
void Encontrar_Faixa_Voos_Maior(Matriz* pMatriz);//Faixa que tem a maior quantidade de voos
void Encontrar_Faixa_Voos_Menor(Matriz* pMatriz);//Faixa que tem a menor quantidade de voos
void Encontrar_Lista_Voos_Mais_Recente(Matriz* pMatriz);
void Encontrar_Lista_Voos_Menos_Recente(Matriz* pMatriz);
int Matriz_Esparca(Matriz* pMatriz);*/
