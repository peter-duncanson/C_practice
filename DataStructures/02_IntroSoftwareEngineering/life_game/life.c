#include "life.h"

void copy_map(Grid map, Grid newmap, int row_size, int col_size)
{
    int row, col;

    for (row = 0; row <= row_size + 1; row++)
    {
        for (col = 0; col <= col_size + 1; col++)
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

void init(Grid map, int *row_size, int *col_size, FILE *fptr)
{
    int row, col;
    char c;
    bool flag;

    printf("Welcome to the Life Game Simulation!\n");
    while (true)
    {
        printf("Enter grid size: ");
        scanf("%d %d", row_size, col_size);
        if (*row_size > MAXROW || *col_size > MAXCOL)
        {
            printf("Grid size is too large, max size is %dx%d. Please enter a valid size.\n",
                    MAXROW, MAXCOL);
        }
        else break;
    }

    for (row = 0; row <= *row_size + 1; row++)
    {
        for (col = 0; col <= *col_size + 1; col++)
        {
            map[row][col] = DEAD; // set all cells to dead, including hedge
        }
    }

    if (fptr == NULL)
    {
        printf("Enter each row of the grid using space for dead cells and x for alive cells.\n");
        for (row = 1; row <= *row_size; row++)
        {
            col = 1;
            while (col <= *col_size)
            {
                c = getchar();
                if (c == 'x') map[row][col] = ALIVE;
                else if (c != ' ') continue;
                col++;
            }
        }
        while (getchar() != '\n');
    }
    else
    {
        
    }
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

void write_map(Grid map, int row_size, int col_size)
{
    int row, col;
    puts("\n");
    
    for (row = 1; row <= row_size; row++)
    {
        for (col = 1; col <= col_size; col++)
        {
            if (map[row][col] == ALIVE) putchar('*');
            else putchar('-');
            
        }
        puts("");
    }
}
