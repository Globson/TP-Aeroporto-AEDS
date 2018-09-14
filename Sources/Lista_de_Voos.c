#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Libs/Lista_de_Voos.h"
#include "../Libs/Dados_Voo.h"

//Inicalizacao//
void Inicia_Lista(TLista* pLista){
  pLista->pPrimeiro = (struct Celula*) malloc(sizeof(TCelula));
  pLista->pUltimo = pLista->pPrimeiro;
  pLista->pPrimeiro->pProx= NULL;
  InicializaVoo(pLista->pPrimeiro->Item);}


int Lista_Vazia(TLista* pLista){
  return(pLista->pPrimeiro == pLista->pUltimo);} //Retorna 1 para caso a afirmação seja verdade e 0 caso não.//


int Insere_Voo(TLista* pLista,TVoo* pVoo){             //Se inserido com sucesso retorna 1, se nao foi inserido por falta de memoria de malloc retorna 0.//
  TCelula *pAux_Prox,*pAux_Atual,*pNovo;
  pNovo=(TCelula*)malloc(sizeof(TCelula));
  if(pNovo == NULL){return 0;}
  pNovo->Item = pVoo;
  pAux_Atual=pLista->pPrimeiro;
  pAux_Prox=pLista->pPrimeiro->pProx;
  while(pAux_Prox != NULL){
    if(strcmp((pAux_Prox->Item->Hora_Decola),(pVoo->Hora_Decola))>=0){break;}
    pAux_Atual = pAux_Prox;
    pAux_Prox = pAux_Prox->pProx;}
  pNovo->pProx = pAux_Prox;
  pAux_Atual->pProx = pNovo;
  if(pLista->pUltimo->pProx != NULL){
    pLista->pUltimo = pLista->pUltimo->pProx;
    pLista->pUltimo->pProx = NULL;}
  return 1;}



TVoo* Remove_Voo(TLista* pLista,int VID_R){    //Essa função retorna o ponteiro do ItemVoo correspondente a celula eliminada da lista e NULL caso VID n seja encontrado.//
  TCelula *pAux_Atual,*pAux_Prox;
  TVoo* pVoo_Aux;
  if(pLista->pPrimeiro->pProx == NULL){return 0;}
  pAux_Atual = pLista->pPrimeiro;
  pAux_Prox = pLista->pPrimeiro->pProx;
  while(pAux_Prox != NULL && pAux_Prox->Item->VID != VID_R ){
            pAux_Atual = pAux_Prox;
            pAux_Prox = pAux_Prox->pProx;}
  if(pAux_Prox != NULL){
    pVoo_Aux = pAux_Prox->Item;
    pAux_Atual->pProx = pAux_Prox->pProx;
    free(pAux_Prox);
    if(pLista->pUltimo->pProx != NULL){
      pLista->pUltimo = pLista->pUltimo->pProx->pProx;
      pLista->pUltimo->pProx = NULL;}
      return pVoo_Aux;}
    return NULL;}



TVoo* Procura_Voo(TLista* pLista,int VID_P){ // A função devolve o endereço do TipoVoo que contem o VID entrado e NULL caso n exista.//
  TCelula* Aux;
  Aux= pLista->pPrimeiro->pProx;
  while(Aux !=NULL && Aux->Item->VID != VID_P){
    Aux=Aux->pProx;}
  if(Aux->Item->VID == VID_P){
    return Aux->Item;}
<<<<<<< HEAD
    else{return NULL;}
=======

//ATENÇÃO APAGAR FUNÇÃO IMPRIME ANTES DE ENTREGAR// ->> FUNÇÃO CRIADA APENAS PARA TESTE DE LISTA<<-------
void Imprime_Lista(TLista* pLista){ //--------------->> Função Apenas para teste separado <<----------------
    TCelula* pAux;
    pAux = pLista->pPrimeiro->pProx;
    while(pAux != NULL){
      printf("-------Inicio de Celula-------\n");
      printf("VID: %d\n",pAux->Item->VID);
      printf("Hora de Decolagem: %s\n",pAux->Item->Hora_Decola);
      printf("Hora de Pouso Previsto: %s\n",pAux->Item->Hora_Previsto);
      printf("Numero da Pista: %d\n",pAux->Item->Pista);
      printf("Aeroporto de Chegada: %s\n",pAux->Item->Aeroporto_Chegada);
      printf("Aeroporto de Partida: %s\n",pAux->Item->Aeroporto_Partida);
      printf("---------Fim da Celula--------");
      pAux=pAux->pProx;
    }
>>>>>>> e187772fa08729dfd8d3c2d15d65a13276853001
}
