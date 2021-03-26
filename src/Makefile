PROJECT = photux

SRC			=	$(wildcard *.c)

OBJS		=	$(patsubst %.c, %.o, $(SRC))

CC			=	gcc

LIBS		=	-lm -lGL -lGLU -lglut
 
C_FLAGS =	-Wall	\
					-O0		\
					-Werror		\
					-std=c11	\
					-Wextra		\
					-Wno-sign-compare			\
					-Wno-unused-parameter	\
					-Wno-unused-variable	\
					-Wshadow

.PHONY: all

all: $(OBJS)
	@echo Criando arquivo executável: $@
	$(CC) $(OBJS) $(LIBS) -o $(PROJECT)

%.o: %.c
	@echo Compilando arquivo objeto: $@
	$(CC) $(C_FLAGS) -c $(SRC)

clean:
	rm -rf $(OBJS) $(PROJECT)

run: $(PROJECT)
	./$(PROJECT)
