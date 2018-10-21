#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sieve(int n)
{
    if (n == 1)
    {
        return 2;
    }
    int len = (int)(n * log(n) * 1.15 + 50);
    n--; // Subtract 1 for 2 as first prime

    int *sieve = calloc(sizeof(int), len);
    int *p = sieve + 2;
    int *q;

    int num;
    int i = 2;
    int j = 2;
    for (; i < len; i++)
    {
        if (!(sieve[i / 32] & 1 << (i % 32)))
        {
            num = 2 * i - 1;
            if (!--n)
            {
                free(sieve);
                return num;
            }
            else
            {
                for (j = i; j < len; j += num)
                {
                    sieve[j / 32] |= 1 << (j % 32);
                }
            }
        }
    }

    return -1;
}
