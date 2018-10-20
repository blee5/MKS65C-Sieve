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

    /*
     * sieve[n] represents the number (2n - 1),
     * therefore only storing odd numbers.
     * (NOTE: Index 0 and 1 are unused because they correspond to -1 and 1)
     */
    char *sieve = calloc(sizeof(char), len);
    char *p = sieve + 2;
    char *q;

    int num;

    char *bound = sieve + (int)(sqrt(2 * len - 1) + 1)/ 2;
    char *end = sieve + len;
    for (; p < bound; p++)
    {
        if (*p == 0)
        {
            num = 2 * (p - sieve) - 1;
            if (--n <= 0)
            {
                free(sieve);
                return num;
            }
            // Increment j by num => 2(j + num - 1)
            // => 2j + 2num - 2 => 2(j - 1) + 2num, which is the next odd multiple of num
            //
            // Also start at the prime (and get the proper index) because something something square root
            for (q = sieve + (num * num + 1) / 2; q < end ;q += num)
            {
                if (*q == 0)
                {
                    *q = 1;
                }
            }    
        }
    }
    for (; p < end; p++)
    {
        n += *p - 1;
        if (!n)
        {
            free(sieve);
            return 2 * (p - sieve) - 1;
        }
    }
    return -1;
}
