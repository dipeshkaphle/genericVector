#include <stdio.h>
#include"genericVector.h"

int cmp(const void *a,const void *b)
{
  return *(int *)a - *(int *)b;
}
int main()
{
  vector *vec=Vector(sizeof (int),cmp);
  for(int i=5;i>=1;i--)
    push_back(vec,(void *)&i);
  sort(vec);
  for(int i=0;i<5;i++)
    printf("%d\n",*(int *)get(vec,i));
 
  removeAt(vec,2);
  for(int i=0;i<=3;i++)
    printf("%d\n",*(int *)get(vec,i));
  delete(vec);
  free(vec);
  return 0;
}
