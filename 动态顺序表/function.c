#include "index.h"


void SeqListDInit(PSeqListD ps, int capacity)
{
    ps->capacity = capacity;
    ps->arry = (DataType *)malloc(sizeof(DataType)*capacity);
    ps->size = 0;
}

void SeqListDPushBack(PSeqListD ps, DataType data)
{
    if (CheckCapacity(ps) >= 0)
    {
        ps->arry[ps->size++] = data;
    }
}

void SeqListDPopBack(PSeqListD ps)
{
    if (SeqListDIsEmpty(ps) == 0)
    {
        ps->size--;
    }
    else printf("Pop failed, the SeqListD is already empty\n");
}

void SeqListDInsert(PSeqListD ps, int pos, DataType data)
{
    if (pos < 0 || ((unsigned int)pos) > ps->size)
    {
        printf("Error, this position is illegal\n");
        return;
    }
    if (CheckCapacity(ps) >= 0)
    {
        int i;
        for (i = ps->size; i>pos; i--)
        {
            ps->arry[i] = ps->arry[i-1];
        }
        ps->arry[pos] = data;
        ps->size++;
    }
}

void SeqListDErase(PSeqListD ps, int pos)
{
    if (pos < 0 || ((unsigned int)pos) >= ps->size)
    {
        printf("Error, this position is illeagl\n");
        return;
    }
    if (SeqListDIsEmpty(ps) == 0)
    {
        unsigned int i = 0;
        for (i = ((unsigned int)pos); i < ps->size; i++)
        {
            ps->arry[i] = ps->arry[i+1];
        }
        ps->size--;
    }
}

int SeqListDSize(PSeqListD ps)  //��ȡԪ�ظ���
{
    return ps->size;
}

int SeqListDCapacity(PSeqListD ps)  //��ȡ˳��������
{
    return ps->capacity;
}

int SeqListDIsEmpty(PSeqListD ps)    //�ж�˳����Ƿ�Ϊ��
{
    if (ps->size == 0)
    {
        return 1;                   //Ϊ�շ���1����Ϊ�շ���0
    }
    return 0;               
}

void SeqListDClear(PSeqListD ps)   //���˳����Ҳ��ı�ռ��С
{
    memset(ps->arry, 0, sizeof(DataType)*ps->size);
}

void SeqListDDestory(PSeqListD ps) //����ѭ���
{
    ps->capacity = 0;
    ps->size = 0;
    free(ps->arry);
    ps = NULL;
}

int CheckCapacity(PSeqListD ps)   //�����������������Ͷ�˳�������
{
    DataType *p = NULL;
    if (ps->size >= ps->capacity)
    {
        p = (DataType *)realloc(ps->arry, sizeof(DataType)*ps->capacity*2);
        if (p == NULL)
        {
            printf("�Բ��𣬿ռ䲻��\n");
            return -1;             //����ʧ�ܷ���-1
        }
        ps->arry = p;
        ps->capacity *= 2;
        return 1;                   //���ݳɹ�����1
    }
    return 0;                       //����Ҫ���ݷ���0
}

void PrintSeqListD(PSeqListD ps)  //��ӡ˳���
{
    unsigned int i = 0;
    for (i = 0; i < ps->size; i++)
    {
        printf("%d  ", ps->arry[i]);
    }
    printf("\nsize=%d\n", ps->size);
    printf("capacity=%d\n\n", ps->capacity);
}