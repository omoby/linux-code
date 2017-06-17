#ifndef _QUEUE_H
#define _QUEUE_H
#include<iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 4096
typedef int ElemType;
typedef struct Queue {
    ElemType *base;
    int wp;//写指针
    int rp;//读指针
    int queueCnt;//标记队列是否满或空
} CommQueue;
//队列状态：满、空、运行正确、运行错误
typedef enum {
    QueueFull = 0,
    QueueEmpty,
    QueueOK,
    QueueFail
} QueueStatus;
//初始化队列
QueueStatus init_queue(CommQueue* queue);
//入队列
QueueStatus inQueue(ElemType val, CommQueue* queue);
//出队列
QueueStatus outQueue(CommQueue* queue, ElemType *val);
//读取缓冲区数据
int readQueue(ElemType *buf, int size, CommQueue *queue);
//往缓冲区写入数据
int writeQueue(const ElemType *buf, int size, CommQueue *queue);


QueueStatus init_queue(CommQueue* queue)
{
    queue->base =(ElemType *)calloc(sizeof(ElemType) * MAXSIZE, 1);
    //分配失败
    if (queue->base == NULL)
    {
        perror("malloc()");
        return QueueFail;
    }
    //初始化读写指针
    queue->wp = queue->rp = 0;
    //初始化队列中元素个数
    queue->queueCnt = 0; // conuter
}
static int isFull(CommQueue *queue)
{
    return (queue->queueCnt == MAXSIZE - 1) ? 1 : 0;
}
static int isEmpty(CommQueue *queue)
{
    return (0==queue->queueCnt)? 1 : 0;
}
QueueStatus inQueue(ElemType val, CommQueue *queue)
{
    if (1==isFull(queue))
    {
        return QueueFull;
    }
    else
    {
        memcpy((queue->base + queue->wp),&val, sizeof(ElemType));
        //回转
        if (++(queue->wp) == MAXSIZE)
        {
            queue->wp = 0;
        }
        //元素个数加1
        (queue->queueCnt)++;
    }
    return QueueOK;
}
QueueStatus outQueue(CommQueue *queue, ElemType *val)
{
    if (1==isEmpty(queue))
    {
        return QueueEmpty;
    }
    else {
        int index = queue->rp;
        if (++(queue->rp) == MAXSIZE)
        {
            queue->rp = 0;
        }
        (queue->queueCnt)--;
        memcpy(val ,(queue->base + index), sizeof(ElemType));
    }
    return QueueOK;
}
int readQueue(ElemType *buf, int len, CommQueue * queue)
{
    int i ;
    ElemType val;
    for (i=0; i < len; i++)
    {
        QueueStatus ret = outQueue(queue, &val);
        if (ret != QueueEmpty)
        {
            memcpy(buf+i, &val, sizeof(ElemType));
        } else
        {
            break;
        }
    }
    return i;
}
int writeQueue(const ElemType *buf, int len, CommQueue *queue)
{
    int i ;
    for (i=0; i < len; i++)
    {
        QueueStatus ret = inQueue(buf[i], queue);
        if (ret == QueueFull)
        {
            break;
        }
    }
    //printf("%s/n", (char *)(queue->base));
    return i;
}
#endif//_QUEUE_H
