#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Libs/Lista_de_Voos.h"
#include "../Libs/Dados_Voo.h"

//Inicalizacao//
void Inicia_Lista(TLista* pLista){
  pLista->pPrimeiro = (struct Celula*) malloc(sizeof(TCelula));
  pLista->pUltimo = pLista->pPrimeiro;
  pLista->pPrimeiro->pProx= NULL;}


int Lista_Vazia(TLista* pLista){
  return(pLista->pPrimeiro == pLista->pUltimo);} //Retorna 1 para caso a afirmação seja verdade e 0 caso não.//


int Insere_Voo(TLista* pLista,TVoo* pVoo){             //Se inserido com sucesso retorna 1, se nao foi inserido por falta de memoria de malloc retorna 0.//
  TCelula *pAux_Prox,*pAux_Atual,*pNovo;
  pNovo=(TCelula*)malloc(sizeof(TCelula));
  if(pNovo == NULL){return 0;}
  pNovo->Item = *pVoo;
  pAux_Atual=pLista->pPrimeiro;
  pAux_Prox=pLista->pPrimeiro->pProx;
  while(pAux_Prox != NULL){
    if(strcmp((pAux_Prox->Item.Hora_Decola),(pVoo->Hora_Decola))>=0){break;}    //Função compara horarios com a função STRCPY() ate encontrar local devido para fazer inserçao.//
    pAux_Atual = pAux_Prox;
    pAux_Prox = pAux_Prox->pProx;}
  pNovo->pProx = pAux_Prox;
  pAux_Atual->pProx = pNovo;
  if(pLista->pUltimo->pProx != NULL){
    pLista->pUltimo = pLista->pUltimo->pProx;
    pLista->pUltimo->pProx = NULL;}
  return 1;}



int Remove_Voo(TLista* pLista,TVoo* pVoo_Aux,int VID_R){    //Essa função retorna 1 se o voo foi removido com sucesso e 0 caso nao. Alem de passar por parametro o Tipo Voo (para fora da função) removido.//
  TCelula *pAux_Atual,*pAux_Prox;                           //ATENÇÃO! CRIE UM PONTEIRO DO TIPO TVoo E UMA VARIAVEL (FAÇA O PONTEIRO APONTAR PARA A VARIAVEL E ENT O PASSE POR PARAMETRO) PARA SALVAR O VOO FORA DA MEMORIA Q SERA DADO FREE().//
  if(pLista->pPrimeiro->pProx == NULL){return 0;}
  pAux_Atual = pLista->pPrimeiro;
  pAux_Prox = pLista->pPrimeiro->pProx;
  while(pAux_Prox != NULL && pAux_Prox->Item.VID != VID_R ){
            pAux_Atual = pAux_Prox;
            pAux_Prox = pAux_Prox->pProx;}
  if(pAux_Prox != NULL){
    *pVoo_Aux = pAux_Prox->Item;
    pAux_Atual->pProx = pAux_Prox->pProx;
    free(pAux_Prox);
    if(pLista->pUltimo->pProx != NULL){
      pLista->pUltimo = pLista->pUltimo->pProx;                                    
      pLista->pUltimo->pProx = NULL;}
      return 1;}
    return 0;}



int Procura_Voo(TLista* pLista,TVoo* pVoo_Aux,int VID_P){ // A função devolve o endereço do TipoVoo que contem o VID pelo ponteiro TVoo passado por parametro e retorna 1 se isso ocorre corretamente e 0 se nao é encontrado.//
  TCelula* Aux;                                          //ATENÇÃO! CRIE UM PONTEIRO DO TIPO TVoo E UMA VARIAVEL (FAÇA O PONTEIRO APONTAR PARA A VARIAVEL E ENT O PASSE POR PARAMETRO) PARA SALVAR O VOO FORA DA MEMORIA//
  Aux= pLista->pPrimeiro->pProx;
  while(Aux != NULL && Aux->Item.VID != VID_P){
    Aux=Aux->pProx;}
  if(Aux != NULL){
    *pVoo_Aux= Aux->Item;
    return 1;}
    else{return 0;}
  }



void Imprime_Lista(TLista* pLista){  //Função criada para facilitar as funcoes do TAD Matriz de Voos.//
    TCelula* pAux;
    pAux = pLista->pPrimeiro->pProx;
    while(pAux != NULL){
      printf("\n\t\t-------Inicio dos dados do Voo-------\n");
      printf("\t\t->VID: %d\n",pAux->Item.VID);
      printf("\t\t->Hora de Decolagem: %s\n",pAux->Item.Hora_Decola);
      printf("\t\t->Hora de Pouso Previsto: %s\n",pAux->Item.Hora_Previsto);
      printf("\t\t->Numero da Pista: %d\n",pAux->Item.Pista);
      printf("\t\t->Aeroporto de Chegada: %s\n",pAux->Item.Aeroporto_Chegada);
      printf("\t\t->Aeroporto de Partida: %s\n",pAux->Item.Aeroporto_Partida);
      printf("\t\t---------Fim dos dados do Voo--------\n\n");
      pAux=pAux->pProx;
    }
}
