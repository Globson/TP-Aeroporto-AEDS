#include <stdio.h>
#include <stdlib.h>
#include "../Libs/Lista_de_Voos.h"
#include "../Libs/Dados_Voo.h"

//Inicalizacao//
void Inicia_Lista(TLista* pLista){
  pLista->pPrimeiro = (struct Celula*) malloc(sizeof(TCelula));
  pLista->pUltimo = pLista->pPrimeiro;
  pLista->pPrimeiro->pProx= NULL;}
int Lista_Vazia(TLista* pLista){
  return(pLista->pPrimeiro == pLista->pUltimo);} //Retorna 1 para caso a afirmação seja verdade e 0 caso não.//
int Insere_Voo(TLista* pLista){} //Ainda pensando em como efetuar a entrada baseada na comparação entre horas de voos,Att Grobs//
int Remove_Voo(TLista* pLista,Voo* pVoo){
  TCelula* pAux;
  if(Lista_Vazia(pLista))
    return 0;
  *pVoo = pLista->pPrimeiro->pProx->Item;   //ATENÇÃO! ACREDITO QUE A FUNÇÃO NAO ESTEJA DE ACORDO COM O PEDIDO.CASO ENCONTRE ERRO,SINTA A VONTADE A REPARAR,PRETENDO REPARAR POSTERIORMENTE.//
  pAux = pLista->pPrimeiro;
  pLista->pPrimeiro = pLista->pPrimeiro->pProx;
  free(pAux);
  return 1;}
int Procura_Voo(TLista* pLista,Voo* pVoo){
  if(Lista_Vazia(pLista))
    return 0; //Falso caso lista esteja vazia.//
}
