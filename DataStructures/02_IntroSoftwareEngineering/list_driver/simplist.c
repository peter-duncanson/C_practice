#include "common.h"
#include "simplist.h"

typedef struct list
{
    int count;
    ListEntry entry[MAXLIST]
} List;

// pass the address of a list struct, this function will initialize it to be empty
// does not delete elements previously stored in entry array. Previously stored 
// elements are presumably overwritten upon subsequent calls to list_add().
void list_create(List *list)
{
    list->count = 0;
}

// clears 
void list_clear(List *list)
{
    if (list->count != 0)
    {
        for (int i = 0; i < list->count; i++)
        {
            list->entry[i] = 0;
        }
        list->count = 0;
    }
}

// returns boolean true or false based on whether the list is empty or not respectively
bool list_empty(const list *list)
{
    return (list->count == 0);
}

void list_add(ListEntry x, List *list)
{
    if (list_full(list))
        Warning("Attempt to insert into a full list.");
    else
        list->entry[list->count++] = x;
}

void traverse_list(List *list, void (*Visit)(ListEntry))
{
    int i;
    for (i = 0; i < list->count; i++)
        (*Visit)(list->entry[i]);
}


