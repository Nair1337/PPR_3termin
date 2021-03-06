/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "app.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAXLINE 1024

int send_data(char* data,size_t size){
	int sockfd;
	struct sockaddr_in servaddr;
	
	// Creating socket file descriptor 
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
  
    memset(&servaddr, 0, sizeof(servaddr)); 
      
    // Filling server information 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
	
	sendto(sockfd, data, size, 
        MSG_CONFIRM, (const struct sockaddr *) &servaddr,  
            sizeof(servaddr)); 
            
    return 0;
}

int *procedure_1_svc(print_data *argp, struct svc_req *rqstp)
{
	int i;
	/*
	 * insert server code here
	 */
	for (i = 0; i < argp->size; i++)
	{
		printf("%c", argp->buffer[i]);
		fflush(stdout);
		
		argp->buffer[i]+=1;
	}
	send_data(argp->buffer,argp->size);
	return &argp->size;
}
