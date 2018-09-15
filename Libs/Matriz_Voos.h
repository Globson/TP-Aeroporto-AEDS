#include "Item_Matriz.h"
#include "Lista_de_Voos.h"
#include "Dados_Voo.h"

typedef struct {
  TItem_Matriz* M[24][24];
  int Total_De_Voos;
  char Data[20];
  char Hora_Ultima_Atualizacao[20];
}TMatriz;



//------------------------------------------------------------------------------------------------------

// SETS
void SetData(TMatriz* pMatriz);
void SetTotal_De_Voos(TMatriz* pMatriz);
void SetHora_Ultima_Atualizacao(TMatriz* pMatriz);


// GETS

void Inicia_Matriz(TMatriz* pMatriz);
int Insere_Voo_Matriz(TMatriz* pMatriz,TVoo* Voo);
TVoo* Remove_Voo_Matriz(TMatriz* pMatriz,int VID);
TVoo* Procurar_Voo_Matriz(TMatriz* pMatriz,int VID);
void Imprimir_Voos_Decolagem_Pouso(TMatriz* pMatriz,char Hora_Decola,char Hora_Pouso);
void Imprimir_Voos_Decolagem(TMatriz* pMatriz);
void Imprimir_Voos_Pouso(TMatriz* pMatriz);
void Imprimir_Matriz(TMatriz* pMatriz);
void Encontrar_Faixa_Voos_Maior(TMatriz* pMatriz);//Faixa que tem a maior quantidade de voos
void Encontrar_Faixa_Voos_Menor(TMatriz* pMatriz);//Faixa que tem a menor quantidade de voos
void Encontrar_Lista_Voos_Mais_Recente(TMatriz* pMatriz);
void Encontrar_Lista_Voos_Menos_Recente(TMatriz* pMatriz);
int Matriz_Esparca(TMatriz* pMatriz);
/*Verificar se o numero de posicoes da matriz sem voos
cadastrados e,no minimo,o dobro daquelas com 1 voo
cadastrado*/
