#include "common.h"
#include <ctype.h>
#include "simplist.h"

void print(ListEntry);
void introduction(void);
void help(void);
char get_command(void);
void do_command(char, List *);

int main(void)
{
    List list;

    introduction();
    
    list_create(&list);

    // infinite loop
    // do_command function will call exit() in order to end the program
    while (true)
        do_command(get_command(), &list);

    // this statement should never be executed
    return 1;
}

void help(void)
{
    printf("\nThis program allows one command to be entered on each line.\n"
            "For example, if the command I is entered at the command line\n"
            "then the program will ask for a string of characters and\n"
            "insert them one at a time into the simple list.\n");

    printf("\nValid commands are:\n"
            "\tI - Insert values into the simple list\n"
            "\tP - Print the simple list\n"
            "\tT - Traverse the simple list (same as print)\n"
            "\tS - The current size of the simple list\n"
            "\tD - Delete the simple list\n"
            "\tC - Clear the simple list (same as delete)\n"
            "\tH - This help screen\n"
            "\tQ - Quit\n"
            "Press <Enter> to continue.");
    while (getchar() != '\n');
}

char get_command(void)
{
    char command;

    printf("\n\t[I]nsert entry\t[P]rint list\t[S]ize of list\n"
            "\t[D]elete list\t[C]lear list\t[H]elp\n"
            "\t[T]raverse the list\t\t[Q]uit\n"
            "Select command and press <Enter>:");

    while (true)
    {
        while ((command = getchar()) == '\n');

        command = tolower(command);

        switch (command)
        {
            case 'i':
            case 'p':
            case 't':
            case 's':
            case 'd':
            case 'c':
            case 'h':
            case 'q':
                while (getchar() != '\n');
                return command;
            default:
                printf("Please enter a valid command.\n");
        }
    }
}

void do_command(char command, List *list)
{
    ListEntry x;

    switch (command)
    {
        case 'i':
            if (list_full(list))
                Warning("Sorry, list is full!");
            else
            {
                printf("Enter new key(s) to insert:");
                while ((x = getchar()) != '\n' && !list_full(list))
                    list_add(x, list);
                if (x != '\n')
                {
                    Warning("The list is full, cannot insert any more entries.");
                    while ((x = getchar()) != '\n');
                }
            }
            break;
        case 'd': // same as c, deleting the entries
        case 'c':
            list_clear(list);
            printf("List cleared\n");
            break;
        case 'p':
        case 't':
            if (list_empty(list))
                printf("List is empty.\n");
            else
            {
                printf("\nTraversing the list; it contains:\n");
                list_traverse(list, print); // function as a parameter
            }
            break;
        case 's':
            printf("The size of the list is %d\n", list_size(list));
            break;
        case 'h':
            help();
            break;
        case 'q':
            printf("Simple list demonstration finished.\n");
            exit(0);
    }
}

void print(ListEntry x)
{
    printf(" %c", x);
}
