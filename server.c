#include "header.h"

int server(int readfd, int writefd){

            
    
    int n;
    extern int errno;
    char buf[MAXBUFF]={0};

    printf("----Welcome to Our Humble App----\n");
    
    sleep(1);  
    
    loggingS("Server Connected!\n");
    
    printf("Ready for Client Connection... Please Execute Client Console.\n");
     printf("Adding Server Logs...\n");
     
     //------------------------------------

     
     //_----------------------------------------------------------       
     
    int status = fork();
    if(status==0){
        
        while(1){
           
            if ((n = read(readfd, buf, MAXBUFF)) != MAXBUFF)
            {
                printf("Server: read error!");
            }
            
            if((strncmp(strtok(buf, " "), "logsServer", 10 ) == 0)){
                printf("Accessing Server Logs...\n");
                logreaderServer(writefd);
            }
    
            if((strncmp(strtok(buf, " "), "logsUser", 8 ) == 0)){
                printf("Accessing User Logs...\n");
                logreaderUser(writefd);
            }
            
            if((strncmp(strtok(buf, " "), "logsErro", 8 ) == 0)){
                printf("Accessing Error Logs...\n");
                logreaderErro(writefd);
            }
            
            if(strncmp(buf, "ClientS", 7)==0){
                printf("Adding User Logs...\n");
                loggingU("Client Started!\n");
            }
            if(strncmp(buf, "AcountC", 7)==0){
                printf("Adding User Logs...\n");
                loggingU("Account Created.\n");
            }
            if(strncmp(buf, "LogS", 4)==0){
                printf("Adding User Logs...\n");
                loggingU("Login Successful.\n");
            }
            
            if(strncmp(buf, "LogF", 4)==0){
                printf("Adding User Logs...\n");
                loggingU("Login Failed.\n");
            }
            
            if(strncmp(buf, "CcmdE", 5)==0){
                printf("Adding User Logs...\n");
                loggingE("Client: command write error!\n");
            }
            
            if(strncmp(buf, "CdataE", 6)==0){
                printf("Adding User Logs...\n");
                loggingE("Client: data write error!\n");
            }

            if(strncmp(buf, "AppStart", 8)==0){
            
                connection_handler();
                    
            }
            
        }
    }
    
    wait(&status);
   
    return 0;
}


