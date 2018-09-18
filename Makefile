all:	Main.c Sources/Dados_Voo.c Sources/Item_Matriz.c Sources/Lista_de_Voos.c Sources/Matriz_Voos.c Sources/Menu.c
	gcc Main.c -o EXEC_GCC Sources/Dados_Voo.c Sources/Item_Matriz.c Sources/Lista_de_Voos.c Sources/Matriz_Voos.c Sources/Menu.c

clang: Main.c Sources/Dados_Voo.c Sources/Item_Matriz.c Sources/Lista_de_Voos.c Sources/Matriz_Voos.c Sources/Menu.c
	clang Main.c -o EXEC_CLANG Sources/Dados_Voo.c Sources/Item_Matriz.c Sources/Lista_de_Voos.c Sources/Matriz_Voos.c Sources/Menu.c
