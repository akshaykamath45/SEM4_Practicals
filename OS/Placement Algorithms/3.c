#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int msize, hole, used;
} Memory;

typedef struct
{
    int psize, alloc;
} Process;
int main()
{
    Process proc[10];
    Memory mem[10];
    int n_mem, n_proc;
    printf("Enter number of partitions available in the memory : ");
    scanf("%d", &n_mem);

    for (int i = 0; i < n_mem; i++)
    {
        printf("Enter size of partition %d in kB ", i + 1);
        scanf("%d", &mem[i].msize);
        mem[i].used = 0;
    }

    printf("\n");

    printf("Enter number of processes to be allocated inside memory : ");
    scanf("%d", &n_proc);

    for (int i = 0; i < n_proc; i++)
    {
        printf("Enter size of process %d to be allocated into memory partitions : ", i + 1);
        scanf("%d", &proc[i].psize);
        proc[i].alloc = -1;
    }
    int prev = -1;
    for (int i = 0; i < n_proc; i++)
    {
        int index = -1;
        for (int j = prev + 1; j < n_mem; j++)
        {
            if (mem[j].msize >= proc[i].psize && !mem[j].used)
            {
                index = j;
                prev = j;
                break;
            }
        }
        if (index != -1)
        {
            mem[index].used = 1;
            proc[i].alloc = index;
        }
        if (proc[i].alloc != -1)
        {
            mem[index].hole = mem[index].msize - proc[i].psize;
        }
    }

    printf("\n");
    for (int i = 0; i < n_proc; i++)
    {
        if (proc[i].alloc == -1)
            printf("Process %d has not been allocated any memory\n", i + 1);
        else
        {
            printf("Process %d has been allocated partition No. %d\n", i + 1, proc[i].alloc + 1);
            printf("A hole of %dkB has been generated \n", mem[proc[i].alloc].hole);
        }
        printf("\n");
    }
    return 0;
}