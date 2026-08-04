#include "simplist.h"

#define MAXROW 20 // max size of grid
#define MAXCOL 60 // change based on size of screen output
#define MAXLIST 300 // maximum size allowed for the four lists

typedef enum state { DEAD, ALIVE } State;
typedef State Grid[MAXROW + 2][MAXCOL + 2];
typedef int Gridcount[MAXROW + 2][MAXCOL + 2]; // number of neighbors
typedef struct cell 
{
    int row, col; // grid coordinates
} Cell;

typedef Cell ListEntry;

bool user_says_yes(void);
void write_map(Grid);
void find_size(int *, int *);
void read_map(List *, Grid);
void vivify(ListEntry);
void kill(ListEntry);
void add_neighbors(ListEntry);
void subtract_neighbors(ListEntry);
void initialize(Grid, Gridcount, List *, List *, List *, List *);
