#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef struct Heap
{
    int capacity;
    int size;
    int* element;
}Heap;

Heap* init_heap(Heap* head, int capacity)
{
    head = (Heap*)malloc(sizeof(Heap));
    if (head == NULL)
    {
        perror("init_heap");
        return NULL;
    }

    head->capacity = capacity++;
    head->size = 0;
    head->element = (int*)calloc(capacity, sizeof(int));
    if (head->element == NULL)
    {
        perror("init_heap");
        free(head);
        return NULL;
    }
    
    head->element[0] = -2147483648;
    return head;
}

int isfull(Heap* p)
{
    return p->capacity == p->size;
}

void insert_heap(int x, Heap* p)
{
    int index;
    if (isfull(p))
    {
        puts("This heap if full!");
        return;
    }

    for (index = ++p->size; p->element[index / 2] > x; index /= 2)
    {
        p->element[index] = p->element[index / 2];
    }

    p->element[index] = x;
}

void print_heap(Heap* p)
{
    for (int i = 1; p->element[i] != 0; i++)
    {
        printf("%d ", p->element[i]);
    }
    putchar('\n');
}
#include<limits.h>
int main()
{
    Heap* heap_head = init_heap(heap_head, 30);
    if (heap_head == NULL)
    {
        perror("main");
        return 1;
    }

    insert_heap(5, heap_head);
    insert_heap(8, heap_head);
    insert_heap(9, heap_head);
    insert_heap(2, heap_head);
    print_heap(heap_head);
    printf("%lld %lld %lld %lld\n", LONG_MAX, LONG_MIN, LLONG_MAX, LLONG_MIN);

    return 0;
}