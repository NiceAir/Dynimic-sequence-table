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

int SeqListDSize(PSeqListD ps)  //获取元素个数
{
    return ps->size;
}

int SeqListDCapacity(PSeqListD ps)  //获取顺序表的容量
{
    return ps->capacity;
}

int SeqListDIsEmpty(PSeqListD ps)    //判断顺序表是否为空
{
    if (ps->size == 0)
    {
        return 1;                   //为空返回1，不为空返回0
    }
    return 0;               
}

void SeqListDClear(PSeqListD ps)   //清空顺序表且不改变空间大小
{
    memset(ps->arry, 0, sizeof(DataType)*ps->size);
}

void SeqListDDestory(PSeqListD ps) //销毁循序表
{
    ps->capacity = 0;
    ps->size = 0;
    free(ps->arry);
    ps = NULL;
}

int CheckCapacity(PSeqListD ps)   //检查容量，如果不够就对顺序表扩容
{
    DataType *p = NULL;
    if (ps->size >= ps->capacity)
    {
        p = (DataType *)realloc(ps->arry, sizeof(DataType)*ps->capacity*2);
        if (p == NULL)
        {
            printf("对不起，空间不够\n");
            return -1;             //扩容失败返回-1
        }
        ps->arry = p;
        ps->capacity *= 2;
        return 1;                   //扩容成功返回1
    }
    return 0;                       //不需要扩容返回0
}

void PrintSeqListD(PSeqListD ps)  //打印顺序表
{
    unsigned int i = 0;
    for (i = 0; i < ps->size; i++)
    {
        printf("%d  ", ps->arry[i]);
    }
    printf("\nsize=%d\n", ps->size);
    printf("capacity=%d\n\n", ps->capacity);
}