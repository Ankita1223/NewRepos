#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>
#include <unistd.h>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]){

int sockfd,connfd;
size_t clilen;

struct sockaddr_in sa,ca;

sockfd=socket(AF_INET,SOCK_STREAM,0);

bzero(&sa,sizeof(sa));
sa.sin_family=AF_INET;
sa.sin_addr.s_addr=INADDR_ANY;
sa.sin_port=htons(atoi(argv[1]));

bind(sockfd,(sockaddr*)&sa,sizeof(sa));

listen(sockfd,10);
cout<<"Listening....."<<endl;
clilen=sizeof(ca);
int n;
while (1) {
        int connfd = accept(sockfd, (sockaddr*)&ca, (socklen_t*)&clilen);
        
        int pid = fork();
        if (pid == 0) {
            close(sockfd);
            cout << "server connection successful" << endl;

            char buff[256];
            memset(buff, 0, sizeof(buff));
            read(connfd, buff, 255);
            cout << "Message from client: " << buff << endl;

            int len = strlen(buff);
            write(connfd, buff, sizeof(buff));
            exit(0);
        } else {
            close(connfd);
        }
    }
    return 0;
}
