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
    time_t tp;
    struct tm lt;
    time(&tp);
    lt = *localtime(&tp);
    int data=1000000*lt.tm_mday+10000*(lt.tm_mon+1)+1900+lt.tm_year;
    pMatriz->Data = data;
}
void SetHora_Ultima_Atualizacao_Matriz(tMatriz* pMatriz){
    time_t tp;
    struct tm lt;
    time(&tp);
    lt = *localtime(&tp);
	int hora=100*lt.tm_hour+lt.tm_min;
    pMatriz->Hora_Ultima_Atualizacao_Matriz = hora;
}
//------------------------------------------------------------------------------------------------------

// GETS
int GetData(tMatriz* pMatriz){
    return pMatriz->Data;
}
int GetHora_Ultima_Atualizacao_Matriz(tMatriz* pMatriz){
    return pMatriz->Hora_Ultima_Atualizacao_Matriz;
}
//------------------------------------------------------------------------------------------------------

void Inicia_Matriz(tMatriz* pMatriz){
    SetData(pMatriz);
    pMatriz->Total_De_Voos = 0;
    SetHora_Ultima_Atualizacao_Matriz(pMatriz);
    int i = 0,j = 0;
    for ( i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            Inicializa_Item_Matriz(&pMatriz->M[i][j]);
        }
    }
}
int Insere_Voo_Matriz(tMatriz* pMatriz,TVoo* Voo){
    //Vai ser pego a hora para achar a posicao na matriz e
    // dps chamar a funcao da lista daquela posicao da matriz
    //SetHora_Ultima_Atualizacao_Matriz(pMatriz);
    char Decolagem[3];
    char Previsto[3];
    memcpy( Decolagem, &Voo->Hora_Decola[0], 2);
    memcpy( Previsto, &Voo->Hora_Previsto[0], 2);
    Decolagem[2] = '\0'; // adiciona o terminador de linha
    Previsto[2] = '\0'; // adiciona o terminador de linha
    int Hora_Decola = atoi(Decolagem);
    int Hora_Previsto = atoi(Previsto);
    int aux = 0;
    aux = Insere_Voo(&pMatriz->M[Hora_Decola][Hora_Previsto].Lista,Voo);
    if (aux == 1) {
        SetNumero_de_Voos(&pMatriz->M[Hora_Decola][Hora_Previsto],1);
        SetHora_Ultima_Atualizacao_Matriz(pMatriz);
        SetUltima_Atualizacao(&pMatriz->M[Hora_Decola][Hora_Previsto]);
        return 1;
    }else{
        return 0;
    }
}



TVoo Remove_Voo_Matriz(tMatriz* pMatriz,int VID){ //Função retorna uma variavel do tipo TVoo, por isso então, Criei uma variavel do mesmo tipo para receber o retorno dessa função.//YURICABAÇO//
    TVoo Voo;
    InicializaVoo(&Voo);
    int aux = 0 ;
    for ( size_t i = 0; i < count; i++) {
        for ( size_t j = 0; j < count; j++) {
            aux = Remove_Voo(&pMatriz->M[i][j].Lista,&Voo,VID);
            if(aux == 1){
                SetNumero_de_Voos(&pMatriz->M[i][j],0);
                SetHora_Ultima_Atualizacao_Matriz(pMatriz);
            }
        }
    }
    return Voo;
}




TVoo Procurar_Voo_Matriz(tMatriz* pMatriz,int VID){ //Função retorna endereço para ponteiro do Tipo TVoo (Endereço de um Voo dentro de uma celula da lista encadeada.)//
    TVoo Voo;
    InicializaVoo(&Voo);
    for (size_t i = 0; i < count; i++) {
        for (size_t j = 0; j < count; j++) {
            Procura_Voo(&pMatriz->M[i][j].Lista,&Voo,VID);
        }
    }
    return Voo;
}




void Imprimir_Voos_Decolagem_Pouso(tMatriz* pMatriz,char* Hora_Decola,char* Hora_Previsto){
    TLista* Aux;
    char Decolagem[3];
    char Previsto[3];
    memcpy( Decolagem,&Hora_Decola[0], 2);
    memcpy( Previsto,&Hora_Previsto[0], 2);
    Decolagem[2] = '\0'; // adiciona o terminador de linha
    Previsto[2] = '\0'; // adiciona o terminador de linha
    int iHDecola = atoi(Decolagem);
    int iHPrevisto = atoi(Previsto);
    Aux= &pMatriz->M[iHDecola][iHPrevisto].Lista;
    if(pMatriz->M[iHDecola][iHPrevisto].Numero_de_Voos > 0){
    printf("Voos que pousarao na faixa de horario:->Decolagem: %d Horas /n->Previsao: %d Horas\n",iHDecola,iHPrevisto );
    Imprime_Lista(Aux);}
}




void Imprimir_Voos_Decolagem(tMatriz* pMatriz, char* Hora_Decola){
  TLista* Aux;
  int i;
  char Decolagem[3];
  memcpy(Decolagem,&Hora_Decola[0],2);
  Decolagem[2] = '\0';
  int iHDecola = atoi(Decolagem);
  for ( i = 0; i < count; i++) {
      Aux = &pMatriz->M[iHDecola][i].Lista;
      if(pMatriz->M[iHDecola][i].Numero_de_Voos > 0){
      printf("Voos que decolarao na faixa de horario:\n->Decolagem: %d Horas /n->Previsao: %d Horas\n",iHDecola,i );
      Imprime_Lista(Aux);}
  }
}

void Imprimir_Voos_Pouso(tMatriz* pMatriz,char* Hora_Previsto){
  TLista* Aux=NULL;
  int i;
  char Previsto[3];
  memcpy(Previsto,&Hora_Previsto[0],2);
  Previsto[2] = '\0';
  int iPrevisto = atoi(Previsto);
  for(i = 0; i < count; i++){
    Aux = &pMatriz->M[i][iPrevisto].Lista;
    if(pMatriz->M[i][iPrevisto].Numero_de_Voos > 0){
    printf("Voos que pousarao na faixa de horario:\n->Partida: %d Horas\n->Previsao: %d Horas\n",i,iPrevisto );
    Imprime_Lista(Aux);}
  }
}




void Imprimir_Matriz(tMatriz* pMatriz){
    TLista* Aux;
    int i,j;
    for ( i = 0; i < count; i++) {
        for ( j = 0; j < count; j++) {
            Aux= &pMatriz->M[i][j].Lista;
            if(pMatriz->M[i][j].Numero_de_Voos > 0){
            printf("---------\n->Partida: %d Horas\n->Previsao:%d Horas\n",i,j );
            Imprime_Lista(Aux);}
        }
    }
}




void Encontrar_Faixa_Voos_Maior(tMatriz* pMatriz){
  int i,j,MDecolagem = 0,MPrevisao = 0,aux = 0;
  for ( i = 0; i < count; i++) {
      for ( j = 0; j < count; j++) {
          if (pMatriz->M[i][j].Numero_de_Voos>aux) {
             aux = pMatriz->M[i][j].Numero_de_Voos;
             MDecolagem = i;
             MPrevisao =j;
          }
      }
  }
  if(aux == 0){
      printf("------Nenhum voo cadastrado ate o momento------\n");
  }else{
      printf("Faixa de numeros menor: \n->Numero de voos: %d\n->Horario de Decolagem: %d\n->Horario Previso: %d\n",pMatriz->M[MDecolagem][MPrevisao].Numero_de_Voos,MDecolagem,MPrevisao );
  }
}




void Encontrar_Faixa_Voos_Menor(tMatriz* pMatriz){
    int i,j,MDecolagem = 0,MPrevisao = 0,aux = sizeof(int);
    for ( i = 0; i < count; i++) {
        for ( j = 0; j < count; j++) {
            if (pMatriz->M[i][j].Numero_de_Voos<aux && pMatriz->M[i][j].Numero_de_Voos !=0 ) {
               aux = pMatriz->M[i][j].Numero_de_Voos;
               MDecolagem = i;
               MPrevisao =j;
            }
        }
    }
    if(aux == sizeof(int)){
        printf("-----Nenhum voo cadastrado ate o momento------\n");
    }else{
        printf("Faixa de numeros menor: \n->Numero de voos: %d\n->Horario de Decolagem: %d\n->Horario Previso: %d\n",pMatriz->M[MDecolagem][MPrevisao].Numero_de_Voos,MDecolagem,MPrevisao );
    }
}



void Encontrar_Lista_Voos_Mais_Recente(tMatriz* pMatriz){
/*Encontrar lista de voos mais recentemente alterada. Mostra indices i e j
da posição encontrada e horário da última alteração*/
  int aux = 0,i,j,auxJ,auxI;
  for ( i = 0; i < count; i++) {
    for ( j = 0; j < count; j++) {
      if(pMatriz->M[i][j].Hora_Ultima_Atualizacao > aux){
        aux = pMatriz->M[i][j].Hora_Ultima_Atualizacao;
        auxI = i;
        auxJ = j;
      }
    }
  }
  if(aux != 0){
    int converthora = aux/100;
    int convertmin = aux - converthora*100;
    printf("Na Hora atual: %d:%d\n A lista de Voo mais recente se encontra:\nNa posicao: Linha = %d \\ Coluna = %d\n",converthora,convertmin,auxI,auxJ);

  }else{
    printf("Nenhum voo cadastrado ate o momento\n");
  }
}




void Encontrar_Lista_Voos_Menos_Recente(tMatriz* pMatriz){
  int aux = 9999,i,j,auxJ,auxI;
  for ( i = 0; i < count; i++) {
    for ( j = 0; j < count; j++) {
      if(pMatriz->M[i][j].Hora_Ultima_Atualizacao < aux){
        aux = pMatriz->M[i][j].Hora_Ultima_Atualizacao;
        auxI = i;
        auxJ = j;
      }
    }
  }
  if(aux != 9999){
    int converthora = aux/100;
    int convertmin = aux - converthora*100;
    printf("Hora: %d:%d\nNa posicao: Linha = %d \\ Coluna = %d\n",converthora,convertmin,auxI,auxJ);

  }else{
    printf("Nenhum voo cadastrado ate o momento\n");
  }
}



void Matriz_Esparca(tMatriz* pMatriz){
  int i = 0 ,j = 0 ,semcadastro = 0,comcadastro = 0;
  for ( i = 0; i < count; i++) {
    for ( j = 0; j < count; j++) {
      if (pMatriz->M[i][j].Numero_de_Voos >0) {
        comcadastro+=1;
      }else{
        semcadastro+=1;
      }
    }
  }
  if (semcadastro*2>comcadastro) {
    printf("A matriz e esparca\n");
  }else{
    printf("A matriz nao e esparca\n");
  }
}
