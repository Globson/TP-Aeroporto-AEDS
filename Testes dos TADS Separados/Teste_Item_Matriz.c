#include <stdio.h>
#include <stdlib.h>
#include "../Libs/Dados_Voo.h"
#include "../Libs/Lista_de_Voos.h"
#include "../Libs/Item_Matriz.h"
int main(int argc, char const *argv[]) {
  TLista Lista1,*pLista1,*pLista2=NULL;
  TItem_Matriz Item_M;
  TVoo Voo1,*pVoo1=NULL,Voo2,*pVoo2=NULL,Voo3,*pVoo3,pVoo_REMOVIDO,*pVooRemov,pVoo_PROCURADO,*pVooProc;
  char horad[10]="13:50",horap[10]="14:50",aeroc[10]="CPD",aerop[10]="ADC1";
  char horad2[10]="10:33",horap2[10]="16:55",aeroc2[10]="ASD",aerop2[10]="ASP2";
  char horad3[10]="09:20",horap3[10]="20:43",aeroc3[10]="ACE",aerop3[10]="AMG3";
  int pista1=2,pista2=3,pista3=1;
  pVoo1=&Voo1;
  pVoo2=&Voo2;
  pVoo3=&Voo3;
  pLista1=&Lista1;
  pVooRemov=&pVoo_REMOVIDO;
  pVooProc=&pVoo_PROCURADO;
  int retorno_ListaVazia,Removido,Procurado;
  int numero_voos=1,N_Voos;
  int U_ATT;
//Parte dos itens Voo


//Voo1
  InicializaVoo(pVoo1);
  SetVID(pVoo1);
  SetPista(pVoo1,pista1);
  SetHora_Decola(pVoo1,horad);
  SetHora_Previsto(pVoo1,horap);
  SetAeroporto_Partida(pVoo1,aerop);
  SetAeroporto_Chegada(pVoo1,aeroc);

  //Voo2
  InicializaVoo(pVoo2);
  SetVID(pVoo2);
  SetPista(pVoo2,pista2);
  SetHora_Decola(pVoo2,horad2);
  SetHora_Previsto(pVoo2,horap2);
  SetAeroporto_Partida(pVoo2,aerop2);
  SetAeroporto_Chegada(pVoo2,aeroc2);

  //Voo3
  InicializaVoo(pVoo3);
  SetVID(pVoo3);
  SetPista(pVoo3,pista3);
  SetHora_Decola(pVoo3,horad3);
  SetHora_Previsto(pVoo3,horap3);
  SetAeroporto_Partida(pVoo3,aerop3);
  SetAeroporto_Chegada(pVoo3,aeroc3);

//Lista


  Inicia_Lista(pLista1);
  retorno_ListaVazia = Lista_Vazia(pLista1);
  printf("Lista_Vazia: %d\n",retorno_ListaVazia);
  Insere_Voo(pLista1,pVoo1);
  Insere_Voo(pLista1,pVoo2);
  Insere_Voo(pLista1,pVoo3);
  retorno_ListaVazia= Lista_Vazia(pLista1);
  printf("Lista_Vazia: %d\n",retorno_ListaVazia);
  Imprime_Lista(pLista1);
  Procurado= Procura_Voo(pLista1,pVooProc,GetVID(pVoo3));
  if(Procurado != 0){
    printf("-----------Horario do voo procurado: %s----------------\n\n",pVoo_PROCURADO.Hora_Decola );}
  else{
  printf("-----------Voo procurado nao encontrado!: ----------------\n\n");}
  Removido = Remove_Voo(pLista1,pVooRemov,GetVID(pVoo3));
  if(Removido != 0){
  printf("-----------Hora do Voo removido: %s---------------------\n\n",pVoo_REMOVIDO.Hora_Decola );}
  else{printf("--------------------Voo a ser removido não encontrado!-----------------\n\n" );}
  Imprime_Lista(pLista1);


//Teste do Item_Matriz
Inicializa_Item_Matriz(&Item_M);
SetLista_de_Voos(&Item_M,pLista1);
SetNumero_de_Voos(&Item_M, numero_voos);
SetNumero_de_Voos(&Item_M, numero_voos);
SetNumero_de_Voos(&Item_M, numero_voos);
SetUltima_Atualizacao(&Item_M);
pLista2=GetLista_de_Voos(&Item_M);
if(pLista2 != NULL){
  printf("A lista dentro do item matriz existe!\n\n");
  Imprime_Lista(pLista2);}
else{printf("A lista dentro do item matriz não existe!\n\n");}
U_ATT = GetUltima_Atualizacao(&Item_M);
N_Voos = GetNumero_de_Voos(&Item_M);
printf("Numero de Voos:%d\n\n",N_Voos);
printf("Ultima Atualização: %d\n\n",U_ATT);

  return 0;
}
