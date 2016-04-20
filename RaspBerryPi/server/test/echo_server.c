/*구 버전의 라이브러리를 사용 segement fault core dump 현상이 발생
ubunto의 core정보 확인후에도 같은 결과
*/
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXBUF 1023

int main(int argc, char **argv){
	
	int server_sockfd, client_sockfd;
	int client_len, n;
	
	char buf[MAXBUF];
	struct sockaddr_in clientaddr, serveraddr;
	
	client_len = sizeof(clientaddr);
	
	if((server_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1 ){
		perror("socket error : ");
		exit(0);
	}
	
	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(atoi(argv[1]));
	
	bind(server_sockfd,(struct sockaddr *) &serveraddr, sizeof(serveraddr));
	listen(server_sockfd, 5);
	
	while(1){
		memset(buf,0x00, MAXBUF);
		client_sockfd = accept(server_sockfd,(struct sockaddr *)& clientaddr, &client_len);
		printf("New Client Connect: %s\n",inet_ntoa(clientaddr.sin_addr));
		
		if((n = read(client_sockfd, buf, MAXBUF)) <= 0){
			close(client_sockfd);
			continue;
		}
		
		if(write(client_sockfd,buf,MAXBUF) <= 0){
			perror("write error : ");
			close(client_sockfd);
		}
		
		close(client_sockfd);
	}
	
	close(client_sockfd);
	return 0;
}
