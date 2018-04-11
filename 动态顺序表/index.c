#include "index.h"
int main()
{
    SeqListD ps;
    SeqListDInit(&ps, 5);

    SeqListDPushBack(&ps, 2);
    SeqListDPushBack(&ps, 1);
    SeqListDPushBack(&ps, 5);
    SeqListDPushBack(&ps, 3);
    SeqListDPushBack(&ps, 4);
    SeqListDPushBack(&ps, 4);
    SeqListDPopBack(&ps);

    SeqListDInsert(&ps, 0, 8);
    SeqListDErase(&ps, 4);

    PrintSeqListD(&ps);
    SeqListDClear(&ps);
    SeqListDDestory(&ps);
    return 0;
}