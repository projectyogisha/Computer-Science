CC := gcc
FLAGS := -c -g -Wall -I../include/ 
OBJ := ../obj
BIN := ../bin
SRC := ../src
INC := ../include
SERVER :=server
CLIENT :=client

EXE=$(shell ls ../bin/*)

all: server client

server: $(BIN) $(OBJ)/server  $(BIN)/server


client: $(BIN) $(OBJ)/client  $(BIN)/client


$(BIN) :
	if [ ! -d "./$(BIN)" ];then \
                             mkdir $(BIN); \
                            fi

$(OBJ)/server :
	if [ ! -d "./$(OBJ)/server" ];then \
                             mkdir -p $(OBJ)/server; \
                             fi


$(OBJ)/client :
	if [ ! -d "./$(OBJ)/client" ];then \
                             mkdir -p $(OBJ)/client; \
                             fi

SRCS=$(shell ls ../src/$(SERVER)/*.c)
DEFS=$(shell ls ../include/*.h)
DEF := $(DEFS:../include/%.h=%.h)
OBJECTS := $(SRCS:../src/$(SERVER)/%.c=../obj/server/%.o)

$(BIN)/server: $(OBJECTS) 
	$(CC) -o $@ $^

$(OBJ)/server/%.o: $(SRC)/$(SERVER)/%.c
	$(CC) $(FLAGS) $< -o $@ 


SRCS=$(shell ls ../src/$(CLIENT)/*.c)
DEFS=$(shell ls ../include/*.h)
DEF := $(DEFS:../include/%.h=%.h)
OBJECTS := $(SRCS:../src/$(CLIENT)/%.c=../obj/client/%.o)


$(BIN)/client: $(OBJECTS) 
	$(CC) -o $@ $^

$(OBJ)/client/%.o: $(SRC)/$(CLIENT)/%.c
	$(CC) $(FLAGS) $< -o $@ 





clean:
	rm -f $(OBJ)/server/*.o   $(OBJ)/client/*.o
	rm -f $(BIN)/*


valgrind:
	valgrind --tool=memcheck --leak-check=yes $(BIN)/$O 
