#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

void LCS(char *str1, char *str2, int m, int n, int seq_length[][MAX], char symbol[][MAX])
{

    for (int i = 0; i <= m; i++)
    {
        seq_length[i][0] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        seq_length[0][i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                seq_length[i][j] = seq_length[i - 1][j - 1] + 1;
                symbol[i - 1][j - 1] = '\\'; // Diagonal
            }
            else if (seq_length[i - 1][j] > seq_length[i][j - 1])
            {
                seq_length[i][j] = seq_length[i - 1][j];
                symbol[i - 1][j - 1] = '|'; // top
            }
            else
            {
                seq_length[i][j] = seq_length[i][j - 1];
                symbol[i - 1][j - 1] = '-'; // left
            }
        }
    }
}

void print_LCS(char *str1, char *str2, int i, int j, int last, char ans[], char symbol[][MAX])
{
    if (i == -1 || j == -1)
    {
        return;
    }
    else if (symbol[i][j] = '\\')
    {
        ans[last - 1] = str1[i];
        last--;
        print_LCS(str1, str2, i - 1, j - 1, last, ans, symbol);
    }
    else if (symbol[i][j] = '|')
    {
        print_LCS(str1, str2, i - 1, j, last, ans, symbol);
    }
    else
    {
        print_LCS(str1, str2, i, j - 1, last, ans, symbol);
    }
}

void printTable(int seq_length[][MAX], char symbol[][MAX], int m, int n)
{
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%d\t", seq_length[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c\t", symbol[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}
int main()
{
    char str1[MAX], str2[MAX];
    int seq_length[MAX][MAX];
    char symbol[MAX][MAX];
    int m, n;
    printf("Enter String 1 : \n");
    scanf("%s", &str1);

    printf("Enter String 2 : \n");
    scanf("%s", &str2);

    m = strlen(str1);
    n = strlen(str2);

    LCS(str1, str2, m, n, seq_length, symbol);
    printTable(seq_length, symbol, m, n);

    char ans[MAX];
    int last = seq_length[m][n];
    ans[last] = '\0';
    print_LCS(str1, str2, m - 1, n - 1, last, ans, symbol);

    printf("The longest common subsequence is : \'%s\'", ans);
}
