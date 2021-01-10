#include "genericVector.h"

// returns the number of elements in the vector
unsigned int size(vector *vec) { return vec->size; }

// returns the capacity of the vector to hold elements
unsigned int capacity(vector *vec) { return vec->capacity; }

// tells you if the vector is empty
int isempty(vector *vec) { return (size(vec) == 0) ? 1 : 0; }

// pushes the data to the end of the array. Resizes if needed.
void push_back(vector *vec, void *data) {
  if (size(vec) < capacity(vec)) {
    char *ptr = (char *)vec->arr;
    ptr += (size(vec) * (vec->word_size));
    memcpy((void *)ptr, (const void *)data, vec->word_size);
    vec->size++;
  } else {
    if (size(vec) == 0) {
      vec->arr = calloc(2, vec->word_size);
      vec->capacity = 2;
    } else {
      void *tmp = vec->arr;
      vec->arr = calloc(2 * capacity(vec), vec->word_size);
      vec->capacity = 2 * capacity(vec);
      memcpy(vec->arr, tmp, size(vec) * vec->word_size);
      free(tmp);
    }
    push_back(vec, data);
  }
}

// pops the element at the end of the array
// The number will be there as is. It wont be removed but will be overwritten
// next time you do push_back
void pop_back(vector *vec) {
  if (size(vec) != 0) {
    vec->size -= 1;
  }
}

// Vector initializer
vector *make_vector(unsigned int word_size,
                    int (*compare)(const void *, const void *)) {
  vector *vec = (vector *)calloc(1, sizeof(vector));
  vec->cmp = compare;
  vec->word_size = word_size;
  vec->size = 0;
  vec->capacity = 0;

  return vec;
}

// Reserves the needed amount of memory and returns a heap allocated vector
vector *initAndReserve(unsigned int word_size,
                       int (*compare)(const void *, const void *),
                       unsigned int capacity) {
  vector *vec = make_vector(word_size, compare);
  vec->arr = calloc(capacity, word_size);
  vec->capacity = capacity;
  return vec;
}

// deletes the heap allocated memory
void delete_vec(vector *vec) {
  if (vec->arr != NULL) {
    free(vec->arr);
    vec->arr = NULL;
  }
}

void *get(vector *vec, unsigned int index) {
  return (void *)((char *)vec->arr + (index * vec->word_size));
}

void *set(vector *vec, void *data, unsigned int index) {
  if (index < capacity(vec)) {
    void *ptr = (void *)((char *)vec->arr + (index * (vec->word_size)));
    memcpy(ptr, (const void *)data, vec->word_size);
    if (index >= vec->size)
      vec->size = (index + 1);

    return ptr;
  }
  return NULL;
}

// shrinks the vector to the size of the vector. No unwanted storage used
void shrinkToFit(vector *vec) {
  if (size(vec) != 0) {
    void *tmp = vec->arr;
    vec->arr = calloc(vec->size, vec->word_size);
    memcpy(vec->arr, tmp, size(vec) * vec->word_size);
    free(tmp);
    vec->capacity = vec->size;
  }
}

// Insert an element at arbitrary position
void insert(vector *vec, void *elemAddr, unsigned int position) {
  unsigned int len = size(vec);
  if (len == position) {
    push_back(vec, elemAddr);
    return;
  } else {
    push_back(vec, (char *)vec->arr + (len - 1) * vec->word_size);
    memmove((void *)((char *)vec->arr + (position + 1) * vec->word_size),
            (void *)((char *)vec->arr + position * vec->word_size),
            (len - position - 1) * vec->word_size);
    set(vec, elemAddr, position);
    return;
  }
}

// Delete an element from an arbitrary position
void removeAt(vector *vec, unsigned int position) {

  int len = size(vec);
  if (position == len - 1) {
    pop_back(vec);
  } else {
    for (unsigned int i = position + 1; i < size(vec); i++) {
      set(vec, get(vec, i), i - 1);
    }
    (vec->size)--;
  }
}

void printAll(vector *vec, void (*printFunc)(const void *),
              char printNewLineAtTheEnd) {
  for (unsigned int i = 0; i < size(vec); i++) {
    printFunc(get(vec, i));
  }
  if (printNewLineAtTheEnd) {
    printf("\n");
  }
}

// uses the built in qsort to sort the generic vector
void sort(vector *vec) { qsort(vec->arr, size(vec), vec->word_size, vec->cmp); }
