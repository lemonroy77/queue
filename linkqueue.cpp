#include<stdio.h>
#include<stdlib.h>
#define MaxSize 5
typedef int ElemType;
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct {
    LinkNode *front, *rear;
}LinkQueue;
void InitQueue(LinkQueue &Q){
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}
//带头节点的入队列
void EnQueue(LinkQueue &Q, ElemType x){
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
//  if(Q.front==NULL) Q.front=s;Q.rear=s;  不带头节点的特殊处理
    Q.rear->next = s;
    Q.rear = s;
}
//出队列
bool DeQueue(LinkQueue &Q, ElemType &x){
    if(Q.rear == Q.front) return false;//只有一个节点
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if(Q.rear == p)//出队的是最后一个节点
        Q.rear = Q.front;
    //if(Q.rear==p) Q.rear=Q.front=NULL;
    free(p);
    return true;
}
void PrintQueue(LinkQueue Q) {
    LinkNode* p = Q.front->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main(){
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q,1);
    EnQueue(Q,2);
    EnQueue(Q,3);
    int x;
    DeQueue(Q, x);
    DeQueue(Q, x);
    PrintQueue(Q);
    return 0;
}
