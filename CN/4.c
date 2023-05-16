#include <stdio.h>
#include <string.h>

#define N strlen(gen_poly)

char data[28];
char check_value[28];
char gen_poly[10];
int data_length, i, j;

void XOR()
{
    for (j = 1; j < N; j++)
    {
        check_value[j] = (check_value[j] == gen_poly[j]) ? '0' : '1';
    }
}

void crc()
{
    for (i = 0; i < N; i++)
    {
        check_value[i] = data[i];
    }
    do
    {
        if (check_value[0] == '1')
        {
            XOR();
        }
        for (j = 0; j < N - 1; j++)
        {
            check_value[j] = check_value[j + 1];
        }
        check_value[j] = data[i++];
    } while (i <= data_length + N - 1);
}

void reciever()
{
    printf("Enter recieved data : ");
    scanf("%s", data);
    printf("\nRecieved data : %s \n", data);
    crc();
    if (i < N - 1)
    {
        printf("\nError Detected\n");
    }
    else
    {
        printf("\nNo Error Detected\n");
    }
}
int main()
{
    printf("Enter data to be transmitted : ");
    scanf("%s", data);

    printf("Enter generator polynomial function : ");
    scanf("%s", gen_poly);

    data_length = strlen(data);

    printf("Data to be transmitted is : %s \n", data);

    for (int i = data_length; i < data_length + N - 1; i++)
    {
        data[i] = '0';
    }

    printf("Data after appending n-1 zeroes's is : %s \n", data);

    crc();

    printf("CRC or Check Value is : %s \n", check_value);

    for (int i = data_length; i < data_length + N - 1; i++)
    {
        data[i] = check_value[i - data_length];
    }

    printf("Final Data to be sent is : %s\n", data);

    reciever();

    return 0;
}