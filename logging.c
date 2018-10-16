#include "header.h"

void loggingU(char log[MAXBUFF]){

    FILE *fd=NULL;
    
    fd = fopen("logsU.txt","a+");
    fprintf(fd,"%s" ,log);
    fclose(fd);
}

void loggingS(char log[MAXBUFF]){

    FILE *fd=NULL;
    
    fd = fopen("logsS.txt","a+");
    fprintf(fd,"%s" ,log);
    fclose(fd);
}

void loggingE(char log[MAXBUFF]){

    FILE *fd=NULL;
    
    fd = fopen("logsE.txt","a+");
    fprintf(fd,"%s" ,log);
    fclose(fd);
}

void logreaderErro (int writefd){
    int fd;
     char logs[MAXBUFF]={0};
    logs[0]='\0';
    int n;
   
     printf("---- Error Logs Accessed ----\n");
    fd= open("logsE.txt", 0);
    while ((n = read(fd, logs, MAXBUFF)) > 0)
    {
        if (write(writefd, logs, n) != n)
        {

            err_sys("Server: data write error!");
            loggingE("Server: data write error!\n");
        }
    }
    
}

void logreaderServer(int writefd){
    int fd;
     char logs[MAXBUFF]={0};
    logs[0]='\0';
    int n;
   
     printf("---- Server Logs Accessed ----\n");
    fd= open("logsS.txt", 0);
    while ((n = read(fd, logs, MAXBUFF)) > 0)
    {
        if (write(writefd, logs, n) != n)
        {

            err_sys("Server: data write error!");
            loggingE("Server: data write error!\n");
        }
    }
    
}

void logreaderUser(int writefd){
 int fd;
     char logs[MAXBUFF];
    logs[0]='\0';
    int n;

    printf("---- User Logs Accessed ----\n");
    fd=open("logsU.txt", 0);
    while ((n = read(fd, logs, MAXBUFF)) > 0)
    {
        if (write(writefd, logs, n) != n)
        {

            err_sys("Server: data write error!");
            loggingE("Server: data write error!\n");
        }
    }
}

void logToServer(char log[MAXBUFF], int writefd){
    
    if ((write(writefd, log , MAXBUFF)) != MAXBUFF) {
        err_sys("Client: command write error!\n");
        loggingE("Server: data read error!\n");
    }
    
}
