#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *vals;
	size_t count;
	size_t capacity;
} Darr;

int main(){
	printf("test\n");
	Darr xs = {0};
	for(int x = 0; x < 10; ++x){
		if(xs.count >= xs.capacity){
			if(xs.capacity == 0) xs.capacity = 1<<8;
			else xs.capacity *= 2;
			xs.vals = realloc(xs.vals, xs.capacity*sizeof(*xs.vals));
		}
		xs.vals[xs.count++] = x;
	}
	printf("finished\n");
	for(size_t i = 0; i < xs.count; ++i){
		printf("%d\n", xs.vals[i]);
	}
	return 0;
}
