#ifndef VOO_H
#define VOO_H
typedef struct DadoVoo{
  int VID;
  char Hora_Decola[10];    //Variaveis para numero do Voo,Horario de decolagem,Horario de pouso,Horario previsto e numero da pista.
  char Hora_Previsto[10];
  int Pista;
  char Aeroporto_Partida[10];
  char Aeroporto_Chegada[10];

} TVoo;
//Inicializacao
void InicializaVoo(TVoo* pVoo);       //pVoo é um ponteiro para o tipo TVoo.
//------------------------------------------------------------------------------------------------------
//SETS
void SetVID(TVoo* pVoo);
void SetHora_Decola(TVoo* pVoo,char hora[]);
void SetHora_Previsto(TVoo* pVoo,char hora[]);
void SetPista(TVoo* pVoo,int pista);
void SetAeroporto_Partida(TVoo* pVoo,char aeroporto[]);
void SetAeroporto_Chegada(TVoo* pVoo,char aeroporto[]);
//------------------------------------------------------------------------------------------------------
//GETS
int GetVID(TVoo* pVoo);
char* GetHora_Decola(TVoo* pVoo);
char* GetHora_Previsto(TVoo* pVoo);
int GetPista(TVoo* pVoo);
char* GetAeroporto_Partida(TVoo* pVoo);
char* GetAeroporto_Chegada(TVoo* pVoo);


//------------------------------------------------------------------------------------------------------
#endif
