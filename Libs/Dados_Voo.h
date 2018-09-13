typedef struct DadoVoo{
  int VID;
  int Hora_Decola;
  int Minuto_Decola;     //Variaveis para numero do Voo,Horario de decolagem,Horario de pouso,Horario previsto e numero da pista.
  int Hora_Previsto;
  int Minuto_Previsto;
  int Pista;
  char Aeroporto_Partida[30];
  char Aeroporto_Chegada[30];
  //char CiaAerea[30];
  //char Status[30];
} TVoo;
//Inicializacao
void InicializaVoo(TVoo* Modelo);
//------------------------------------------------------------------------------------------------------
//SETS
void SetVID(TVoo* Modelo);  //Variaveis declaradas para atribuições dentro da struct.
void SetHora_Minuto_Decola(TVoo* Modelo,int hora,int minuto);
void SetHora_Minuto_Previsto(TVoo* Modelo,int hora,int minuto);
void SetPista(TVoo* Modelo,int pista);
void SetAeroporto_Partida(TVoo* Modelo,char aeroporto[]);
void SetAeroporto_Chegada(TVoo* Modelo,char aeroporto[]);
//void SetCiaAerea(TVoo* Modelo,char ciaaerea[]);
//void SetStatus(TVoo* Modelo,char status[]);
//------------------------------------------------------------------------------------------------------
//GETS
int GetVID(TVoo Modelo);
void GetHora_Minuto_Decola(TVoo Modelo);
void GetHora_Minuto_Previsto(TVoo Modelo);
int GetPista(TVoo Modelo);
char* GetAeroporto_Partida(TVoo Modelo);
char* GetAeroporto_Chegada(TVoo Modelo);
//char* GetCiaAerea(TVoo Modelo);
//char* GetStatus(TVoo Modelo);

//------------------------------------------------------------------------------------------------------
