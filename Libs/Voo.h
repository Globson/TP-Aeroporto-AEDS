typedef struct DadoVoo{
  int VID;
  int HDecola;
  int HPouso;      //Variaveis para numero do Voo,Horario de decolagem,Horario de pouso,Horario previsto e numero da pista.
  int HPrevisto;
  int Pista;
} Voo;
void InicializaVoo(Voo* Modelo);
void SetVoo(Voo* Modelo,int Hora_decolagem,int Hora_de_pouso,int Hora_previsto,int Numero_Pista);  //Variaveis declaradas para atribuições dentro da struct.
