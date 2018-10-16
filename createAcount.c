#include "header.h"
 

int createAcount(int loggedUserId, char username[55], char password[55]){
		
	FILE *fd=NULL;

	char usr[55];
	char pwd[55];
    
	printf("Starting Creation.\n");
    
	fd=fopen("users.txt", "r");
	
    while(!(feof(fd))){
		fscanf(fd, "%d %s %s", &loggedUserId, usr, pwd);
		if((strncmp(username, usr, 55)==0)){
           
			fclose(fd);
            return 1;
		}
	}
	
	fclose(fd);
    fd=NULL;
	fd=fopen("users.txt", "a+");
	fprintf(fd, "%d %s %s\n", loggedUserId, username, password);
	fclose(fd);

	return 0;
}
