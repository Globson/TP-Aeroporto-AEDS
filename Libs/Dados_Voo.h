typedef struct DadoVoo{
  int VID;
  int Hora_Decola;
  int Minuto_Decola;     //Variaveis para numero do Voo,Horario de decolagem,Horario de pouso,Horario previsto e numero da pista.
  int Hora_Previsto;
  int Minuto_Previsto;
  int Pista;
  char Aeroporto_Partida[5];
  char Aeroporto_Chegada[5];
  //char CiaAerea[30];
  //char Status[30];
} TVoo;
//Inicializacao
void InicializaVoo(TVoo* pVoo);       //pVoo é um ponteiro para o tipo TVoo.
//------------------------------------------------------------------------------------------------------
//SETS
void SetVID(TVoo* pVoo);  //Variaveis declaradas para atribuições dentro da struct.
void SetHora_Minuto_Decola(TVoo* pVoo,int hora,int minuto);
void SetHora_Minuto_Previsto(TVoo* pVoo,int hora,int minuto);
void SetPista(TVoo* pVoo,int pista);
void SetAeroporto_Partida(TVoo* pVoo,char aeroporto[]);
void SetAeroporto_Chegada(TVoo* pVoo,char aeroporto[]);
//void SetCiaAerea(TVoo* pVoo,char ciaaerea[]);
//void SetStatus(TVoo* pVoo,char status[]);
//------------------------------------------------------------------------------------------------------
//GETS
int GetVID(TVoo pVoo);
void GetHora_Minuto_Decola(TVoo pVoo);
void GetHora_Minuto_Previsto(TVoo pVoo);
int GetPista(TVoo pVoo);
char* GetAeroporto_Partida(TVoo pVoo);
char* GetAeroporto_Chegada(TVoo pVoo);
//char* GetCiaAerea(TVoo pVoo);
//char* GetStatus(TVoo pVoo);

//------------------------------------------------------------------------------------------------------
