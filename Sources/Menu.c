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
  printf("\t1.Entrada interativa\n");
  printf("\t2.Entrada por arquivo\n");
  Rodape();
}
void MenInteraivo(/* arguments */) {
  Cabecalho();
  printf("\t1.Inserir Voo\n");
  printf("\t2.Remove Voo\n");
  printf("\t3.Procura Voo\n");
  printf("\t4.Imprimir Voo\n");
  printf("\t5.Encontrar faixa\n" );
  printf("\t6.Verificar matriz esparca\n" );
  printf("\t7.Entrada por arquivo\n");
  Rodape();
}
