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
        // uses n_neighbors, changes map and newlive
        list_traverse(&maylive, vivify);

        // uses n_neighbors, changes map and newdie
        list_traverse(&maydie, kill);
        
        write_map(map);
        list_clear(&maylive);
        list_clear(&maydie);
        list_traverse(*newlive, add_neighbors);

        // changes n_neighbors, maylive, maydie
        list_traverse(&new_die, subtract_neighbors); 
        list_clear(&newlive);
        list_clear(&newdie);

        printf("Do you want to continue viewing new generations?");
    }
    return 0;
}
