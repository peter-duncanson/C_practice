typedef struct list
{
    int count;
    ListEntry entry[MAXLIST];
} List;

void list_create(List *);
void list_clear(List *);
bool list_empty(const list *);
bool list_full(const list *);
int list_size(const list *);
void list_add(ListEntry, List *);
void list_traverse(List *, void(*)(ListEntry));
void list_copy(List *, const List *);
