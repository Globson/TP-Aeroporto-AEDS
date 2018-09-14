all: Main.o Sources/Dados_Voo.o Sources/Item_Matriz.o Sources/Lista_de_Voos.o Sources/Matriz_Voos.o
	clang -o Main Sources/Dados_Voo.o Sources/Item_Matriz.o Sources/Lista_de_Voos.o Sources/Matriz_Voos.o

Sources/Dados_Voo.o: Libs/Dados_Voo.h Sources/Dados_Voo.c
	clang -c Sources/Dados_voo.c

Sources/Item_Matriz.o: Libs/Item_Matriz.h Sources/Item_Matriz.c
	clang -c Sources/Item_Matriz.c

Sources/Lista_de_Voos.o: Libs/Lista_de_Voos.h Sources/Lista_de_Voos.c
	clang -c Sources/Lista_de_Voos.c

Sources/Matriz_Voos.o: Libs/Matriz_Voos.h Sources/Matriz_Voos.c
	clang -c Sources/Matriz_Voos.c

Main.o: Libs/Dados_Voo.h Libs/Item_Matriz.h Libs/Lista_de_Voos.h Libs/Matriz_Voos.h
	clang -c Main.c

clean:
	rm -rf *.o
