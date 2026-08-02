#inclide "common.h"
#include "life2.h"

Grid map;               // 2D array to hold cells

Gridcount n_neighbors;  // 2D array holding square counts

List newlive,           // cells that have just been vivified
     newdie,            // cells that have just died
     maylive,           // candidates to vivify in the next generation
     maydie;            // candidates to die in the next generation

int rows, cols;         // global to store user defined grid size

int main(void)
{
    initialize(map, n_neighbors, &newlive, &newdie, &maylive, &maydie);

    write_map(map);

    printf("Something may go here");

    while (user_says_yes())
    {
        list_traverse(&maylive, vivify);


        list_clear(&maylive);
        list_clear(&maydie);
        list_traverse(*newlive, add_neighbors);

    }

}
