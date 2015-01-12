/* Server side of network */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *message)
{
    perror(message);
    exit(1);
}

int main(int argc, char *argv[])
{
     int sockfd;
     int newsockfd;
     int portno;
     socklen_t clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     /* checks for input */
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     /* Sets socket */
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0)
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     /* Bind */
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0)
              error("ERROR on binding");
    /* listen */
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     /* creates new socket to be accepted */
     newsockfd = accept(sockfd,
                 (struct sockaddr *) &cli_addr,
                 &clilen);
     if (newsockfd < 0)
          error("ERROR on accept");
     bzero(buffer,256);
     /* read */
     n = read(newsockfd,buffer,255);
     if (n < 0) error("ERROR reading from socket");
     printf("The message: %s\n",buffer);
     /* write */
     n = write(newsockfd,"message received!\n",18);
     if (n < 0) error("ERROR writing to socket");
     /* close new socket */
     close(newsockfd);
     /* close original socket */
     close(sockfd);
     return 0;
}
