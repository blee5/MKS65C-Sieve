#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sieve(int n)
{
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
                return i;
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
    return -i;
}
