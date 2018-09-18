#include <stdio.h>
#include <stdlib.h>
#include "Libs/Dados_Voo.h"
#include "Libs/Lista_de_Voos.h"
#include "Libs/Item_Matriz.h"
#include "Libs/Matriz_Voos.h"
#include "Libs/Menu.h"
int main(int argc, char const *argv[]) {
  TVoo Voo;
  InicializaVoo(&Voo);
  SetVID(&Voo);
  printf("--------->VID:%d\n",GetVID(&Voo));
  MenuInteraivo();
  return 0;
}
