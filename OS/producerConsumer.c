#include <stdio.h>
#include <stdlib.h>

int semaphore = 1;   // Semaphore to control access to critical sections
int item, temp;      // Variables to store the produced/consumed items
int count = 0;       // Count of items in the buffer
int buffer[8];       // Shared buffer
int buffer_size = 8; // Size of the buffer
int in = 0;          // Index for the next item to be produced
int out = 0;         // Index for the next item to be consumed
int full = 0;        // Count of filled slots in the buffer
int empty = 5;       // Count of empty slots in the buffer

int up(int n)
{
    return ++n;
}
int down(int n)
{
    return --n;
}

void produce_item(int *temp)
{
    printf("Enter item : ");
    scanf("%d", temp);
    printf("Produced item : %d\n", *temp);
}

void consume_item(int item)
{
    printf("Consumed item : %d\n", item);
}

void producer()
{
    produce_item(&temp);
    empty = down(empty);
    semaphore = down(semaphore);
    buffer[in] = temp;
    in = (in + 1) % buffer_size;
    full = up(full);
    semaphore = up(semaphore);
}

void consumer()
{
    full = down(full);
    semaphore = down(semaphore);
    item = buffer[out];
    out = (out + 1) % buffer_size;
    semaphore = up(semaphore);
    empty = up(empty);
    consume_item(item);
}
int main()
{
    int n, c;
    int i = 1;
    printf("Enter 1 for Producer \n Enter 2 for Consumer \n Enter 3 for Exiting \n");

    while (i > 0)
    {
        printf("Enter your choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            if ((semaphore == 1) && (empty != 0))
            {
                producer();
            }
            else
            {
                printf("Buffer is full,Producer can not produce more items\n");
            }
            break;
        case 2:
            if ((semaphore == 1) && (full > 0))
            {
                consumer();
            }
            else
            {
                printf("Buffer is empty,Consumer not allowed to consume\n");
            }
            break;

        case 3:
            exit(0);
            break;
        }
    }

    return 0;
}
