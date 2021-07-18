PROJECT = photux
#H_SOURCE = $(wildcard ./src/*.h)

DIR_OUT = obj
DIR_SRC += .
DIR_SRC = ./src
DIR_INC += $(addprefix -I, $(DIR_SRC))

C_SOURCE += $(wildcard $(addsuffix /*.c, $(DIR_SRC)))

OBJ := $(patsubst %.c, %.o, $(C_SOURCE))
 
CC = gcc

EXE := obj/$(PROJECT)
 
LIBS =	-lm -lGL -lGLU -lglut

CC_FLAGS =		-c		\
		 					-Wall		\
							-O0		\
							-Werror		\
							-std=c11	\
							-Wextra	\
							-Wno-sign-compare		\
							-Wno-unused-parameter		\
							-Wno-unused-variable		\
							-Wshadow

RM = rm -rf
MD = $(shell mkdir -p $(DIR_OUT))

.PHONY:all

all:$(OBJ) $(EXE)
%.o: %.c
	$(MD)
	$(CC) $(DIR_INC) $(CC_FLAGS) $< -o $@

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o $@ $(DIR_INC)

	$(RM) $(DIR_SRC)/*.o

clean:
	cd obj && $(RM) *

run: $(EXE)
	cd obj && ./${PROJECT}