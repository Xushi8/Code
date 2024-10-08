#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>

#define PORT 8080
#define BACKLOG 10

int main(void)
{
    int sockfd;
    struct sockaddr_in6 servaddr;

    // 创建IPv6套接字
    if ((sockfd = socket(AF_INET6, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // 配置服务器地址结构体，设置为监听所有IPv6地址，同时允许接受IPv4映射的IPv6地址
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin6_family = AF_INET6;  // 使用IPv6地址族
    servaddr.sin6_addr = in6addr_any; // 监听所有IPv6地址，相当于IPv4中的INADDR_ANY
    servaddr.sin6_port = htons(PORT); // 监听端口

    // 绑定套接字到指定地址
    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Socket bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // 开始监听
    if (listen(sockfd, BACKLOG) < 0)
    {
        perror("Listen failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    // 此处可以添加代码来接受连接并处理请求，例如使用accept()函数

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(100s);

    return 0;
}