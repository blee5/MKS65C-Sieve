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

    char *sieve = calloc(sizeof(char), len);
    char *p = sieve + 2;
    char *q;

    int i = 2; n--;
    int j;
    int temp;
    for (; i < len; i++, p++)
    {
        num = (i << 1) - 1; // Index i represents (2i - 1), so we only store odd numbers
        // printf("[%d]: %d holds %x\n", i, num, *p);
        if (*p == 0)
        {
            if (--n <= 0)
            {
                return num;
            }
            j = i;
            // Increment j by num, then j represents the number
            // 2 (j + num - 1)
            // => 2j + 2num - 2
            // => 2(j-1) + 2num, which is the next odd multiple of num
            for (q = p; j < len; j += num, q += temp)
            {
                if (*q == 0)
                {
                    // printf("[%d]: %d set to 0\n", j, (j << 1) - 1); 
                    *q = 1;
                }
            }    
        }
    }
    return -i;
}
