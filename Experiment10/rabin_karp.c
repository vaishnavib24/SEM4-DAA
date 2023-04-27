#include <stdio.h>
#include <string.h>

#define d 256
#define q 101

int rabinSearch(char *t, char *p)
{
    int tlength = strlen(t);
    int plength = strlen(p);
    int i, j;
    int phash = 0;
    int thash = 0;
    int h = 1;

    for (i = 0; i < plength - 1; i++)
    {
        h = (h * d) % q;
    }

    for (i = 0; i < plength; i++)
    {
        phash = (d * phash + p[i]) % q;
        thash = (d * thash + t[i]) % q;
    }

    for (i = 0; i <= tlength - plength; i++)
    {

        if (thash == phash)
        {

            for (j = 0; j < plength; j++)
            {
                if (t[i + j] != p[j])
                {
                    break;
                }
            }

            if (j == plength)
            {
                return i;
            }
        }

        if (i < tlength - plength)
        {
            thash = (d * (thash - t[i] * h) + t[i + plength]) % q;

            if (thash < 0)
            {
                thash += q;
            }
        }
    }

    return -1;
}

int main()
{
    char t[1000], p[1000];

    printf("Enter the text: ");
    fgets(t, 1000, stdin);
    printf("Enter the pattern to search for: ");
    fgets(p, 1000, stdin);

    t[strcspn(t, "\n")] = 0;
    p[strcspn(p, "\n")] = 0;

    int result = rabinSearch(t, p);
    if (result == -1)
    {
        printf("pattern not found in text.\n");
    }
    else
    {
        printf("Pattern found in text starting at index %d.\n", result);
    }

    return 0;
}
