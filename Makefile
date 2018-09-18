all: Main.o Sources/Dados_Voo.c  Sources/Item_Matriz.c  Sources/Lista_de_Voos.c  Sources/Matriz_Voos.c
	clang Main.c Dados_Voo.c Item_Matriz.c Lista_de_Voos.c Matriz_Voos.c -o EXEC
clean:
	rm -rf *.o
