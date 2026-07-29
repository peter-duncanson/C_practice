// Testing ground for memory leaks

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create_list(struct node **head, struct node **tail, int n);
void add_top(struct node **list, int n);
void add_bottom(struct node **list, int n);
void destroy(struct node **head);

int main(int argc, char **argv)
{
    struct node *head, *tail;
    head = NULL;
    tail = NULL;
    create_list(&head, &tail, 1);
    add_top(&head, 10);
    add_bottom(&tail, 20);
    destroy(&head);

    return 0;
}

void create_list(struct node **head, struct node **tail, int n)
{
    struct node *new;
    new = malloc(sizeof(struct node));
    new->data = n;
    new->next = NULL;
    *head = new;
    *tail = new;
}

void add_top(struct node **head, int n)
{
    struct node *new;
    new = malloc(sizeof(struct node));
    new->data = n;
    new->next = *head;
    *head = new;
}

void add_bottom(struct node **tail, int n)
{
    struct node *new;
    new = malloc(sizeof(struct node));
    new->data = n;
    (*tail)->next = new;
    new->next = NULL;
    *tail = new;
}

void destroy(struct node **head)
{
    struct node **p = head;

    while ((*head)->next != NULL)
    {
        p = head;
        *head = (*head)->next;
        free(p);
    }
}
