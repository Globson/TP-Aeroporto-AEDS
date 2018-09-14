#include "Item_Matriz.h"
#include "Lista_de_Voos.h"
#include "Dados_Voo.h"

typedef struct {
  Item_Matriz M[24][24];
  int Total_De_Voos;
  char Data[20];
  char Hora_Ultima_Atualizacao[20];
}tMatriz;



//------------------------------------------------------------------------------------------------------

// SETS
void SetData(tMatriz* pMatriz);
void SetTotal_De_Voos(tMatriz* pMatriz);
void SetHora_Ultima_Atualizacao(tMatriz* pMatriz);


// GETS
int
void Inicia_Matriz(tMatriz* pMatriz);
int Insere_Voo_Matriz(tMatriz* pMatriz);
TVoo* Remove_Voo_Matriz(tMatriz* pMatriz);
TVoo* Procurar_Voo_Matriz(tMatriz* pMatriz);
void Imprimir_Voos_Decolagem_Pouso(tMatriz* pMatriz);
void Imprimir_Voos_Decolagem(tMatriz* pMatriz);
void Imprimir_Voos_Pouso(tMatriz* pMatriz);
void Imprimir_Matriz(tMatriz* pMatriz);
void Encontrar_Faixa_Voos_Maior(tMatriz* pMatriz);//Faixa que tem a maior quantidade de voos
void Encontrar_Faixa_Voos_Menor(tMatriz* pMatriz);//Faixa que tem a menor quantidade de voos
void Encontrar_Lista_Voos_Mais_Recente(tMatriz* pMatriz);
void Encontrar_Lista_Voos_Menos_Recente(tMatriz* pMatriz);
int Matriz_Esparca(tMatriz* pMatriz);
/*Verificar se o numero de posicoes da matriz sem voos
cadastrados e,no minimo,o dobro daquelas com 1 voo
cadastrado*/
