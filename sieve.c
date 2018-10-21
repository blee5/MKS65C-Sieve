#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sieve(int n)
{
    if (n == 1)
    {
        return 2;
    }
    int len = (int)(n * log(n) * 1.15 + 50) / 2;
    n--; // Subtract 1 for 2 as first prime
    int *sieve = calloc(sizeof(int), 1 + len / (sizeof(int) * 8));
    int *p = sieve + 2;
    int *q;

    int num;
    int i;
    int j;

    int bound = (int)(sqrt(2 * len - 1) + 1) / 2;
    for (; i < bound; i++)
    {
        if (!(sieve[i / 32] & 1 << (i % 32)))
        {
            num = 2 * i + 3;
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
    for (;;i++)
    {
        if (!(sieve[i / 32] & 1 << (i % 32)) && !--n)
        {
            free(sieve);
            return 2 * i + 3;
        }
    }

    return -1;
}
