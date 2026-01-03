# Dynamic arrays

We can either initialize an array with a known number of items.

if we when we are programming do not before hand know the size of the array, we should be able to dynamically allocate memory for it to accommodate for the items that we need

```c
#include <stdio.h>

typedef struct {
    int *items;
    size_t count;
    size_t capacity
} DynamicArray;

int main(){
    DynamicArray xs = {0};
    for(int x = 0; x < 10; ++x){
        if(xs.count >= xs.capacity){
            if(xs.capacity == 0) xs.capacity = 1<<8; // 256;
            else xs.capacity *= 2;
            xs.items = realloc(xs.items, xs.capacity*sizeof(*xs.items));
        }
        xs.items[xs.count++] = x;
    }
    return 0;
}
```
