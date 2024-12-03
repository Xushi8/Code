#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

int main()
{
    struct addrinfo hints, *res;
    int status;

    // 设置 hints
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;       // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP

    // 获取地址信息
    if ((status = getaddrinfo("www.example.com", "http", &hints, &res)) != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 1;
    }

    // 这里可以使用返回的地址信息 res

    freeaddrinfo(res); // 释放返回的内存
    return 0;
}
