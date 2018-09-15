typedef struct DadoVoo{
  int VID;
  char Hora_Decola[10];    //Variaveis para numero do Voo,Horario de decolagem,Horario de pouso,Horario previsto e numero da pista.
  char Hora_Previsto[10];
  int Pista;
  char Aeroporto_Partida[10];
  char Aeroporto_Chegada[10];
  //char CiaAerea[30];
  //char Status[30];
} TVoo;
//Inicializacao
void InicializaVoo(TVoo* pVoo);       //pVoo é um ponteiro para o tipo TVoo.
//------------------------------------------------------------------------------------------------------
//SETS
void SetVID(TVoo* pVoo);  //Variaveis declaradas para atribuições dentro da struct.
void SetHora_Decola(TVoo* pVoo,char hora[]);
void SetHora_Previsto(TVoo* pVoo,char hora[]);
void SetPista(TVoo* pVoo,int pista);
void SetAeroporto_Partida(TVoo* pVoo,char aeroporto[]);
void SetAeroporto_Chegada(TVoo* pVoo,char aeroporto[]);
//void SetCiaAerea(TVoo* pVoo,char ciaaerea[]);
//void SetStatus(TVoo* pVoo,char status[]);
//------------------------------------------------------------------------------------------------------
//GETS
int GetVID(TVoo* pVoo);
char* GetHora_Decola(TVoo* pVoo);
char* GetHora_Previsto(TVoo* pVoo);
int GetPista(TVoo* pVoo);
char* GetAeroporto_Partida(TVoo* pVoo);
char* GetAeroporto_Chegada(TVoo* pVoo);
//char* GetCiaAerea(TVoo pVoo);
//char* GetStatus(TVoo pVoo);

//------------------------------------------------------------------------------------------------------
