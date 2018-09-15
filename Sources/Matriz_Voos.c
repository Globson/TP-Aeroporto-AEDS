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
void SetData(TMatriz* pMatriz){
    strcpy(pMatriz->Data,__DATE__);
}
void SetHora_Ultima_Atualizacao(TMatriz* pMatriz){
    strcpy(pMatriz->Hora_Ultima_Atualizacao,__TIME__);
}
//------------------------------------------------------------------------------------------------------

// GETS
char* GetData(TMatriz* pMatriz){
    return pMatriz->Data;
}
char* GetHora_Ultima_Atualizacao(TMatriz* pMatriz){
    return pMatriz->Hora_Ultima_Atualizacao;
}
//------------------------------------------------------------------------------------------------------

void Inicia_Matriz(TMatriz* pMatriz){
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
int Insere_Voo_Matriz(TMatriz* pMatriz,TVoo* Voo){
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
    Insere_Voo(&pMatriz->M[Hora_Decola][Hora_Previsto]->Lista,Voo);
    (pMatriz->M[Hora_Decola][Hora_Previsto]->Numero_de_Voos+=1);//não consegui fazer com SetNumero_de_Voos
}



TVoo* Remove_Voo_Matriz(TMatriz* pMatriz,int VID){
    TVoo* Voo;
    for ( size_t i = 0; i < count; i++) {
        for ( size_t j = 0; j < count; j++) {
            Remove_Voo(&pMatriz->M[i][j]->Lista,Voo,VID);
            (pMatriz->M[i][j]->Numero_de_Voos-=1);//não consegui fazer com SetNumero_de_Voos
        }
    }
    return Voo;
}




TVoo* Procurar_Voo_Matriz(TMatriz* pMatriz,int VID){
    TVoo* Voo;
    for (size_t i = 0; i < count; i++) {
        for (size_t j = 0; j < count; j++) {
            Procura_Voo(&pMatriz->M[i][j]->Lista,Voo,VID);
        }
    }
    return Voo;
}




void Imprimir_Voos_Decolagem_Pouso(TMatriz* pMatriz,char Hora_Decola,char Hora_Pouso){
    // TODO:Retirar o for's e usar hora_decola e hora_Chegada como especificado //tirei os GETS dos prints e aprece funcionar agr.ARYELS
    TCelula* Aux;
    int i,j;
    for ( i = 0; i < count; i++) {
        for ( j = 0; j < count; j++) {
            Aux= pMatriz->M[i][j]->Lista.pPrimeiro->pProx;
            printf("|Partida: %d /n Previsao: %d\n|",i,j );
            while(Aux != NULL){
                printf("|VID: %d\n",(Aux->Item.VID) );
                printf("|Pista: %d\n",(Aux->Item.Pista));
                printf("|Aeroporto Partida: %s\n",(Aux->Item.Aeroporto_Partida));
                printf("|Aeroporto Chegada: %s/n",(Aux->Item.Aeroporto_Chegada));
                Aux=Aux->pProx;
            }
        }
    }
}




void Imprimir_Voos_Decolagem(TMatriz* pMatriz, char Hora_Decola,TVoo* Voo){//decola =i pouso=j, imprimir de acordo com a hora de decolagem passando por todos os horarios de pouso
  TCelula* Aux;
  int j;
  char i[3];
  memcpy(i, &Voo->Hora_Decola,2);
  i[2]='\0';
  int Hora_Decola= atoi(i);
  for(j = 0;j < count; j++){
    Aux = pMatriz->M[i][j]->pLista->pPrimeiro->pProx;
    printf("|Partida: %d\n Previsao: %d\n|",i,j );
    while (Aux != NULL) {
      printf("|VID: %d\n",(Aux->Item.VID) );
      printf("|Pista: %d\n",(Aux->Item.Pista));
      printf("|Aeroporto Partida: %s\n",(Aux->Item.Aeroporto_Partida));
      printf("|Aeroporto Chegada: %s/n",(Aux->Item.Aeroporto_Chegada));
    }
  }
}


//Fiz a mudança só em uma pq deu erro, não consegui usar essa função que vc usou pra converter pra int, sorry;

void Imprimir_Voos_Pouso(TMatriz* pMatriz,char Hora_Previsto){
  TCelula* Aux;
  int i,j;

  j=(int)Hora_Previsto;
  for(i = 0; i < count; i++){
    Aux = pMatriz->M[i][j]->Lista.pPrimeiro->pProx;
    printf("|Partida: %d\n Previsao: %d\n|",i,j );
    while (Aux != NULL) {
      printf("|VID: %d\n",(Aux->Item.VID) );
      printf("|Pista: %d\n",(Aux->Item.Pista));
      printf("|Aeroporto Partida: %s\n",(Aux->Item.Aeroporto_Partida));
      printf("|Aeroporto Chegada: %s/n",(Aux->Item.Aeroporto_Chegada));
    }
  }
}




void Imprimir_Matriz(TMatriz* pMatriz){
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




void Encontrar_Faixa_Voos_Maior(TMatriz* pMatriz){//Faixa que tem a maior quantidade de voos
  //percorre a matriz procurando a faixa com mais voos cadastrados, comparação feita ao fim da cada linha;
  int i,j,maior,contador=0,fi,fc;
  for(i=0;i<count;i++){
    for (j=0;j<count;j++){
      if(pMatriz->M[i][j] !=0){
        contador++;
        if(i==0 && j==0){
          maior=contador;
        }//fim if de inicialização maior;
      }//fim if contando voos adicionados
    }//fim for colunas;
    if (maior<contador){ //se o primeiro maior, for menor que o numero de voos da linha testado no for;
      maior=contador; //maior recebe numero de voos da linha
      fi=i;
      fc=j;
    }
  }//fez isso 24 vezes;
  printf("Faixa com mais voos: Linha: %d Coluna: %d\n ",fi,fc );
}




void Encontrar_Faixa_Voos_Menor(TMatriz* pMatriz){//Faixa que tem a menor quantidade de voos
//percorre a matriz procurando a faixa com mais zeros, comparação feita ao fim da cada linha;
int i,j,menor,contador=0,fi,fc;
for(i=0; i<count;i++){
  for (j = 0; j < count; j++){
    if(pMatriz->M[i][j]==0){
      contador++;
      if(i==0 && j==0){
        menor=contador;
      }//fim if de inicialização menor;
    }//fim if contando voos adicionados
  }//fim for colunas;
  if (menor<contador){ //se o primeiro maior, for menor que o numero de voos da linha testado no for;
    menor=contador; //menor recebe numero de zeros da linha
    fi=i;
    fc=j;
  }
}//fez isso 24 vezes;
printf("Faixa com menos voos: Linha: %d Coluna: %d\n ",fi,fc );
}




void Encontrar_Lista_Voos_Mais_Recente(TMatriz* pMatriz){

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




void Encontrar_Lista_Voos_Menos_Recente(TMatriz* pMatriz){
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



int Matriz_Esparca(TMatriz* pMatriz){
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
