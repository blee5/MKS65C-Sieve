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
    int i = 0;
    int j;

    int bound = (int)(sqrt(2 * len - 1) + 1) / 2;

    // NOTE: n & 31 == n % 32
    for (; i < bound; i++)
    {
        if (!(sieve[i >> 5] & 1 << (i & 31)))
        {
            num = 2 * i + 3;
            if (!--n)
            {
                free(sieve);
                return num;
            }
            else
            {
                // Start at index representing num ^ 2
                for (j = (num * num - 3) / 2; j < len; j += num)
                {
                    sieve[j >> 5] |= 1 << (j & 31);
                }
            }
        }
    }
    for (;;i++)
    {
        if (!(sieve[i >> 5] & 1 << (i & 31)) && !--n)
        {
            free(sieve);
            return 2 * i + 3;
        }
    }

    return -1;
}
