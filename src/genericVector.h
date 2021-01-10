#ifndef GENERICVECTOR_H
#define GENERICVECTOR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct vector {
  void *arr;
  unsigned int word_size;
  unsigned int size;
  unsigned int capacity;
  int (*cmp)(const void *, const void *);
};
typedef struct vector vector;

// returns the number of elements in the vector
unsigned int size(vector *vec);

// returns the capacity of the vector to hold elements
unsigned int capacity(vector *vec);

// tells you if the vector is empty
int isempty(vector *vec);

// pushes the data to the end of the array. Resizes if needed.
void push_back(vector *vec, void *data);

// pops the element at the end of the array
// The number will be there as is. It wont be removed but will be overwritten
// next time you do push_back
void pop_back(vector *vec);

// Vector initializer
vector *make_vector(unsigned int word_size,
                    int (*compare)(const void *, const void *));

// Reserves the needed amount of memory and returns a heap allocated vector
vector *initAndReserve(unsigned int word_size,
                       int (*compare)(const void *, const void *),
                       unsigned int capacity);

// deletes the heap allocated memory
void delete_vec(vector *vec);

void *get(vector *vec, unsigned int index);

void *set(vector *vec, void *data, unsigned int index);

// shrinks the vector to the size of the vector. No unwanted storage used
void shrinkToFit(vector *vec);

// Insert an element at arbitrary position
void insert(vector *vec, void *elemAddr, unsigned int position);

// Delete an element from an arbitrary position
void removeAt(vector *vec, unsigned int position);

void printAll(vector *vec, void (*printFunc)(const void *),
              char printNewLineAtTheEnd);

// uses the built in qsort to sort the generic vector
void sort(vector *vec);

#endif // GENERICVECTOR_H
