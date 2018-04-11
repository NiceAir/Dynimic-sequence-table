#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#pragma once
#define DataType int

typedef struct SeqListD{
    DataType * arry;    //数据块的头指针
    size_t size;        //使用量 size_t 实际上是unsigned int 的别名
    size_t capacity;    //总容量
}*PSeqListD, SeqListD;


void SeqListDInit(PSeqListD ps, int capacity);
void SeqListDPushBack(PSeqListD ps, DataType data);
void SeqListDPopBack(PSeqListD ps);
void SeqListDInsert(PSeqListD ps, int pos, DataType data);
void SeqListDErase(PSeqListD ps, int pos);

int SeqListDSize(PSeqListD ps); //获取元素个数
int SeqListDCapacity(PSeqListD ps); //获取顺序表的容量
int SeqListDIsEmpty(PSeqListD ps);  //判断顺序表是否为空

void SeqListDClear(PSeqListD ps);   //清空顺序表且不改变空间大小
void SeqListDDestory(PSeqListD ps); //销毁循序表

int CheckCapacity(PSeqListD ps);    //对顺序表扩容

void PrintSeqListD(PSeqListD ps);   //打印顺序表