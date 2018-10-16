CC = cc -Wall 


OBS = mainfifocli.o createAcount.o client.o loginRegSystem.o server.o logging.o error.o mainfifoserv.o serverS.o

all :serverS server client 

serverS: createAcount.o client.o loginRegSystem.o server.o logging.o error.o serverS.o
	cc -Wall -pthread serverS createAcount.o client.o loginRegSystem.o server.o logging.o error.o serverS.o
	

server: $(OBS)
	cc -Wall -pthread -o server server.o logging.o error.o mainfifoserv.o 
	
client: $(OBS)
	cc -Wall -o client mainfifocli.o createAcount.o client.o  loginRegSystem.o logging.o error.o 
	rm -f *.o

SS: serverS 
	./serverS
	
S: server
	./server

C: client
	./client
	
clean:
	rm -f client server serverS *.o
