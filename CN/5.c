#include <stdio.h>
#include <string.h>

void transmit(int par)
{
    int data[8], sendData[4];

    printf("Enter 4 bit data : ");
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &sendData[i]);
    }
    data[3] = sendData[3];
    data[5] = sendData[2];
    data[6] = sendData[1];
    data[7] = sendData[0];
    if (par == 1)
    {
        data[1] = data[3] ^ data[5] ^ data[7];
        data[2] = data[3] ^ data[6] ^ data[7];
        data[4] = data[5] ^ data[6] ^ data[7];
    }
    else
    {
        data[1] = 1 - (data[3] ^ data[5] ^ data[7]);
        data[2] = 1 - (data[3] ^ data[6] ^ data[7]);
        data[4] = 1 - (data[5] ^ data[6] ^ data[7]);
    }
    printf("Hamming Code Transmitted is : ");
    for (int i = 7; i > 0; i--)
    {
        printf("%d", data[i]);
    }
    printf("\n");
}

void recieve(int par)
{
    int data[8], idealData[5], i, e = 0;

    printf("Enter 7 bit recieved data : ");
    for (i = 7; i > 0; i--)
    {
        scanf("%d", &data[i]);
    }
    if (par == 1)
    {
        idealData[1] = data[3] ^ data[5] ^ data[7] ^ data[1];
        idealData[2] = data[3] ^ data[6] ^ data[7] ^ data[2];
        idealData[4] = data[5] ^ data[6] ^ data[7] ^ data[4];
    }
    else
    {
        idealData[1] = 1 - (data[3] ^ data[5] ^ data[7] ^ data[1]);
        idealData[2] = 1 - (data[3] ^ data[6] ^ data[7] ^ data[2]);
        idealData[4] = 1 - (data[5] ^ data[6] ^ data[7] ^ data[4]);
    }

    e = 4 * idealData[4] + 2 * idealData[2] + idealData[1];

    if (e == 0)
    {
        printf("No Errors \n");
    }
    else
    {
        data[e] = 1 - data[e];
        printf("Corrected hamming code : ");
        for (i = 7; i > 0; i--)
        {
            printf("%d", data[i]);
        }
    }

    printf("\n");
}

int main()
{
    int par, ch;
    do
    {
        printf("Enter 1 for even parity ,0 for odd partiy : ");
        scanf("%d", &par);

        printf("Enter 1 for Transmission \nEnter 2 for Recvieving \nEnter 3 For Exiting \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            transmit(par);
            break;
        case 2:
            recieve(par);
            break;
        case 3:
            printf("Exiting Program ");
            break;
        }
    } while (ch != 3);
    return 0;
}