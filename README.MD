# Generic Vector in C

## <u>NOTE:</u>
* You should initialize the vector by using one of the `initAndReserve` or `Vector` function
* `vector *vec = Vector(int sizeof_data,int (*compare)(const void *,const void *))` is one way to initialize a vector. 
    * `int sizeof_data` is the size of the data type you want to store in the vector. It would be `sizeof(int)` for `int` while `sizeof(char *)` for `strings`
    * The 2nd parameter function excepts a compare function which returns `-1` if  when `a<b`,`0` when `a=b` and  `1` else. It would look like this for `int` type<br>
        #### Example
            `
            int compare(const void *a,const void *b)
            {
            return *(int *)a-*(int *)b;
            }
            `
* `vector *vec=initAndReserve(int sizeof_data,int (*cmp)(const void *,const void *),unsigned int capacity)` is another way to initialize a vector.
    * This way the vector will be preallocated storage for storing data and will save some time in resizing. This is recommended if you know how big you want your vector to be. All the memory will be initialized to `0` but size will still be `0` so you can do `push_back` operation as well as the `set` operation


## <u>Other Functions:</u>

* `size(vector *vec)` returns an unsigned int which is the current size of the array
* `capacity(vector *vec)` returns an unsigned int which is the current space which has been allocated to the vector
* `isempty(vector *vec)` returns `1` if the vector is empty else `0`
* `push_back(vector *vec,void *data)` is the way to push an element to the vector's end.
    #### Example of `push_back`:
        `
        vector *vec=Vector(sizeof(int),cmp);
        int a=10;
        push_back(vec,(void *)&a);
        `
* `pop_back(vector *vec)` is used to pop the last element of the vector
* `delete(vector *vec)` should be used to delete the heap allocated memory so that our program wont have memory leaks
* `get(vector *vec,int index)` is the equivalent of `arr[index]` in normal arrays. Although its a little bit trickier than that.
    #### Example of `get`:
        `
        //This is if your data was int
        printf("%d\n",*(int *)get(vec,2));


        //This is if your data was string(char *)

        printf("%s\n",*(char **)get(vec,2));
        `
* `set(vector *vec,void *data,int index)` should be used to set data at particular index if you have already allocated data and `index<capacity`. If your `size` was less than `index` then your new size after calling `set` will be `size=index+1`. The `void *data` should be passed in the same way as `push_back` function 

* `shrinkToFit(vector *vec)` will resize the vector  so that `capacity=size`
* `sort(vector *vec)` will sort the vector using built in `qsort` of C
* `removeAt(vector *vec,unsigned int pos)` removes the element at index `pos`. Might result in segmentation fault when used incorrectly like trying to delete element at index not within vector length.
* `insert(vector *vec,void *elementToAddAddress,unsigned int pos)` will insert the element at address `elementToAddAddress` at position `pos`. Does no error handling. Upto the user to get it right. Might result in segmentation faults if used incorrectly.
