PROJECT = mainSemOpenGL

CC			=	gcc

LIBS		=	-lm
 
C_FLAGS =	-Wall	\
					-O0		\
					-Werror		\
					-std=c11	\
					-Wextra		\
					-Wno-sign-compare			\
					-Wno-unused-parameter	\
					-Wno-unused-variable	\
					-Wshadow							\
					-g 										\
					-fno-inline 					\
					-fno-omit-frame-pointer

$(PROJECT): mainSemOpenGL.o imagem.o  filtros.o
	@echo Criando arquivo executável: $@
	@$(CC) mainSemOpenGL.o imagem.o filtros.o $(LIBS) -o $(PROJECT) 

mainSemOpenGL.o: mainSemOpenGL.c
	@echo Compilando arquivo objeto: $@
	@$(CC) $(C_FLAGS) -c mainSemOpenGL.c

imagem.o: imagem.c
	@echo Compilando arquivo objeto: $@
	@$(CC) $(C_FLAGS) -c imagem.c 

filtros.o: filtros.c
	@echo Compilando arquivo objeto: $@
	@$(CC) $(C_FLAGS) -c filtros.c 

memcheck: $(PROJECT) 
	valgrind --tool=memcheck --leak-check=full ./$(PROJECT) img.ppm

.PHONY: clean
clean:
	rm -f $(PROJECT) *.o