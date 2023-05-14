#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int allocate[10], maxNeed[10], remaining[10], satisfied;
} Process;

Process proc[10];
int main()
{
    int resources, totalResource[10], availableResource[10], totalProcess, completed = 0;
    printf("Enter number of resources : ");
    scanf("%d", &resources);

    printf("Enter total resources for each process : \n");
    for (int i = 0; i < resources; i++)
    {
        scanf("%d", &totalResource[i]);
        availableResource[i] = totalResource[i];
    }

    printf("Enter total number of processes : ");
    scanf("%d", &totalProcess);

    printf("Enter process allocation for each process : \n");
    for (int i = 0; i < totalProcess; i++)
    {
        proc[i].satisfied = 0;
        for (int j = 0; j < resources; j++)
        {
            scanf("%d", &proc[i].allocate[j]);
            availableResource[j] -= proc[i].allocate[j];
        }
    }
    printf("Enter MAX need for each process : \n");
    for (int i = 0; i < totalProcess; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            scanf("%d", &proc[i].maxNeed[j]);
        }
    }
    for (int i = 0; i < totalProcess; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            proc[i].remaining[j] = proc[i].maxNeed[j] - proc[i].allocate[j];
        }
    }

    printf("\nTotal Resources : \n");
    for (int i = 0; i < resources; i++)
    {
        printf("%d\t", totalResource[i]);
    }
    printf("\nAvailable Resources : \n");
    for (int i = 0; i < resources; i++)
    {
        printf("%d\t", availableResource[i]);
    }

    printf("\nAllocation Graph : \n");
    for (int i = 0; i < totalProcess; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            printf("%d\t", proc[i].allocate[j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Max Need Graph : \n");
    for (int i = 0; i < totalProcess; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            printf("%d\t", proc[i].maxNeed[j]);
        }
        printf("\n");
    }
    printf("\nRemaining Graph : \n");
    for (int i = 0; i < totalProcess; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            printf("%d\t", proc[i].remaining[j]);
        }
        printf("\n");
    }
    printf("\n");

    while (completed < totalProcess)
    {
        int satisfiedProcess = -1;
        for (int i = 0; i < totalProcess; i++)
        {
            if (proc[i].satisfied != 1)
            {
                int count = 0;
                for (int j = 0; j < resources; j++)
                {
                    if (proc[i].remaining[j] <= availableResource[j])
                    {
                        count++;
                    }
                }
                if (count == resources)
                {
                    satisfiedProcess = i;
                    break;
                }
            }
        }
        if (satisfiedProcess != -1)
        {
            proc[satisfiedProcess].satisfied = 1;
            for (int j = 0; j < resources; j++)
            {
                availableResource[j] += proc[satisfiedProcess].allocate[j];
            }
            printf("P%d\t", satisfiedProcess + 1);
            completed++;
        }
        else
        {
            printf("Deadock");
            break;
        }
    }
}
