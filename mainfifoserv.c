#include "header.h"
#include "fifo.h"

void *socket_desc;
 
//the thread function
void *connection_handler();


int main()
{

	int             readfd, writefd;
    
	/*
	 * Create the FIFOs, then open them - one for reading and one * for
	 * writing.
	*/

	umask(0);
 

	if ((mknod(FIFO1, S_IFIFO | PERMS, 0) < 0) && (errno != EEXIST))
	{

		fprintf(stderr, "can't create fifo: %s", FIFO1);

		return (-1);

	}
	if ((mknod(FIFO2, S_IFIFO | PERMS, 0) < 0) && (errno != EEXIST))
	{

		unlink(FIFO1);

		fprintf(stderr, "can't create fifo: %s", FIFO2);

		return (-1);

	}
	if ((readfd = open(FIFO1, 0)) < 0)
	{

		fprintf(stderr, "server: can't open read fifo: %s", FIFO1);

		return (-1);

	}
	if ((writefd = open(FIFO2, 1)) < 0)
	{

		fprintf(stderr, "server: can't open write fifo: %s", FIFO2);

		return (-1);

	}
	
	
    printf("FIFO CREATED\n");
	server(readfd, writefd);
    
	close(readfd);

	close(writefd);
    
	return (0);

}

void *connection_handler()
{
    //Get the socket descriptor
    int sock = *(int*)socket_desc;
    int read_size;
    char *message , client_message[2000];
     
    //Send some messages to the client
    message = "Greetings! I am your connection handler\nWrite smth:\n";
    write(sock , message , strlen(message));
     
    //Receive a message from client
    while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 )
    {
        //Send the message back to client
        write(sock , client_message , strlen(client_message));
    }
     
    if(read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }
         
    //Free the socket pointer
    free(socket_desc);
     
    return 0;
} 

