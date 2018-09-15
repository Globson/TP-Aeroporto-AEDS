#ifndef LISTA_DE_VOOS_H
#define LISTA_DE_VOOS_H
#include "Dados_Voo.h"
typedef struct Celula{
  TVoo Item;
  struct Celula* pProx;
}TCelula;//Nome TipoCelula para substituir a struct//
typedef struct Lista{
  struct Celula* pPrimeiro;
  struct Celula* pUltimo;
}TLista; //Nome TipoLista para substituir a struct//
void Inicia_Lista(TLista* pLista); //Passando por parametro ponteiro do tipo da struct TipoLista para acessar structs//
int Lista_Vazia(TLista* pLista); //Função para verificar se lista encontra-se vazia.//
int Insere_Voo(TLista* pLista,TVoo* pVoo);
int Remove_Voo(TLista* pLista,TVoo* pVoo_Aux,int VID_R);
int Procura_Voo(TLista* pLista,TVoo* pVoo_Aux,int VID_P);
void Imprime_Lista(TLista* pLista);
#endif
