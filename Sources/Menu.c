#include <stdio.h>
#include "../Libs/Menu.h"
//TAD CRIADO APENAS PARA ENCAPSULAR ESTILIZAÇÃO DO MENU INTERATIVO DO PROGRAMA//
void Cabecalho(){
  printf("\n\n###########################################################################\n ");
  printf("\t\t     Bem vindo ao TADS AEROPORTO\n");
  printf("###########################################################################\n\n ");
}
void Rodape() {
  printf("\n\n###########################################################################\n\n");
}
void MenuArquivoInteraivo() {
  Cabecalho();
  printf("\t1.Entrada interativa->\n");
  printf("\t2.Entrada por arquivo->\n");
  printf("\t9.Finalizar programa->\n\n");
}
void MenuInteraivo(){
  Rodape();
  printf("\t1.Inserir Voo\n");
  printf("\t2.Remover Voo\n");
  printf("\t3.Procurar Voo\n");
  printf("\t4.Imprimir Voos->\n");
  printf("\t5.Encontrar faixa de horario->\n");
  printf("\t6.Lista de Voos mais recentemente->\n");
  printf("\t7.Verificar matriz esparca\n\n");
}
void Menu_Voos(){
  printf("\n\n\t1.Imprimir todos os Voos da seguinte hora de decolagem e pouso:\n");
  printf("\t2.Imprimir todos os Voos da seguinte hora de decolagem:\n");
  printf("\t3.Imprimir todos os Voos da seguinte hora de pouso:\n");
  printf("\t4.Imprimir todos os Voos cadastrados\n\n");
}
void Menu_Faixa(){
  printf("\n\n\t1.Encontrar faixa de horario de decolagem \n\te pouso com maior numero de Voos cadastrados\n\n");
  printf("\t2.Encontrar faixa de horario de decolagem \n\te pouso com menor numero de Voos cadastrados\n\n");
}
void Menu_Lista_De_Voos(){
  printf("\n\n\t1.Encontrar lista de Voos mais recentemente alterada\n\n");
  printf("\t2.Encontrar lista de Voos menos recentemente alterada\n\n");
}
void Agradecimentos(){
  printf("\n\t\t  ---------TADS AEROPORTO---------\n\n\t\t   Desenvolvedores:\n\t\t    Yuri Dimitre - 3485\n\t\t    Samuel Sena - 3494\n\t\t    Aryel Penido - 3500\n\n\t\t  OBRIGADO POR UTILIZAR O PROGRAMA!");
  Rodape();
}
