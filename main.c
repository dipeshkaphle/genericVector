#include "genericVector.h"
#include <stdio.h>

void printInt(const void *val) { printf("%d ", *(int *)val); }

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int main() {
  vector *vec = Vector(sizeof(int), cmp);
  for (int i = 5; i >= 1; i--)
    push_back(vec, (void *)&i);
  sort(vec);
  for (int i = 0; i < 5; i++)
    printf("%d\n", *(int *)get(vec, i));

  printf("\n\n");

  removeAt(vec, 2);
  for (int i = 0; i < size(vec); i++)
    printf("%d\n", *(int *)get(vec, i));
  int storeThis = 3;
  insert(vec, &storeThis, 2);
  insert(vec, &storeThis, 2);
  insert(vec, &storeThis, 2);
  insert(vec, &storeThis, 2);
  printAll(vec, printInt, 1);
  delete (vec);
  free(vec);
  return 0;
}
