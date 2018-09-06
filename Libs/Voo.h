typedef struct DadoVoo{
  int VID;
  int Hora_Decola;
  int Minuto_Decola;     //Variaveis para numero do Voo,Horario de decolagem,Horario de pouso,Horario previsto e numero da pista.
  int Hora_Previsto;
  int Minuto_Previsto;
  int Pista;
  char Aeroporto_Partida[30];
  char Aeroporto_Chegada[30];
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
//------------------------------------------------------------------------------------------------------
//GETS
int GetVID(Voo Modelo);
void GetHora_Minuto_Decola(Voo Modelo,int hora,int minuto);
void GetHora_Minuto_Previsto(Voo Modelo,int hora,int minuto);
int GetPista(Voo Modelo);
char* GetAeroporto_Partida(Voo Modelo);
char* GetAeroporto_Chegada(Voo Modelo);
//------------------------------------------------------------------------------------------------------
