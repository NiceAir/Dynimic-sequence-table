#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#pragma once
#define DataType int

typedef struct SeqListD{
    DataType * arry;    //���ݿ��ͷָ��
    size_t size;        //ʹ���� size_t ʵ������unsigned int �ı���
    size_t capacity;    //������
}*PSeqListD, SeqListD;


void SeqListDInit(PSeqListD ps, int capacity);
void SeqListDPushBack(PSeqListD ps, DataType data);
void SeqListDPopBack(PSeqListD ps);
void SeqListDInsert(PSeqListD ps, int pos, DataType data);
void SeqListDErase(PSeqListD ps, int pos);

int SeqListDSize(PSeqListD ps); //��ȡԪ�ظ���
int SeqListDCapacity(PSeqListD ps); //��ȡ˳��������
int SeqListDIsEmpty(PSeqListD ps);  //�ж�˳����Ƿ�Ϊ��

void SeqListDClear(PSeqListD ps);   //���˳����Ҳ��ı�ռ��С
void SeqListDDestory(PSeqListD ps); //����ѭ���

int CheckCapacity(PSeqListD ps);    //��˳�������

void PrintSeqListD(PSeqListD ps);   //��ӡ˳���