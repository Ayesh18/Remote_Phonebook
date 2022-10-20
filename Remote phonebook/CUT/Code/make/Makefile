#compiler
GCC = gcc
#compiler flags
CFLAG = -pg -Wall -fprofile-arcs -ftest-coverage
#output file
LFLAGS = -o
#binary file directory
BIN = ../bin
#source file directory
SRC = ../src
#include file directory
INC = ../header
#object file directory
OBJ = ../obj
#IFLAG
IFLAGS = -I $(INC)

#valgrind report
CVFLAGS = --tool=memcheck --leak-check=full 

#compile all source file
all: buildServer buildClient

buildServer: $(OBJ)/server.o $(OBJ)/user.o  
	$(GCC) $(IFLAGS) $(CFLAG) $(LFLAGS) $(BIN)/server $(OBJ)/server.o $(OBJ)/user.o  $(SRC)/servermain.c 

buildClient: $(OBJ)/client.o
	$(GCC) $(IFLAGS) $(CFLAG) $(LFLAGS) $(BIN)/client $(OBJ)/client.o $(SRC)/clientmain.c 

$(OBJ)/server.o: $(SRC)/server.c
	$(GCC) $(IFLAGS) $(CFLAG) -c  $(LFLAGS) $(OBJ)/server.o $(SRC)/server.c 
	
$(OBJ)/client.o: $(SRC)/client.c
	$(GCC) $(IFLAGS) $(CFLAG) -c $(LFLAGS) $(OBJ)/client.o $(SRC)/client.c 

$(OBJ)/user.o: $(SRC)/user.c
	$(GCC) $(IFLAGS)  $(CFLAG) -c $(LFLAGS) $(OBJ)/user.o $(SRC)/user.c 

#run server
server:
	 ./$(BIN)/server

#run client
client:
	 ./$(BIN)/client

clean:
        rm $(BIN)/server
        rm $(BIN)/client
        rm $(OBJ)/server.o
        rm $(OBJ)/client.o
        rm $(OBJ)/user.o
cleanall:
        rm $(OBJ)/*
        rm $(BIN)/*
        rm *.out *.gcov *.gcda *.gcno
	
gprofserver: 
	gprof -b $(BIN)/server gmon.out
		
gprofclient:
	gprof -b $(BIN)/client gmon.out
	
gcov:
	gcov clientmain
	gcov $(OBJ)/client

gcovshow:
	cat clientmain.c.gcov
	cat client.c.gcov

