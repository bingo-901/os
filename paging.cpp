#include <stdio.h>

int main() {
    int ms, ps, nop, np, rempages, i, j, x, y, pa, offset;
    int s[10], fno[10][20];

    printf("\nEnter the memory size (in bytes): ");
    scanf("%d", &ms);
    printf("\nEnter the page size (in bytes): ");
    scanf("%d", &ps);

    nop = ms / ps;
    printf("\nThe number of pages available in memory are: %d\n", nop);

    printf("\nEnter the number of processes: ");
    scanf("%d", &np);

    rempages = nop;

    for (i = 1; i <= np; i++) {
        printf("\nEnter the number of pages required for process p[%d]: ", i);
        scanf("%d", &s[i]);

        if (s[i] > rempages) {
            printf("\nMemory is full.\n");
            break;
        }

        rempages -= s[i];

        printf("\nEnter the page table for process p[%d]:\n", i);
        for (j = 0; j < s[i]; j++) {
            printf("Enter page frame for page %d: ", j + 1);
            scanf("%d", &fno[i][j]);
        }
    }

    printf("\nEnter Logical Address to find Physical Address:\n");
    printf("Enter process number, page number, and offset: ");
    scanf("%d %d %d", &x, &y, &offset);

    if (x > np || y >= s[x] || offset >= ps) {
        printf("\nInvalid Process, Page Number, or Offset\n");
    } else {
        pa = fno[x][y] * ps + offset;
        printf("\nThe Physical Address is: %d\n", pa);
    }

    return 0;
}
