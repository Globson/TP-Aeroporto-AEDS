#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libs/Dados_Voo.h"
#include "Libs/Lista_de_Voos.h"
#include "Libs/Item_Matriz.h"
#include "Libs/Matriz_Voos.h"
#include "Libs/Menu.h"
int main(int argc, char const *argv[]) {
  tMatriz Matriz;
  Inicia_Matriz(&Matriz);
  while(1){  //While faz programa sempre retornar a tela inicial após uma operação de qualquer tipo ou especie.//
    int a1 = 0;
  MenuArquivoInteraivo();
  while(a1 != 1 && a1 != 2 && a1 != 9){
    printf("Digite a opção desejada:");
    scanf("%d",&a1);
    if(a1 != 1 && a1 != 2 && a1 != 9){
      printf("Opção invalida!\n");}}

  if(a1 == 1){ //Parte interativa
    int a2 = 0;
    MenuInteraivo();
    while(a2 != 1 && a2 != 2 && a2 != 3 && a2 != 4 && a2 != 5 && a2 != 6 && a2 != 7){   //Esse while faz o programa insistir em uma entrada de uma opção valida(ela aparece em outras funções).//
      printf("Digite a opção desejada:");
      scanf("%d",&a2);
      if(a2 != 1 && a2 != 2 && a2 != 3 && a2 != 4 && a2 != 5 && a2 != 6 && a2 != 7){
        printf("Opção invalida!\n");}}

    if(a2 == 1){ //Inserir Voo e entrar com valores para o Voo que deseja inserir.//
      TVoo Voo;
      char Hd[10],Hp[10],Ap[10],Ac[10];
      int Pista,aux=0;
      InicializaVoo(&Voo);
      SetVID(&Voo);
      Rodape();
      printf("\t->Formato da hora: HH:MM ->24Hrs\n\n");
      printf("Entre com o horario de decolagem do Voo:");
      scanf("%s",Hd);
      printf("\nEntre com o horario de pouso do Voo:");
      scanf("%s",Hp);
      printf("\nEntre com o numero da pista:");
      scanf("%d",&Pista);
      printf("\nEntre com o nome do aeroporto de partida do Voo:");
      scanf("%s",Ap);
      printf("\nEntre com o nome do aeroporto de chegada do Voo:");
      scanf("%s",Ac);
      SetHora_Decola(&Voo,Hd);
      SetHora_Previsto(&Voo,Hp);
      SetPista(&Voo,Pista);
      SetAeroporto_Chegada(&Voo,Ac);
      SetAeroporto_Partida(&Voo,Ap);
      aux = Insere_Voo_Matriz(&Matriz,&Voo);
      if(aux==1){
        printf("\n\tVoo inserido com sucesso!");
        Rodape();
      }else{
        printf("\n\tVoo nao inserido por falta de memoria!");
        Rodape();
      }}

    if(a2 == 2){ //Remover Voo e imprime na tela se usuario desejar.//
      TVoo Voo_R;
      int VID_R,aux=0,aux2=0;
      InicializaVoo(&Voo_R);
      Rodape();
      printf("\nEntre com o VID do Voo a ser removido:");
      scanf("%d",&VID_R);
      aux = Remove_Voo_Matriz(&Matriz,&Voo_R,VID_R);
      if(aux == 1){
        printf("\n\tVoo removido com sucesso!\n");
        printf("\nDeseja imprimir o Voo removido?\n\t1.Sim\n\t2.Nao\n");
        while(aux2 != 1 && aux2 != 2){
          printf("Entre com a opção desejada:");
          scanf("%d",&aux2);
          if(aux2 != 1 && aux2 != 2){
            printf("Opção invalida!\n");}}
         if(aux2 == 1){
           printf("\n-------Inicio dos dados do Voo-------\n");
           printf("VID: %d\n",Voo_R.VID);
           printf("Hora de Decolagem: %s\n",Voo_R.Hora_Decola);
           printf("Hora de Pouso Previsto: %s\n",Voo_R.Hora_Previsto);
           printf("Numero da Pista: %d\n",Voo_R.Pista);
           printf("Aeroporto de Chegada: %s\n",Voo_R.Aeroporto_Chegada);
           printf("Aeroporto de Partida: %s\n",Voo_R.Aeroporto_Partida);
           printf("---------Fim dos dados do Voo--------\n\n");
           Rodape();
         }else{Rodape();}
        }else{
          printf("\n\t->Falha ao remover Voo! Voo nao encontrado.");
          Rodape();}}

    if(a2 == 3){ //Procurar Voo e imprime na tela.//
      TVoo Voo_P;
      InicializaVoo(&Voo_P);
      int VID,aux=0;
      Rodape();
      printf("\nEntre com o VID do Voo a ser procurado:");
      scanf("%d",&VID);
      aux = Procurar_Voo_Matriz(&Matriz,&Voo_P,VID);
      if(aux == 1){
        printf("\n\t->Voo encontrado!");
        printf("\n-------Inicio dos dados do Voo-------\n");
        printf("VID: %d\n",Voo_P.VID);
        printf("Hora de Decolagem: %s\n",Voo_P.Hora_Decola);
        printf("Hora de Pouso Previsto: %s\n",Voo_P.Hora_Previsto);
        printf("Numero da Pista: %d\n",Voo_P.Pista);
        printf("Aeroporto de Chegada: %s\n",Voo_P.Aeroporto_Chegada);
        printf("Aeroporto de Partida: %s\n",Voo_P.Aeroporto_Partida);
        printf("---------Fim dos dados do Voo--------\n\n");
        Rodape();
      }else{
        printf("\n\t->Voo nao encontrado!");
        Rodape();}}

    if(a2 == 4){ //Imprime Voo...//
      int b=0;
      char horaDec[10],horaPou[10];
      Menu_Voos();
      while(b != 1 && b != 2 && b != 3 && b != 4){
        printf("Digite a opção desejada:");
        scanf("%d",&b);
        if(b != 1 && b != 2 && b != 3 && b != 4){
          printf("Opção invalida!\n");}}
      if(b == 1){ //Apenas nas hora de decolagem e pouso//
        Rodape();
        printf("\t->Formato da hora: HH:MM ->24Hrs\n\n");
        printf("Digite o horario de decolagem:");
        scanf("%s",horaDec);
        printf("Digite o horario de pouso:");
        scanf("%s",horaPou);
        Imprimir_Voos_Decolagem_Pouso(&Matriz,horaDec,horaPou);
        Rodape();}
      if(b == 2){ //Apenas na hora de decolagem//
        Rodape();
        printf("\t->Formato da hora: HH:MM ->24Hrs\n\n");
        printf("Digite o horario de decolagem:");
        scanf("%s",horaDec);
        Imprimir_Voos_Decolagem(&Matriz,horaDec);
        Rodape();}
      if(b == 3){ //Apenas na hora de pouso//
        Rodape();
        printf("\t->Formato da hora: HH:MM ->24Hrs\n\n");
        printf("Digite o horario de pouso:");
        scanf("%s",horaPou);
        Imprimir_Voos_Pouso(&Matriz,horaPou);
        Rodape();}
      if(b == 4){ //Todos os Voos//
        Rodape();
        Imprimir_Matriz(&Matriz);
        Rodape();}}

    if(a2 == 5){ //Encontrar faixa...//
      int c = 0;
      Menu_Faixa();
      while(c != 1 && c != 2){
        printf("Digite a opção desejada:");
        scanf("%d",&c);
        if(c != 1 && c != 2){
          printf("Opção invalida!\n");}}
      if(c == 1){ //Encontrar faixa de horario de decolagem e pouso com maior numero de Voos cadastrados.//
        Encontrar_Faixa_Voos_Maior(&Matriz);
        Rodape();}
      if(c == 2){ //Encontrar faixa de horario de decolagem e pouso com menor numero de Voos cadastrados.//
        Encontrar_Faixa_Voos_Menor(&Matriz);
        Rodape();}}

    if(a2 == 6){ //Encontrar lista de Voos...//
      int d = 0;
      Menu_Lista_De_Voos();
      while(d != 1 && d != 2){
        printf("Digite a opção desejada:");
        scanf("%d",&d);
        if(d != 1 && d != 2){
          printf("Opção invalida!\n");}}
      if(d == 1){ //Encontrar lista de Voos mais recente.//
        Encontrar_Lista_Voos_Mais_Recente(&Matriz);
        Rodape();}
      if(d == 2){ //Encontrar lista de Voos mais recente.//
        Encontrar_Lista_Voos_Menos_Recente(&Matriz);
        Rodape();}}

    if(a2 == 7){ //Teste da matriz esparca.//
      Rodape();
      Matriz_Esparca(&Matriz);
      Rodape();
    }
  }
  if(a1 == 2){ //Parte de arquivo.//
    FILE *f;
    char nome_arquivo[20],comparador[1];
    printf("\nDigite o nome do arquivo que deseja abrir:");
    scanf("%s",nome_arquivo);
    f = fopen(nome_arquivo,"r");
    if(f == NULL){
      printf("\n\tErro!Nao foi possivel abrir arquivo!\n");}
      else{
        printf("\n\tArquivo aberto com sucesso!\n");
        while(fscanf(f,"%s",comparador) != EOF){
            if(strcmp(comparador,"a") == 0){ //Inicia Matriz//
              printf("\n\tA operacao inicia ja foi realizada\n");}

            if(strcmp(comparador,"b") == 0){ //Insere Voo por arquivo//
              TVoo Voo;
              char Ap[10],Ac[10],Hd[10],Hp[10];
              int A_pista,aux=0;
              InicializaVoo(&Voo);
              SetVID(&Voo);
              fscanf(f,"%s",Hd);
              fscanf(f,"%s",Hp);
              fscanf(f,"%s",Ap);
              fscanf(f,"%s",Ac);
              fscanf(f,"%d",&A_pista);
              SetHora_Decola(&Voo,Hd);
              SetHora_Previsto(&Voo,Hp);
              SetPista(&Voo,A_pista);
              SetAeroporto_Chegada(&Voo,Ac);
              SetAeroporto_Partida(&Voo,Ap);
              aux = Insere_Voo_Matriz(&Matriz,&Voo);
              if(aux==1){
                printf("\n\tUm Voo inserido por arquivo com sucesso!");
                Rodape();
              }else{
                printf("\n\tVoo nao inserido por arquivo por falta de memoria!");
                Rodape();
              }
            }
            if(strcmp(comparador,"c") == 0){ //Remove Voo por arquivo//
              TVoo Voo_R;
              int VID_A,aux=0;
              InicializaVoo(&Voo_R);
              fscanf(f,"%d",&VID_A);
              aux = Remove_Voo_Matriz(&Matriz,&Voo_R,VID_A);
              if(aux == 1){
                printf("\n\tUm Voo removido com sucesso por arquivo!\n");
                Rodape();
                }else{
                  printf("\n\t->Falha ao remover Voo por arquivo! Voo nao encontrado.");
                  Rodape();}}

            if(strcmp(comparador,"d") == 0){ //Procura Voo por arquivo//
              TVoo Voo_P;
              int VID_A,aux=0;
              InicializaVoo(&Voo_P);
              fscanf(f,"%d",&VID_A);
              aux = Procurar_Voo_Matriz(&Matriz,&Voo_P,VID_A);
              if(aux == 1){
                printf("\n\t->Voo encontrado por arquivo!");
                printf("\n-------Inicio dos dados do Voo-------\n");
                printf("VID: %d\n",Voo_P.VID);
                printf("Hora de Decolagem: %s\n",Voo_P.Hora_Decola);
                printf("Hora de Pouso Previsto: %s\n",Voo_P.Hora_Previsto);
                printf("Numero da Pista: %d\n",Voo_P.Pista);
                printf("Aeroporto de Chegada: %s\n",Voo_P.Aeroporto_Chegada);
                printf("Aeroporto de Partida: %s\n",Voo_P.Aeroporto_Partida);
                printf("---------Fim dos dados do Voo--------\n\n");
                Rodape();
              }else{
                printf("\n\t->Voo nao encontrado por arquivo!");
                Rodape();}}

            if(strcmp(comparador,"e") == 0){ //Imprime Voos decolagem e pouso por arquivo//
              char Hd[10],Hp[10];
              fscanf(f,"%s",Hd);
              fscanf(f,"%s",Hp);
              Imprimir_Voos_Decolagem_Pouso(&Matriz,Hd,Hp);
              Rodape();}

            if(strcmp(comparador,"f") == 0){ //Imprime Voos decolagem//
              char Hd[10];
              fscanf(f,"%s",Hd);
              Imprimir_Voos_Decolagem(&Matriz,Hd);
              Rodape();}

            if(strcmp(comparador,"g") == 0){ //Imprime Voos de pouso//
              char Hp[10];
              fscanf(f,"%s",Hp);
              Imprimir_Voos_Pouso(&Matriz,Hp);
              Rodape();}

            if(strcmp(comparador,"h") == 0){ //Imprime todos voos cadastrados//
              Imprimir_Matriz(&Matriz);}

            if(strcmp(comparador,"i") == 0){ //Encontrar faixa de voos maior//
              Encontrar_Faixa_Voos_Maior(&Matriz);
              Rodape();}

            if(strcmp(comparador,"j") == 0){ //Encontrar faixa de Voos menos.//
              Encontrar_Faixa_Voos_Menor(&Matriz);
              Rodape();}

            if(strcmp(comparador,"k") == 0){ //Encontrar lista de Voos mais recente.//
              Encontrar_Lista_Voos_Mais_Recente(&Matriz);
              Rodape();}

            if(strcmp(comparador,"l") == 0){ //Encontrar faix de Voos menos recente.//
              Encontrar_Lista_Voos_Menos_Recente(&Matriz);
              Rodape();}

            if(strcmp(comparador,"m") == 0){ //Verificar se matriz é esparça.//
              Matriz_Esparca(&Matriz);
              Rodape();}}
        fclose(f);
      }}
  if(a1 == 9){ //Finalização do programa.//
    int f = 0;
    printf("\nDeseja realmente finalizar a execução do programa?\n\t1.Sim\n\t2.Nao\n");
    while(f != 1 && f != 2){
      printf("Digite a opção desejada:");
      scanf("%d",&f);
      if(f != 1 && f != 2){
        printf("Opção invalida!\n");}}
    if(f == 1){
      printf("\n\t\t  ------------TAD VOO------------\n\n\t\t   Desenvolvedores:\n\t\t    Yuri Dimitre - 3485\n\t\t    Samuel Sena - 3494\n\t\t    Aryel Penido - 3500\n\n\t\t  OBRIGADO POR UTILIZAR O PROGRAMA!");
      Rodape();
      break;}
    if(f == 2){
      printf("\n\tFinalizacao cancelada!");}}
    }
  return 0;
}
