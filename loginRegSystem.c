 #include "header.h"

int loggedUserId=0;

int loginRegSystem(int writefd){

    
    //LOGIN SYS
    int flagLog=1;
    char check[5];
    FILE *fd=NULL;
    char username[55];
    char password[55];
    check[0]='\0';
    username[0]='\0';
    password[0]='\0';    
    
    printf("Have u registered yet? (Yes/No)\n");
    scanf("%s", check);
    if(strcmp(check, "No")==0){
    
        printf("Username: ");
        scanf("%s", username);
        printf("Password: ");
        scanf("%s", password);
        loggedUserId++;
        
      if(createAcount(loggedUserId, username, password)==1){
            printf("Account Already Registered\n");
            loggedUserId--;
            loginRegSystem(writefd);
        }else{
            printf("Creating account...\n");
            sleep(2);            
            printf("Account Created.\n");
            logToServer( "AcountC", writefd);
            return 0;
        }
    }   
    if(strcmp(check, "Yes")==0) {
        char usr[55];
        char pwd[55];
        int uflag=0;
        int pflag=0;
        
        printf("Username: ");
        scanf("%s", username);
        printf("Password: ");
        scanf("%s", password);
        loggedUserId++;
        
        fd=fopen("users.txt", "r");
           
        while(!(feof(fd))){
            fscanf(fd, "%d %s %s", &loggedUserId, usr, pwd);
            if(  strncmp(username, usr, strlen(username))==0 
                && strncmp(username, usr, strlen(usr))==0  ){
            
                    uflag=1;
                }
            if( strncmp(password, pwd,strlen(password))==0 
                && strncmp(password, pwd,strlen(password))==0 ){
            
                    pflag=1;
                }  
            if(uflag==1&&pflag==1){
                fclose(fd);
                flagLog=0;
                break;
            }
            }
        
        if(flagLog ==0)
        {
            printf("Login Successful.\n");
            logToServer("LogS",writefd);
            flagLog=1;
            return 0;
        }else{
              fclose(fd);
                printf("Failed to Login.\n");
                logToServer( "LogF",writefd);
                loggedUserId--;
                loginRegSystem(writefd);
        }
    }
    return 0;
}
