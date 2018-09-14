#include "Item_Matriz.h"
#include "Lista_de_Voos.h"
#include "Dados_Voo.h"

typedef struct {
  Item_Matriz M[24][24];
  int Data;
  int Total_De_Voos;
  char Hora_Ultima_Atualizacao;
}Matriz;

void Inicia_Matriz(Matriz* pMatriz);
int Insere_Voo_Matriz(Matriz* pMatriz);
TVoo* Remove_Voo_Matriz(Matriz* pMatriz);
TVoo* Procurar_Voo_Matriz(Matriz* pMatriz);
void Imprimir_Voos_Decolagem_Pouso(Matriz* pMatriz);
void Imprimir_Voos_Decolagem(Matriz* pMatriz);
void Imprimir_Voos_Pouso(Matriz* pMatriz);
void Imprimir_Matriz(Matriz* pMatriz);
void Encontrar_Faixa_Voos_Maior(Matriz* pMatriz);//Faixa que tem a maior quantidade de voos
void Encontrar_Faixa_Voos_Menor(Matriz* pMatriz);//Faixa que tem a menor quantidade de voos
void Encontrar_Lista_Voos_Mais_Recente(Matriz* pMatriz);
void Encontrar_Lista_Voos_Menos_Recente(Matriz* pMatriz);
int Matriz_Esparca(Matriz* pMatriz);
/*Verificar se o numero de posicoes da matriz sem voos
cadastrados e,no minimo,o dobro daquelas com 1 voo
cadastrado*/
