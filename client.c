#include "header.h"

int client(int readfd, int writefd){
    
                

	char buf[MAXBUFF]={0};
    printf("Client Started!\n");
    
    logToServer("ClientS",writefd);
    //LOGIN SYS
    
                //socketclient---------------------------------

    
            //socket------------------------------------
    
    
    if(loginRegSystem(writefd)==0){
        
        printf( "-- Welcome to the Client --\n");
        
        int status = fork();
        if(status==0){
        while(1){
            printf( "\nInsert command: \n");
            scanf("%s", buf);
            if(strcmp(buf, "AppStart")==0){
                if ((write(writefd, buf, MAXBUFF)) != MAXBUFF) {
                    err_sys("Client: command write error!\n");
                    logToServer("CcmdE", writefd);
                }
                
                  int sock;
                    struct sockaddr_in server;
                    char message[1000] , server_reply[2000];
                    
                    //Create socket
                    sock = socket(AF_INET , SOCK_STREAM , 0);
                    if (sock == -1)
                    {
                        printf("Could not create socket");
                    }
                    puts("Socket created");
                    
                    server.sin_addr.s_addr = inet_addr("127.0.0.1");
                    server.sin_family = AF_INET;
                    server.sin_port = htons( 8888 );
                
                    //Connect to remote server
                    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
                    {
                        perror("connect failed. Error");
                        return 1;
                    }
                    
                    puts("Connected\n");
                    
                    //keep communicating with server
                    while(1)
                    {
                        printf("Enter message : ");
                        scanf("%s" , message);
                        
                        //Send some data
                        if( send(sock , message , strlen(message) , 0) < 0)
                        {
                            puts("Send failed");
                            return 1;
                        }
                        
                        //Receive a reply from the server
                        if( recv(sock , server_reply , 2000 , 0) < 0)
                        {
                            puts("recv failed");
                            break;
                        }
                        
                        puts("Server reply :");
                        puts(server_reply);
                    }
                    
                    close(sock);
                
            }
            if ((write(writefd, buf, MAXBUFF)) != MAXBUFF) {
                err_sys("Client: command write error!\n");
                logToServer("CcmdE", writefd);
            }
        
            int n = strlen(buf);
            
            if (buf[n - 1] == '\n') {
                buf[n - 1] = '\0'; /* ignore newline from fgets() */
            }

            n = read(readfd, buf, MAXBUFF);
           
            if (write(1, buf, n) != n)	/* fd 1 = stdout */
                err_sys("Client: data write error!");
                  logToServer("CdataE", writefd);
            }

        }
        wait(&status);
        }else {
           client( readfd,   writefd); 
        }
    return 0;
}
