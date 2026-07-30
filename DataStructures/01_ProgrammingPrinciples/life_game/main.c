#include "life.h"

int main(void)
{
    int row, col;
    Grid map;
    Grid newmap;
    init(map);
    write_map(map);

    printf("This is the initial configuration you have chosen.\n"
           "Press < Enter > to continue\n");
    while (getchar() != '\n');

    do
    {
        for (row = 1; row <= MAXROW; row++)
        {
            for (col = 1; col <= MAXCOL; col++)
            {
                switch (neighbor_count(map, row, col))
                {
                    case 0:
                    case 1:
                        newmap[row][col] = DEAD;
                        break;
                    case 2:
                        newmap[row][col] = map[row][col];
                        break;
                    case 3:
                        newmap[row][col] = ALIVE;
                        break;
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                        newmap[row][col] = DEAD;
                        break;
                }
            }
        }
        copy_map(map, newmap);
        write_map(map);
        // usleep(500000);
        printf("Do you wish to continue?");

    } while (true);
}
