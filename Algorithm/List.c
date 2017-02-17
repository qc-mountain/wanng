#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int elem;
    struct node *next;
} *List;

List init()   //初始化，头节点
{
    List pnode = (List)malloc(sizeof(List));
    pnode -> next = NULL;

    return pnode;
}

bool isLast(List p)  //是否尾结点
{
    return p -> next == NULL;
}

void insertOne(List L, int x)   //插入一个新节点
{
    List newOne = (List)malloc(sizeof(List));
    newOne -> elem = x;
    newOne -> next = L -> next;
    L -> next = newOne;

    return ;
}

List findPrevious(List L, int x)   //查找该节点的前一个节点
{
    List p = L -> next;

    while( p -> next && p -> next -> elem != x) {
        p = p -> next;
    }
    return p;
}

void deleteOne(List L, int x)  //删除一个节点
{
    List p, tem;m
    p = findPrevious(L, x);

    if(!isLast(p)) {
        tem = p -> next;
        p -> next = tem -> next;
        free(tem);
    }

    return ;
}

void deleteList(List L)   //删除整个链表
{
    List p, tem;
    p = L -> next;
    L -> next = NULL;

    while(p) {
        tem = p -> next;
        free(p);
        p = tem;
    }
    return ;
}

void display(List L)   //展示所有信息
{
    List p;
    p = L -> next;

    if(!p) printf("ÎÞÄÚÈÝ");

    while(p) {
        printf("%d ", p -> elem);
        p = p -> next;
    }
    printf("\n");
    return ;
}

int main()
{
    List one = init();
    insertOne(one, 4);
    insertOne(one, 8);
    insertOne(one, 99);
    insertOne(one, 93);
    display(one);
    deleteOne(one, 8);
    display(one);
    return 0;
}
