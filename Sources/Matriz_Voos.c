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
    strcpy(pMatriz->Hora_Ultima_Atualizacao,__TIME__);//TODO:Consetar o __TIME__.Apenas pega o horario da compilacao
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
            Inicializa_Item_Matriz(pMatriz->M[i][j]);
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
    int aux = 0;
    aux = Insere_Voo(&pMatriz->M[Hora_Decola][Hora_Previsto]->Lista,Voo);
    if (aux == 1) {
        SetNumero_de_Voos(pMatriz->M[Hora_Decola][Hora_Previsto],pMatriz->M[Hora_Decola][Hora_Previsto]->Numero_de_Voos+1);
        SetHora_Ultima_Atualizacao(pMatriz);
        return 1;
    }else{
        return 0;
    }
}



TVoo* Remove_Voo_Matriz(tMatriz* pMatriz,int VID){
    TVoo* Voo;
    int aux = 0 ;
    for ( size_t i = 0; i < count; i++) {
        for ( size_t j = 0; j < count; j++) {
            aux = Remove_Voo(&pMatriz->M[i][j]->Lista,Voo,VID);
            if(aux == 1){
                SetNumero_de_Voos(pMatriz->M[i][j],pMatriz->M[i][j]->Numero_de_Voos-1);
                SetHora_Ultima_Atualizacao(pMatriz);
            }
        }
    }
    return Voo;
}




TVoo* Procurar_Voo_Matriz(tMatriz* pMatriz,int VID){
    TVoo* Voo;
    for (size_t i = 0; i < count; i++) {
        for (size_t j = 0; j < count; j++) {
            Procura_Voo(&pMatriz->M[i][j]->Lista,Voo,VID);
        }
    }
    return Voo;
}




void Imprimir_Voos_Decolagem_Pouso(tMatriz* pMatriz,char* Hora_Decola,char* Hora_Previsto){
    TCelula* Aux;
    char Decolagem[3];
    char Previsto[3];
    memcpy( Decolagem,&Hora_Decola[0], 2);
    memcpy( Previsto,&Hora_Previsto[0], 2);
    Decolagem[2] = '\0'; // adiciona o terminador de linha
    Previsto[2] = '\0'; // adiciona o terminador de linha
    int iHDecola = atoi(Decolagem);
    int iHPrevisto = atoi(Previsto);
    Aux= pMatriz->M[iHDecola][iHPrevisto]->Lista.pPrimeiro->pProx;
    printf("|Decolagem: %d /n Previsao: %d\n|",iHDecola,iHPrevisto );
    while(Aux != NULL){
        printf("|VID: %d\n",(Aux->Item.VID) );
        printf("|Pista: %d\n",(Aux->Item.Pista));
        printf("|Aeroporto Partida: %s\n",(Aux->Item.Aeroporto_Partida));
        printf("|Aeroporto Chegada: %s/n",(Aux->Item.Aeroporto_Chegada));
        Aux=Aux->pProx;
    }
}




void Imprimir_Voos_Decolagem(tMatriz* pMatriz, char* Hora_Decola){
  TCelula* Aux;
  int i;
  char Decolagem[3];
  memcpy(Decolagem,&Hora_Decola[0],2);
  Decolagem[2] = '\0';
  int iHDecola = atoi(Decolagem);
  for ( i = 0; i < count; i++) {
      Aux = pMatriz->M[iHDecola][i]->Lista.pPrimeiro->pProx;
      printf("|Decolagem: %d /n Previsao: %d\n|",iHDecola,i );
      while (Aux != NULL) {
          printf("|VID: %d\n",(Aux->Item.VID) );
          printf("|Pista: %d\n",(Aux->Item.Pista));
          printf("|Aeroporto Partida: %s\n",(Aux->Item.Aeroporto_Partida));
          printf("|Aeroporto Chegada: %s/n",(Aux->Item.Aeroporto_Chegada));
          Aux=Aux->pProx;
      }
  }
}

void Imprimir_Voos_Pouso(tMatriz* pMatriz,char* Hora_Previsto){
  TCelula* Aux;
  int i;
  char Previsto[3];
  memcpy(Previsto,&Hora_Previsto[0],2);
  Previsto[2] = '\0';
  int iPrevisto = atoi(Previsto);
  for(i = 0; i < count; i++){
    Aux = pMatriz->M[i][iPrevisto]->Lista.pPrimeiro->pProx;
    printf("|Partida: %d\n Previsao: %d\n|",i,iPrevisto );
    while (Aux != NULL) {
      printf("|VID: %d\n",(Aux->Item.VID) );
      printf("|Pista: %d\n",(Aux->Item.Pista));
      printf("|Aeroporto Partida: %s\n",(Aux->Item.Aeroporto_Partida));
      printf("|Aeroporto Chegada: %s/n",(Aux->Item.Aeroporto_Chegada));
    }
  }
}




void Imprimir_Matriz(tMatriz* pMatriz){
    TCelula* Aux;
    int i,j;
    for ( i = 0; i < count; i++) {
        for ( j = 0; j < count; j++) {
            Aux= pMatriz->M[i][j]->Lista.pPrimeiro->pProx;
            printf("|Partida: %d\n Previsao: %d\n|",i,j );
            while(Aux != NULL){
              printf("|VID: %d\n",(Aux->Item.VID) );
              printf("|Pista: %d\n",(Aux->Item.Pista));
              printf("|Aeroporto Partida: %s\n",(Aux->Item.Aeroporto_Partida));
              printf("|Aeroporto Chegada: %s\n",(Aux->Item.Aeroporto_Chegada));
            }
        }
    }
}




void Encontrar_Faixa_Voos_Maior(tMatriz* pMatriz){
  int i,j,MDecolagem = 0,MPrevisao = 0,aux = 0;
  for ( i = 0; i < count; i++) {
      for ( j = 0; j < count; j++) {
          if (pMatriz->M[i][j]->Numero_de_Voos>aux) {
             aux = pMatriz->M[i][j]->Numero_de_Voos;
             MDecolagem = i;
             MPrevisao =j;
          }
      }
  }
  if(aux == 0){
      printf("Nenhum voo cadastrado ate o momento\n");
  }else{
      printf("Numero de voos: %d\nHorario de Decolagem: %d\nHorario Previso: %d\n",pMatriz->M[MDecolagem][MPrevisao]->Numero_de_Voos,MDecolagem,MPrevisao );
  }
}




void Encontrar_Faixa_Voos_Menor(tMatriz* pMatriz){
    int i,j,MDecolagem = 0,MPrevisao = 0,aux = pMatriz->M[0][0]->Numero_de_Voos;
    for ( i = 0; i < count; i++) {
        for ( j = 0; j < count; j++) {
            if (pMatriz->M[i][j]->Numero_de_Voos<aux) {
               aux = pMatriz->M[i][j]->Numero_de_Voos;
               MDecolagem = i;
               MPrevisao =j;
            }
        }
    }
    if(aux == 0){
        printf("Nenhum voo cadastrado ate o momento\n");
    }else{
        printf("Numero de voos: %d\nHorario de Decolagem: %d\nHorario Previso: %d\n",pMatriz->M[MDecolagem][MPrevisao]->Numero_de_Voos,MDecolagem,MPrevisao );
    }
}


//TODO:Arrumar daqui pra baixo

void Encontrar_Lista_Voos_Mais_Recente(tMatriz* pMatriz){

  int Aux,i,j,fi,fc,ultm;
  ultm=pMatriz->M[0][0]->Ultima_Atualizacao;
  for(i = 0; i < count; i++){
    for(j = 0; j < count; j++){
      Aux=pMatriz->M[i][j]->Ultima_Atualizacao;
      if(ultm<Aux){
        ultm=Aux;
        fi=i;
        fc=j;
      }
    }
  }

  //printf("Hora da ultima atualização\n",SetHora_Ultima_Atualizacao(pMatriz->M[fi][fc]) );//Queria fazer assim;
  char Hora[3];
  char Minuto[3];
  memcpy( Hora, &pMatriz->Hora_Ultima_Atualizacao[0], 2);//YURI não sei se é assim que usa essa função, tentei me espelhar na sua utilização;
  memcpy( Minuto, &pMatriz->Hora_Ultima_Atualizacao[0], 2);//Não entendi o formato do Hora_Ultima_Atualizacao
  Hora[2] = '\0'; // adiciona o terminador de linha
  Minuto[2] = '\0'; // adiciona o terminador de linha
  int Hora_Ultima_Atualizacao = atoi(Hora);
  int Minuto_Ultima_Atualizacao = atoi(Minuto);
  printf("Ultima Atualização esta na faixa: Linha:%d Coluna: %d\n", fi,fc );
  printf("Hora da ultima atualização: %d:%d\n",Hora_Ultima_Atualizacao, Minuto_Ultima_Atualizacao);
}




void Encontrar_Lista_Voos_Menos_Recente(tMatriz* pMatriz){
  int Aux,i,j,fi,fc,ultm;
  ultm=pMatriz->M[0][0]->Ultima_Atualizacao;
  for(i = 0; i < count; i++){
    for(j = 0; j < count; j++){
      Aux=pMatriz->M[i][j]->Ultima_Atualizacao;
      if(ultm>Aux){
        ultm=Aux;
        fi=i;
        fc=j;
      }
    }
  }
  char Hora[3];
  char Minuto[3];
  memcpy( Hora, &pMatriz->Hora_Ultima_Atualizacao[0], 2);//YURI não sei se é assim que usa essa função, tentei me espelhar na sua utilização;
  memcpy( Minuto, &pMatriz->Hora_Ultima_Atualizacao[0], 2);//Não entendi o formato do Hora_Ultima_Atualizacao
  Hora[2] = '\0'; // adiciona o terminador de linha
  Minuto[2] = '\0'; // adiciona o terminador de linha
  int Hora_Ultima_Atualizacao = atoi(Hora);
  int Minuto_Ultima_Atualizacao = atoi(Minuto);
  printf("Atualização mais antiga esta na faixa: Linha:%d Coluna: %d\n", fi,fc );
  printf("Hora da atualização mais aintga: %d:%d\n",Hora_Ultima_Atualizacao, Minuto_Ultima_Atualizacao);
}



int Matriz_Esparca(tMatriz* pMatriz){
  int x,i,j,contador=0;
  for(i = 0; i < count;i++){
    for(j = 0; i < count; j++){
      if(pMatriz->M[i][j]==0){
        contador++;
      }
    }
  }
  x=count-contador;
  if(contador>(2*x)){ // se o contador for maior que o dobro de posições com voos;
  printf("Matriz é esparça\n");}
  return 0;}
