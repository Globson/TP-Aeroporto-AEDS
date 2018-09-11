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
} Voo;
//Inicializacao
void InicializaVoo(Voo* Modelo);
//------------------------------------------------------------------------------------------------------
//SETS
void SetVID(Voo* Modelo);  //Variaveis declaradas para atribuições dentro da struct.
void SetHora_Minuto_Decola(Voo* Modelo,int hora,int minuto);
void SetHora_Minuto_Previsto(Voo* Modelo,int hora,int minuto);
void SetPista(Voo* Modelo,int pista);
void SetAeroporto_Partida(Voo* Modelo,char aeroporto[]);
void SetAeroporto_Chegada(Voo* Modelo,char aeroporto[]);
//void SetCiaAerea(Voo* Modelo,char ciaaerea[]);
//void SetStatus(Voo* Modelo,char status[]);
//------------------------------------------------------------------------------------------------------
//GETS
int GetVID(Voo Modelo);
void GetHora_Minuto_Decola(Voo Modelo);
void GetHora_Minuto_Previsto(Voo Modelo);
int GetPista(Voo Modelo);
char* GetAeroporto_Partida(Voo Modelo);
char* GetAeroporto_Chegada(Voo Modelo);
//char* GetCiaAerea(Voo Modelo);
//char* GetStatus(Voo Modelo);

//------------------------------------------------------------------------------------------------------