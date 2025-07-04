#include <stdio.h>
#include <fcgiapp.h>
#include <fcgi_stdio.h>

#define SOCKET_PATH "127.0.0.1:8080"

int main(){
    FCGX_Init();
    int sockfd = FCGX_OpenSocket (SOCKET_PATH, 100); //длина очереди запросов сокета "0" ставится по умолчанию
    FCGX_Request req;
    FCGX_InitRequest(&req, sockfd, 0);

    while (FCGX_Accept_r(&req) >= 0){
        FCGX_FPrintF(req.out, "Content-Type: text/html\n\n");
        FCGX_FPrintF(req.out, "Hello world!");
        FCGX_Finish_r(&req);
    }
    return 0;
}