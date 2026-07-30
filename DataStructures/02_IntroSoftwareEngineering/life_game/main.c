#include "life.h"

int main(void)
{
    int row, col, row_size, col_size;
    Grid map;
    Grid newmap;
    init(map, &row_size, &col_size);
    write_map(map, row_size, col_size);

    printf("This is the initial configuration you have chosen.\n"
           "Press < Enter > to continue\n");
    while (getchar() != '\n');

    do
    {
        for (row = 1; row <= row_size; row++)
        {
            for (col = 1; col <= col_size; col++)
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
        copy_map(map, newmap, row_size, col_size);
        write_map(map, row_size, col_size);
        // usleep(500000);
        printf("Do you wish to continue?");

    } while (generate_next());
}
