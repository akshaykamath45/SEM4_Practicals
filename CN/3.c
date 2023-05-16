#include <stdio.h>
#include <string.h>
void main()
{
    char str[100], stuff[100], sflag, eflag, esc;
    int ind = 1, i;
    printf("Enter string : ");
    gets(str);
    printf("Enter start flag : ");
    scanf(" %c", &sflag);
    printf("Enter end flag :  ");
    scanf(" %c", &eflag);
    printf("Enter escape character :  ");
    scanf(" %c", &esc);
    stuff[0] = sflag;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == sflag || str[i] == eflag || str[i] == esc)
            stuff[ind++] = esc;
        stuff[ind++] = str[i];
    }
    stuff[ind] = eflag;
    puts(stuff);
}
