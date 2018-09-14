#include <stdio.h>
#include <stdlib.h>
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
  if((Lista_Vazia(pLista)) == 1){
    pLista->pPrimeiro->pProx=(struct Celula*)malloc(sizeof(TCelula));
    if(pLista->pPrimeiro->pProx == NULL){return 0;}
    pLista->pPrimeiro->pProx->Item=pVoo;
    pLista->pUltimo=pLista->pPrimeiro->pProx;
    return 1;}
  else{
    TCelula **pAux,*nova;
    pAux=&pLista->pPrimeiro;
    while(pVoo->Hora_Decola >= *pAux->pProx->Item->Hora_Decola || *pAux->pProx != NULL){
                    *pAux=*pAux->pProx;}
    nova=(TCelula*)malloc(sizeof(TCelula));
    if(nova == NULL){return 0}
    nova->pProx=*pAux->pProx;
    *pAux=nova;
    if(nova->pProx == NULL){
          TLista->pUltimo = nova;}
    return 1;
    }
  }





TVoo* Remove_Voo(TLista* pLista,int VID_R){    //Essa função retorna o ponteiro do ItemVoo correspondente a celula eliminada da lista//
  TCelula **pAux,*lixo;
  TVoo* pVoo_Aux;
  pAux=&pLista->pPrimeiro;
  while(*pAux != NULL && *pAux->Item->VID != VID_R ){
       if(*pAux->pProx->Item->VID == VID_R){
            pVoo_Aux=*pAux->pProx->Item;
            lixo=*pAux->pProx;
            *pAux=lixo->pProx;
            if(pAux== NULL){TLista->pUltimo = *pAux}
            free(lixo);
            return pVoo_Aux;}
    *pAux= *pAux->pProx;}
    return NULL;}




TVoo* Procura_Voo(TLista* pLista,int VID_P){ // A função devolve o endereço do TipoVoo que contem o VID entrado e NULL caso n exista.//
  TCelula* Aux;
  Aux= pLista->pPrimeiro->pProx;
  while(Aux !=NULL && Aux->Item->VID != VID_P){
    Aux=Aux->pProx;}
    return Aux->Item;}
