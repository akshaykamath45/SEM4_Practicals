#include <stdio.h>
#include <string.h>

int pi[100];

void prefix_function(char p[])
{
    int len = strlen(p);
    int k = 0;
    pi[0] = 0;
    for (int i = 1; i < len; i++)
    {
        while (k > 0 && p[k] != p[i])
        {
            k = pi[k - 1];
        }
        if (p[k] == p[i])
        {
            k++;
        }
        pi[i] = k;
    }
}

int main()
{
    char text[200] = "abacbcdabcdabdabc";
    char pattern[100] = "abc";
    int tlen, plen, q = 0;
    tlen = strlen(text);
    plen = strlen(pattern);
    prefix_function(pattern);
    for (int i = 0; i < tlen; i++)
    {
        while (q > 0 && pattern[q] != text[i])
        {
            q = pi[q - 1];
        }
        if (pattern[q] == text[i])
        {
            q++;
        }
        if (q == plen)
        {
            printf("Pattern occurs after index %d\n", i - plen + 1);
        }
    }
    return 0;
}