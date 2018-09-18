all:	Main.c Sources/Dados_Voo.c Sources/Item_Matriz.c Sources/Lista_de_Voos.c Sources/Matriz_Voos.c
	clang Main.c -o EXEC Sources/Dados_Voo.c Sources/Item_Matriz.c Sources/Lista_de_Voos.c Sources/Matriz_Voos.c
