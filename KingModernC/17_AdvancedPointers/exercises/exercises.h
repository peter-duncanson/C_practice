#ifndef EXERCISES_H
#define EXERCISES_H

// wrapper function for malloc from stdlib. When called, my_malloc will call malloc and ask
// for 'size' bytes on the heap. If malloc returns a null pointer, prints an error message
// and terminates the program. Otherwise, returns a void pointer to heap allocated memory.
void *my_malloc(size_t size);

// uses dynamic storage allocation to create a copy of a string. returns a null pointer if
// the memory allocation fails.
char *duplicate(const char *str);

// returns a int pointer to a dynamically allocated int array with n members, each of which
// is initialized to initial_value. Returns NULL if the array can't be allocated.
int *create_array(int n, int initial_value);

// 

#endif

