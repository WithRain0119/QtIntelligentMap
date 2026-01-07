#include "SQUEUE.h"
#include "STRUCT.h"
#include <iostream>

int IniSqueue(SqQueue& s){
    s.base =new int[MQUEUESIZE];
    s.front=s.rear=0;
    return 1;
}

int isEmpty(SqQueue q){
    return q.front==q.rear;
}

int isFull(SqQueue q){
    if(q.front==(q.rear+1+ MQUEUESIZE)% MQUEUESIZE){
        return OK;
    }else{
        return ERROR;
    }
}

int EnQueue(SqQueue& Q,int num){
    if(isFull(Q)){
        return ERROR;
    }else{
        Q.base[Q.rear]=num;
        Q.rear=(Q.rear+1)% MQUEUESIZE;
        return OK;
    }
}

int DeQueue(SqQueue& Q,int &num){
    if(isEmpty(Q)){
        return ERROR;
    }else{
        num=Q.base[Q.front];
        Q.front=(Q.front+1)% MQUEUESIZE;
        return OK;
    }
}

Status ReleaseQueue(SqQueue& Q)
{
    if (!Q.base)
        return OK;
    delete[] Q.base;
    Q.base = NULL;
    return OK;
}