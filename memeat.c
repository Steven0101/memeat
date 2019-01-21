#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BLOCK_SIZE 1024
#define BOUNDARY_THRESHOLD 4000

void usage(void)
{
    printf("Usage:\n");
    printf("\t memeat <-m> <value>, m means mega\n");
}

int main(int argc, char *argv[])
{
    int ch;

    unsigned long located_mem = 0;
    unsigned long k_Bytes = 0;
    int inNum = 0;

    /* optsting with "ab:c::", it means a doesn't have param and
     * b needs the param like -b 100 or -b100 and c is an option
     * one.
     */
    while ((ch = getopt(argc, argv, "m:")) != -1)
    {
        switch (ch)
        {
            case 'm':
                inNum = strtoull(optarg, NULL, 10);
                if (inNum >= BOUNDARY_THRESHOLD)
                {
                    printf("Not allowed to eat the memory exceed %d", BOUNDARY_THRESHOLD);
                    usage();
                    return 0;
                }
                k_Bytes = inNum * (BLOCK_SIZE) * (BLOCK_SIZE);
                printf("I'm going to eat %d M memory\n", inNum);
                break;

            case '?':
            default:
                usage();
                return 0;
        }

        while(1)
        {
            if (located_mem <= k_Bytes)
            {
                char *memptr = (char *) malloc(BLOCK_SIZE);
                if (memptr == NULL)
                {
                     printf("NULL pointer\n");
                     return 0;
                }
                else
                {
                    located_mem += BLOCK_SIZE;
                }
            }
            else
            {
                static int count = 0;
                if (count == 0)
                {
                    count++;
                    printf("%d M memory has been eaten by me :)\n", inNum);
                }
                sleep(1);
            }
        }
    }

    if (ch == -1)
    {
        usage();
    }

    return 0;
}
