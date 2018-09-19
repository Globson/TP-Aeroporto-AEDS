#include <stdio.h>
#include "../Libs/Menu.h"
void Cabecalho(){
  printf("\n\n###########################################################################\n ");
  printf("\t\t\tBem vindo ao TAD VOO\n");
  printf("###########################################################################\n\n ");

}
void Rodape(/* arguments */) {
  printf("\n\n###########################################################################\n\n");
}
void MenuArquivoInteraivo(/* arguments */) {
  Cabecalho();
  printf("\t1.Entrada interativa->\n");
  printf("\t2.Entrada por arquivo->\n\n");
}
void MenuInteraivo(/* arguments */) {
  Rodape();
  printf("\t1.Inserir Voo\n");
  printf("\t2.Remove Voo\n");
  printf("\t3.Procurar Voo\n");
  printf("\t4.Imprimir Voos->\n");
  printf("\t5.Encontrar faixa de horario->\n");
  printf("\t6.Lista de Voos mais recentemente->\n");
  printf("\t7.Verificar matriz esparca\n\n");

}
void Menu_Voos(){
  Rodape();
  printf("\t1.Imprimir todos os Voos da seguinte hora de decolagem e pouso:\n");
  printf("\t2.Imprimir todos os Voos da seguinte hora de decolagem:\n");
  printf("\t3.Imprimir todos os Voos da seguinte hora de pouso:\n");
  printf("\t4.Imprimir todos os Voos cadastrados\n\n");
}
void Menu_Faixa(){
  Rodape();
  printf("\t1.Encontrar faixa de horario de decolagem \n\te pouso com maior numero de Voos cadastrados\n\n");
  printf("\t2.Encontrar faixa de horario de decolagem \n\te pouso com menor numero de Voos cadastrados\n\n");
}
void Menu_Lista_De_Voos(){
  Rodape();
  printf("\t1.Encontrar lista de Voos mais recentemente alterada\n\n");
  printf("\t2.Encontrar lista de Voos menos recentemente alterada\n\n");
}
