#include <stdio.h>
#include <string.h>
void main()
{
    char str[100], stuff[100];
    int i = 0, j, ct = 0, ind = 0;
    printf("Enter string in binary ");
    gets(str);
    while (i < strlen(str))
    {
        ct = 0;
        for (j = i; j < i + 5; j++)
        {
            if (str[j] == '1')
                ct++;
        }
        if (ct == 5)
        {
            for (j = i; j < i + 5; j++)
            {
                stuff[ind++] = str[i];
            }
            stuff[ind++] = 'x';
            i = j;
        }
        else
        {
            stuff[ind++] = str[i];
            i++;
        }
    }
    puts(stuff);
}