 

# Mathematical operations
## Summing

# Input output operations
## Input  for kattis

Seemingly, there is one general way of processing input (e.g. for kattis): 

```c++
long long a, b;
while (cin >> a >> b) {
   // solve test case and output answer
}
```

## Input and Output for kattis
```c++
int main(int argc, char const *argv[])
{
        /* long long is used to handle 64 bit integers */

        long long R1, S, OUT;
        while (cin >> R1 >> S) {
                // solve test case and output answer
                OUT = 2*S - R1;
                std::cout << OUT << endl;
        }
        return 0;
}
```

So seemingly, to output data for kattis, you are supposed to: ``std::cout << out << endl;`


# Arrays and lists
## Initialization
Default initialization when doing `int arr[10];` is at each index, the value `0` is assigned. 
**NOTE**: however, later in the documentation, it seems to be stated that it could be whatever that is initialized at components that were left unassigned by the programmer, i.e. they could be anything.

### Initialize without dims
It is also possible to create an array without specifying the dimensions of the array:

`int arr[] = { 10, 2, 30, 1 };`

Implicitly, an array `arr` with size `4` is created. 

### One-dimensional
To initialize an array, the simplest way is to: 

`int arr[2];` will initialize the variable `arr` with two positions.

These can be assigned: `arr[0] = 10`, `arr[1] = 20`. 

To access them, one can use the corresponding indices:

```c++
arr[0] = 10`; 
arr[1] = 20
std::cout << arr[0];
> 10
```

### Multi-dimensional
Multi dimensional arrays are also possible. Assume we want an array (matrix), which is 10 rows by 2 columns (in effect two vectors of 10 components):

```c++
double matrix[10][2];

// To access the data and save and extract:
matrix[5][0] = 10
std::cout << matrix[5][0];
```

## Incomplete knowledge
It is possible that the arrays that when the array is initialized, not all knowledge about it is there:
Thus we can do the following 

```c++
int incomp_at_init[20] = { 0, 10 };
```

## Memory management
When initializing an array of different types, then the compiler will assign a specific chunk of memory to the array. For each component, the array will be parking [type] sized chunk (e.g. for int being 4 bytes = 4 x 8 = 32 bits). 

## Errors
### Array Bounds

If an array with pre-specified dimensions is accessed outside of those dimensions, it is not always that the compiler will discover that you are out of bounds with regard to the array. For instance:

```c++
int arr [2][2] = {{1,2},{3,4}};
std::cout << arr[1][2]; // second row, third column, which doesnt exist. . . 
>>> 358854752

```

In this case, when performing the above, we note the above value being returned. 

# Typecasting

## Converting to new type, dynamically:

```c++
int a,b,c;
a = 10;
b = 20;
c = 30;

float d = (float)a + (float)b + (float)c
```

# Use C++17
## The command line operation

To be able to c++17, the following needs to be used in the command line: 

`g++ -std=c++1z [file].cpp -o [out file].out`
