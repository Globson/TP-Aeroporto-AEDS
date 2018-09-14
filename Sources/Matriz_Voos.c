#include "../Libs/Item_Matriz.h"
#include "../Libs/Lista_de_Voos.h"
#include "../Libs/Dados_Voo.h"
#include "../Libs/Matriz_Voos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define count  24



//------------------------------------------------------------------------------------------------------

// SETS
void SetData(tMatriz* pMatriz){
    strcpy(pMatriz->Data,__DATE__);
}
void SetHora_Ultima_Atualizacao(tMatriz* pMatriz){
    strcpy(pMatriz->Hora_Ultima_Atualizacao,__TIME__);
}
//------------------------------------------------------------------------------------------------------

// GETS
char* GetData(tMatriz pMatriz){
    return pMatriz.Data;
}
char* GetHora_Ultima_Atualizacao(tMatriz pMatriz){
    return pMatriz.Hora_Ultima_Atualizacao;
}
//------------------------------------------------------------------------------------------------------

void Inicia_Matriz(tMatriz* pMatriz){
    strcpy(pMatriz->Data,"");
    pMatriz->Total_De_Voos = 0;
    strcpy(pMatriz->Hora_Ultima_Atualizacao,"");
    int i = 0,j = 0;

    for ( i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            Inicializa_Matriz(&pMatriz->M[i][j]);
        }
    }
}
int Insere_Voo_Matriz(tMatriz* pMatriz,TVoo* Voo){
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
