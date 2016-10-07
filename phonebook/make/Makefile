CC := gcc
FLAGS := -c -g -Wall -I../include/ 
OBJ := ../obj
BIN := ../bin
SRC := ../src
INC := ../include

EXE=$(shell ls ../bin/*)
SRCS=$(shell ls ../src/*.c)
DEFS=$(shell ls ../include/*.h)

DEF := $(DEFS:../include/%.h=%.h)
OBJECTS := $(SRCS:../src/%.c=../obj/%.o)

# Executable name should be passed as command line argument
#	make O=<executable name> [OPTIONS]

O := run

ifndef O
all: usage
else
all: $O
endif

$O: $(BIN) $(OBJ)  $(BIN)/$O


$(BIN) :
	if [ ! -d "./$(BIN)" ];then \
                             mkdir $(BIN); \
                            fi

$(OBJ) :
	if [ ! -d "./$(OBJ)" ];then \
                             mkdir $(OBJ); \
                             fi

$(BIN)/$O: $(OBJECTS) 
	$(CC) -o $@ $^

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(FLAGS) $< -o $@ 

clean:
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/*
usage:
	@echo "Executable name should be passed as command line argument"
	@echo "	make O=<executable name> [OPTIONS]"


valgrind:
	valgrind --tool=memcheck --leak-check=yes $(BIN)/$O 
