#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int msize, holes, used;
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
    printf("Enter number of memory partitions (in kB) : ");
    scanf("%d", &n_mem);

    for (int i = 0; i < n_mem; i++)
    {
        printf("Enter memory size of partition %d : ", i + 1);
        scanf("%d", &mem[i].msize);
        mem[i].used = 0;
    }

    printf("Enter number of processes : ");
    scanf("%d", &n_proc);

    for (int i = 0; i < n_proc; i++)
    {
        printf("Enter memory to be allocated for process %d : ", i + 1);
        scanf("%d", &proc[i].psize);
        proc[i].alloc = -1;
    }

    for (int i = 0; i < n_proc; i++)
    {
        int index = -1;
        for (int j = 0; j < n_mem; j++)
        {
            if ((mem[j].msize > proc[i].psize) && (!mem[j].used))
            {
                index = j;
            }
        }
        // allocaating process
        if (index != -1)
        {
            mem[index].used = 1;
            proc[i].alloc = index;
        }
        // calculating hole
        if (proc[i].alloc != -1)
        {
            mem[index].holes = mem[index].msize - proc[i].psize;
        }
    }
    for (int i = 0; i < n_proc; i++)
    {
        if (proc[i].alloc == -1)
        {
            printf("Process %d has not been allocated any partition\n", i + 1);
        }
        else
        {
            printf("Process %d has been allocated partition %d \n", i + 1, proc[i].alloc + 1);
            printf("Hole of %dkB has been generated\n", mem[proc[i].alloc].holes);
        }
    }
    return 0;
}