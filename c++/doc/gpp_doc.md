 

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
### One-dimensional
To initialize an array, the simplest way is to: 

`int arr[2];` will initialize the variable `arr` with two positions.

These can be assigned: `arr[0] = 10`, `arr[1] = 20`. 

To access them, one can use the corresponding indices:

```c++
std::cout << arr[0];
> 10
```


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
