#include<stdio.h>
#include<stdlib.h>
#define Maxsize 5
typedef struct{
    int data[Maxsize];
    int front,rear;
}SeqQueue;
//��ʼ��
void InitQueue(SeqQueue &Q){
    Q.front=Q.rear=0;
}
//�ж�Ϊ��
bool QueueEmpty(SeqQueue &Q){
    if(Q.front==Q.rear){
        return true;
    }
    return false;
}
//���---ֻ���ڶ�β����
bool EnQueue(SeqQueue &Q,int e){
    if(Q.rear==Maxsize){//����
        return false;
    }
    Q.data[Q.rear]=e;
    Q.rear++;
    return true;
}
//����---ֻ���ڶ�ͷ��
bool DeQueue(SeqQueue &Q,int &e){
  if(Q.front==Q.rear){//�п�
      return false;
  }
  e=Q.data[Q.front];
  Q.front=Q.front+1;
  return true;
}
//����ͷԪ��
bool GetHead(SeqQueue&Q,int &e){
    if(Q.front==Q.rear){
        return false;
    }
    e=Q.data[Q.front];
    return true;
}
int GetSize(SeqQueue&Q){
    return Q.rear-Q.front;
}
//��ӡ
void PrintList(SeqQueue&S){
    for(int i=S.front;i!=S.rear;i++){
        printf("%d\t",S.data[i]);
    }
    printf("\n");
}
int main(){
    int e;
    bool b;
    SeqQueue(Q);
    InitQueue(Q);
    if(QueueEmpty(Q)) printf("����Ϊ��\n");
    EnQueue(Q,1);
    printf("Ԫ��1��Ӻ󣬶��д�С:%d\n",GetSize(Q));
    EnQueue(Q,3);
    printf("Ԫ��3��Ӻ󣬶��д�С:%d\n",GetSize(Q));
    EnQueue(Q,5);
    printf("Ԫ��5��Ӻ󣬶��д�С:%d\n",GetSize(Q));
    EnQueue(Q,7);
    printf("Ԫ��7��Ӻ󣬶��д�С:%d\n",GetSize(Q));
    EnQueue(Q,9);
    printf("Ԫ��9��Ӻ󣬶��д�С:%d\n",GetSize(Q));
    PrintList(Q);
    b=EnQueue(Q,10);
    if(!b)printf("��������������10ʧ��");
    DeQueue(Q,e);
    printf("��ͷԪ��%d����\n",e);
    b=EnQueue(Q,10);
    if(!b){
        printf("��������������10ʧ�ܣ����д�С��%d\n",GetSize(Q));
        printf("-----˵�����м����-----\n");
        PrintList(Q);
    }
    DeQueue(Q,e);
    DeQueue(Q,e);
    DeQueue(Q,e);
    if(QueueEmpty(Q)){
        printf("����Ԫ�س��ӣ�����Ϊ��");
    }
    PrintList(Q);
    return 0;
}