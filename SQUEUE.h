#ifndef SQUEUE_H
#define SQUEUE_H
typedef int Status;
#define ERROR 0
#define OK 1
typedef struct{
    int *base;
    int front;
    int rear;
}SqQueue;
Status IniSqueue(SqQueue& s);
Status isEmpty(SqQueue q);
Status isFull(SqQueue q);
Status EnQueue(SqQueue& Q,int num);
Status DeQueue(SqQueue& Q,int &num);
Status ReleaseQueue(SqQueue& Q);
#endif