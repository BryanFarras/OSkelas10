#include <stdio.h>

int main()
{
    int ms, ps, nop, np, rempages, i, j, x, y, pa, offset;
    int s[10], fno[10][20];

    printf("Enter the memory size: ");
    scanf("%d", &ms);

    printf("Enter the page size: ");
    scanf("%d", &ps);

    nop = ms / ps;
    printf("The number of pages available in memory: %d\n", nop);

    printf("Enter number of processes (max 10): ");
    scanf("%d", &np);

    rempages = nop;

    for (i = 0; i < np; i++)
    {
        printf("\nEnter number of pages required for process[%d]: ", i);
        scanf("%d", &s[i]);

        if (s[i] > rempages)
        {
            printf("Memory is Full\n");
            break;
        }

        rempages -= s[i];

        printf("Enter page table for process[%d] (%d values):\n", i, s[i]);
        for (j = 0; j < s[i]; j++)
        {
            printf("Page %d -> Frame: ", j);
            scanf("%d", &fno[i][j]);
        }
    }

    printf("\nEnter Logical Address to find Physical Address\n");
    printf("Enter process number, page number, and offset (separated by space): ");
    scanf("%d %d %d", &x, &y, &offset);

    if (x >= np || y >= s[x] || offset >= ps)
    {
        printf("Invalid process number, page number, or offset.\n");
    }
    else
    {
        pa = fno[x][y] * ps + offset;
        printf("The Physical Address is: %d\n", pa);
    }

    return 0;
}
