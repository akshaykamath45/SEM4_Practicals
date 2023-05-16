#include <stdio.h>
#include <string.h>

void main()
{
    char str[100], stuff[100];
    printf("Enter sentence: ");
    gets(str);
    int i = 0, j, r, ind = 0, len;
    len = strlen(str);
    while (i < strlen(str))
    {
        r = rand() % 8 + 2;
        if (r > len && len > 0)
        {
            r = len + 1;
        }
        len = len - r - 1;
        stuff[ind++] = r + '0';
        for (j = i; j < i + r - 1; j++)
        {
            stuff[ind++] = str[j];
        }
        i = j;
    }
    puts(stuff);
}

//Alternative : Defining strings
// #include <stdio.h>
// #include <string.h>

// int main() {
//     int n, i;
//     printf("Enter the number of strings: ");
//     scanf("%d", &n);
//     char s[n][50];
//     int a[n];
//     printf("Enter strings: \n");
//     for (i = 0; i < n; i++) {
//         scanf("%s",&s[i]);
//         a[i] = strlen(s[i]);
//     }
//     printf("Output: \n");
//     for (i = 0; i < n; i++) {
//         printf("%d%s", a[i] + 1, s[i]);
//     }
//     return 0;
// }