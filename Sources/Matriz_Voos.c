#include "../Libs/Item_Matriz.h"
#include "../Libs/Lista_de_Voos.h"
#include "../Libs/Dados_Voo.h"
#include "../Libs/Matriz_Voos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define count  24

void Inicia_Matriz(Matriz* pMatriz){
    pMatriz->Data = 0;
    pMatriz->Total_De_Voos = 0;
    strcpy(pMatriz->Hora_Ultima_Atualizacao,"");

    for (size_t i = 0; i < count; i++) {
        for (size_t j = 0; j < count; j++) {
            pMatriz->M[i][j] = NULL; // Q
        }
    }
}
int Insere_Voo_Matriz(Matriz* pMatriz TVoo* Voo){
    //Vai ser pego a hora para achar a posicao na matriz e
    // dps chamar a funcao da lista daquela posicao da matriz
    return 0;
}
/*TVoo* Remove_Voo_Matriz(Matriz* pMatriz);
TVoo* Procurar_Voo_Matriz(Matriz* pMatriz);
void Imprimir_Voos_Decolagem_Pouso(Matriz* pMatriz);
void Imprimir_Voos_Decolagem(Matriz* pMatriz);
void Imprimir_Voos_Pouso(Matriz* pMatriz);
void Imprimir_Matriz(Matriz* pMatriz);
void Encontrar_Faixa_Voos_Maior(Matriz* pMatriz);//Faixa que tem a maior quantidade de voos
void Encontrar_Faixa_Voos_Menor(Matriz* pMatriz);//Faixa que tem a menor quantidade de voos
void Encontrar_Lista_Voos_Mais_Recente(Matriz* pMatriz);
void Encontrar_Lista_Voos_Menos_Recente(Matriz* pMatriz);
int Matriz_Esparca(Matriz* pMatriz);*/
