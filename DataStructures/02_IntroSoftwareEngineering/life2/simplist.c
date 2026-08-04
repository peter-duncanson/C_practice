#include "common.h"
#include "simplist.h"

typedef struct list
{
    int count;
    ListEntry entry[MAXLIST]
} List;

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
