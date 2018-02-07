#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[]) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in sa;
    memset((char*)&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &sa.sin_addr);
    sa.sin_port = htons(atoi(argv[2]));

    connect(sockfd, (struct sockaddr*)&sa, sizeof(sa));
	cout<<"Connected"<<endl;
    char buff[256];
    memset(buff, 0, sizeof(buff));
    cout << "Enter message: ";
    cin.getline(buff, 255);
    write(sockfd, buff, strlen(buff));

    memset(buff, 0, sizeof(buff));
    read(sockfd, buff, sizeof(buff));
    cout << "Message back from server: " << buff << endl;
    return 0;
}
