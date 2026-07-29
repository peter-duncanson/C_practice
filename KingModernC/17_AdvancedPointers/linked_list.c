// Example program for implimenting a linked list
// // first points to NULL
// struct Node *first = NULL;
// // create a new node
// struct Node *new_node;
// // get space on the heap for the new node
// new_node = malloc(sizeof(struct Node));
// // set the value of the new node
// new_node->value = 10;
// // the new node is now the end, points to NULL
// new_node->next = first;
// // first now points to the first and therefore only node
// first = new_node;

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;          // data stored in the node
    struct Node *next;  // pointer to the next node
};

struct Node *add_to_list(struct Node *list, int n);
struct Node *read_numbers(void);
struct Node *search_list(struct Node *list, int n);
struct Node *delete_from_list(struct Node *list, int n);

int main(int argc, char **argv)
{
    return 0;
}

struct Node *add_to_list(struct Node *list, int n)
{
    struct Node *new_node;
    new_node = malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        puts("ERROR: failed to allocate memory for node.");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = list;
    return new_node;
}

struct Node *read_numbers(void)
{
    struct Node *first = NULL;
    int n;

    printf("Enter a series of integers (0 to end): ");
    for (;;)
    {
        scanf("%d", &n);
        if (n == 0) return first;
        first = add_to_list(first, n);
    }
}

struct Node *search_list(struct Node *list, int n)
{
    for (; list != NULL; list = list->next)
        if (list->value == n) return list;

    return NULL;
}

struct Node *delete_from_list(struct Node *list, int n)
{
    struct Node *current, *previous;

    for (current = list, previous = NULL; 
         current != NULL && current->value != n;
         previous = current, current = current->next);

    if (current == NULL) return list;           // n not found
    if (previous == NULL) list = list->next;    // n is in the first node
    else previous->next = current->next;            // n is in some other node

    free(current);

    return list;
}
