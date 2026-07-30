#include "life.h"

void copy_map(Grid map, Grid newmap)
{
    int row, col;

    for (row = 0; row <= MAXROW + 1; row++)
    {
        for (col = 0; col <= MAXCOL + 1; col++)
        {
            map[row][col] = newmap[row][col];
        }
    }
}

bool generate_next(void)
{
    int c;
    printf("(y/n)? ");

    do
    {
        while ((c = getchar()) == '\n');

        if (c == 'y' || c == 'Y') return true;
        else if (c == 'n' || c == 'N') return false;
        printf("Please type y or n.\n");
    } while (1);
}

void init(Grid map)
{
    int row, col;
    printf("Simulation of Life Game! Grid size: %d x %d\n", MAXROW, MAXCOL);

    for (row = 0; row <= MAXROW + 1; row++)
    {
        for (col = 0; col <= MAXCOL + 1; col++)
        {
            map[row][col] = DEAD; // set all cells to dead, including hedge
        }
    }
    
    printf("On each line give coordinates for living cells. 0 0 to end.\n");
    scanf("%d %d", &row, &col);
    while (row != 0 || col != 0)
    {
        if (row >= 1 && row <= MAXROW && col >= 1 && col <= MAXCOL)
        {
            map[row][col] = ALIVE;
        }
        else printf("Values are not in range.\n");

        scanf("%d %d", &row, &col);
    }
    while (getchar() != '\n');
}

int neighbor_count(Grid map, int row, int col)
{
    int i, j, count = 0;

    for (i = row - 1; i <= row + 1; i++)
    {
        for (j = col - 1; j <= col + 1; j++)
        {
            if (map[i][j] == ALIVE) count++;
        }
    }

    return (map[row][col] == ALIVE) ? count - 1 : count;
}

void write_map(Grid map)
{
    int row, col;
    puts("\n");
    
    for (row = 1; row <= MAXROW; row++)
    {
        for (col = 1; col <= MAXCOL; col++)
        {
            if (map[row][col] == ALIVE) putchar('*');
            else putchar('-');
            
        }
        puts("");
    }
}
