#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char** argv)
{
#ifdef debug
    printf("debug\n");
    char s[100] = "/home/reflecter/Documents/MyCode/Code-Cpp/Aproject/linux_learning/mmapcopy.c";
    argc = 2;
    argv = (char**)malloc(2 * sizeof(char*));
    char tmp = argc + '0';
    argv[0] = &tmp;
    argv[1] = s;
#endif

    if (argc != 2)
    {
        printf("输入参数: 文件路径\n");
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        printf("文件打开失败！\n");
        exit(1);
    }

    size_t size = 0;
    struct stat buf;
    if (-1 == fstat(fd, &buf))
    {
        printf("获取文件信息失败！\n");
        exit(1);
    }
    else
    {
        size = buf.st_size;
    }

#ifdef debug
    printf("fd = %d\n", fd);
    printf("size = %ld\n", size);
#endif

    void* address = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (MAP_FAILED == address)
    {
        printf("内存映射失败！\n");
        exit(1);
    }
    if (-1 == write(STDOUT_FILENO, address, size))
    {
        printf("写到标准输出失败！\n");
        exit(1);
    }

    printf("\n");
    close(fd);
    return 0;
}