#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <errno.h>
#include <dirent.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <netdb.h>

#define MAXROOM 20
#define PIPENAMELEN 50
#define USERNAMEMAXLEN 55
#define PASSWORDMAXLEN 55
#define LOGMAXLEN 200
#define TEMP "/tmp/"
#define err_sys(STR) fprintf(stderr,STR)
#define MAXBUFF 1024

char *sys_err_str(void);

void logreaderServer(int writefd);

void logreaderUser(int writefd);

void logreaderErro (int writefd);

void loggingE(char log[MAXBUFF]);

void loggingS(char log[LOGMAXLEN]);

void loggingU(char log[LOGMAXLEN]);

int server(int readfd , int writefd);

void logToServer(char log[MAXBUFF], int writefd);

void *connection_handler();

int createAcount(int userId, char username[USERNAMEMAXLEN], char password[PASSWORDMAXLEN]);

int client(int readfd , int writefd);

int loginRegSystem(int writefd);
