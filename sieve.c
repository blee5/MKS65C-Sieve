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

    /*
     * sieve[n] represents the number (2n - 1),
     * therefore only storing odd numbers.
     * (NOTE: Index 0 and 1 are unused because they correspond to -1 and 1)
     */
    char *sieve = calloc(sizeof(char), len);
    char *p = sieve + 2;
    char *q;

    int i = 2; n--;
    int j;
    int num;

    int bound = (sqrt(2 * len - 1) + 1)/ 2;
    for (; i < bound; i++, p++)
    {
        if (*p == 0)
        {
            num = 2 * i - 1;
            if (--n <= 0)
            {
                free(sieve);
                return num;
            }
            j = i;
            // Increment j by num => 2(j + num - 1)
            // => 2j + 2num - 2 => 2(j - 1) + 2num, which is the next odd multiple of num
            for (q = p; j < len; j += num, q += num)
            {
                if (*q == 0)
                {
                    *q = 1;
                }
            }    
        }
    }
    for (; i < len; i++, p++)
    {
        if (*p == 0 && --n <= 0)
        {
            free(sieve);
            return 2 * i - 1;
        }
    }
    return -1;
}
