#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv)
{
    int n = atoi(argv[1]);
    int len = (int)(n * log(n) * 1.15 + 50);

    char *sieve = calloc(sizeof(char), len);
    char *p = sieve + 2;
    char *q;

    int i = 2;
    int j = 0;
    for (; i < len; i++, p++)
    {
        if (*p == 0)
        {
            if (--n <= 0)
            {
                printf("%d\n", i);
                return 0;
            }
            j = i;
            for (q = p; j < len; j += i, q += i)
            {
                if (*q == 0)
                {
                    *q = 1;
                }
            }    
        }
    }
    printf("Error");
    return 1;
}
