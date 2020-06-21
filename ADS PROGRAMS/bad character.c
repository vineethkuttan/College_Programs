# include <limits.h>
# include <string.h>
# include <stdio.h>
# define CH 256
# define MAX 100
int max (int a, int b)
{
    return (a > b)? a: b;
}
void bad_Char_Heuristic( char pat[], int size, int badchar[])
{
    int i;
    for (i = 0; i < CH; i++)
    badchar[i] = -1;
    for (i = 0; i < size; i++)
    badchar[(int) pat[i]] = i;
}
void search(char txt[], char pat[])
{
    int M = strlen(pat);
    int N = strlen(txt);
    int badchar[CH];
    bad_Char_Heuristic(pat,M,badchar);
    int s = 0;
    while(s <= (N-M))
    {
            int j = M-1;
            while(j >= 0 && pat[j] == txt[s+j])
                j--;
            if (j < 0)
            {
                printf("Found pattern at index : %d \n", s);
                s += (s+M < N)? M-badchar[txt[s+M]] : 1;
            }
            else
                s += max(1, j-badchar[txt[s+j]]);
    }
}
int main()
{
    char txt[MAX],pat[MAX];
    printf("\n ENTER THE TEXT : ");
    gets(txt);
    printf("\n ENTER THE PATTERN : ");
    gets(pat);
    search(txt, pat);
    return 0;
}
