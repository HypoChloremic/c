# Input / Output

## Stream
* Stream:
    * source of input
    * destination of output
* Small programs 
    * receive their inputs from one stream (the keyboard) 
    * and outputs streams usually associated with the screen
* Larger programs need bigger streams
    * files stored on DVDs, flash memory, hard drive
    * network ports, printers and the like

We will be focusing on files and sometimes when files are referred it is supposed to refer to "stream"

Note that many of the functions in stdio.h can work on all types of streams, not only the one representing files.

## File pointers

* Accessing a stream in C
    * Done with "file pointers"
* Certain streams
    * can have "standard names"
    * or we declare them ourselves `FILE *fp, *fp2;`
* We can declare several FILE pointers (FILE*)
    * however some operating systems can limit the number we can have open

### Standard streams

stdio.h defines three standard streams.
* we do not need to open or close them
    * `stdin`: mapped to keyboard; stream input
    * `stdout`: mapped to screen; stream output
    * `stderr`: mapped to screen; stream error

The following functions receive input from the stdin stream:
* getchar, putchar, puts, gets
* they send output to stdout

Usually stdin and stderr stream to screen and stdin from keyboard, but many **operating systems can use redirection to change their meaning**

#### input redirection
We can force a program to accept input from a file instead of the keyboard
* by putting the name of the file in the command line
* `demo <init.dat`

the beauty of this is that the program *does not know that it is receiving stdin from a file*, it might as well believe it is from the keyboard.

#### output redirection

is usually done by putting the filename that we wish to output stream to go to in the command line:
* `demo >out.dat`

all output will go to the out.dat file and not the screen

#### combined redirection
`demo <in.dat >out.dat

## "Text files" and "Binary files"
* text file: bytes in a text file are human readable:
    * they map to ASCII characters for instance..?
    * e.g. the source file of a C program stored in a text file.
* binary file: bytes can map to anything, could be integers, floats, chars etc
    * e.g. the output binary of a C program is stored in binary

### Text file
Two characteristics binary files do not possess:
1. **Divided into lines**: ends with 1-2 special characters (**depends on the OS**)
    * Windows carriage-return character + followed by line feed char: ('\x0d') ('\x0a')  
    * Unix and OSX: line feed character only
2. **May contain "end-of-file" marker**
    * Some OS have end-of-file markers
    * Windows: ctrl+z, i.e. '\x1a'
        * any chars after the \x1a char are to be ignored in Windows
        * doesnt need to be present
    * Most other do not have it, e.g. UNIX

### Binary files
* Not divided into lines
* all bytes treated equally 
    * (unlike text files with carriage-return and line-feed chars or end-of-file chars

### To see the difference
When storing data we need to consider how we are to store it, as text or binary
* We want to store 32767 in file
* In text form we can use ASCII binary mappings:
    * '3': 00110011
    * '2': 00110010
    * '7': 00110111
    * '6': 00110110
    * '7': 00110111
* Another option is to store it as binary:
    * would only take two bytes:
    * 01111111 11111111
    * the bytes will be reversed if little-endian order

Storing therefore as binary takes less space
If we do not know to read as text or binary
* more safe to assume to read as binary


## File operations

Redirection is simple but can be too simple for many applications
* We do not even know the file names being used, in the actual program

When redirection insufficient *we use stdio.h file operations*

### Opening a file

`FILE *fopen(const char* restrict filename, const char* restrict mode);`

note use of `restrict` implies that they are pointers to strings that do not share memory locations. It is a C99 keyword

fopen returns a `FILE *`
```
FILE *fp;
fp = fopen(FILENAME, "r");
```
when it cant open it returns a **"null pointer"**.
* perhaps we do not have the permissions to open
* wrong location
* doesnt exist

***WARNING***: Never assume that a file can be opened, always test for the null pointer.

#### Opening a text file

we need to decide on the modes: 
* r, 
* w (file need not exist),
* a (file need not exist)
* r+: open for reading and writing, starts at beginning
* w+: open for reading and writing, truncate if file exists
* a+: open for reading and writing, append if file exists


**Appending**
Will write to the end of the file

for binary you just append a `b` to the mode

**Switching between reading and writing**
* reading -> writing we need to call file positioning function if we wish to switch
* unless the reading operation met end-of-file
* writing->reading: call fflush() or some other functions


### Closing a file
call `fclose(FILE *stream);`
* returns zero if closed or code `EOF` defined in stdio.h 

must be a file pointer from 
* `fopen` 
* or `freopen`

### Example opening and closing
```c
#include <stdio.h>

int main(){
    FILE *fp;
    fp = fopen("dat.dat", "rb");
    if(fp==NULL){
        exit(EXIT_FAILURE);
    }
    flcose(fp);
    return 0;
}
```

other iteration
```c
    ...
    if((file *fp = fopen("dat.dat", "r")) == null){
    ...
}
```
or
```c
    ...
    FILE *fp = fopen("dat.dat", "r");
    if(fp==NULL){
    ...
}
```


### Attaching File to an open stream
`freopen` attaches a file to an already open stream.

Most common use cases:
* Attaching file to the standard streams (stdin, stdout, stderr)

To cause a program being writing to file foo:
```c
if ((freopen("foo", "w", stdout)) == NULL){
    // error if foo cannot be opened
}
```


## Temporary files

A C program can create temporary files to be used.

`FILE *tmpfile(void);`
`char *tmpnam(char *s);`

* tmpfile() opens a temporary file in wb+ mode. if it fails to create, returns **null pointer**
* tmpnam() generates a random tmp file name, that we can open with fopen.
    * stores the file name in a static variable
    * otherwise stores the name in a char array provided by the programmer
        * `char filename[L_tmpnam]; tmpnam(filename);`
        * in this example tmpnam returns the pointer to the first char in the char array
    * `L_tmpnam` is a macro stdio.h deining the length of char array to hold tmpnam

## ! File buffering
### Is a slow operation

* transferring data to/fro disk is slow
* unfeasible for program to read and write byte to/fro disk directly
* acceptable performance comes from **buffering**
    * data written to a **stream** is actually stored in a **buffer area in memory**
* When buffer full or stream is closed:
    * it is flushed: written to actual output device

### Input streams can also be buffered
* input is read from this buffer
* instead of reading directly from the input device itself
* **enormous performance boost**: to read from a buffer (area of memory) than otherwise
    * of course moving data from disk to the buffer is slow
    * but can be done in larger **"block move"** is faster than **tiny byte moves**

The functions in stdio.h perform buffering behind the scenes when it sees fit.

On rare occasions do we need to be more active in the operation
* fflush
* setbuf
* setvbuf

When a program writes to output file,
1. first written to buffer
2. when buffer full or file closed it flushes, and writes to the output device/destination/stream

#### fflush
* `fflush(FILE *fp)` force flushes the buffer of `fp` directly to the output device
* `fflush(NULL)` flushes all buffers

fflush returns zero if success or EOF if error

#### setvbuf
```c
int setvbuf(FILE * restrict stream,
            char * restrict buf,
            int mode, size_t size);
```
What it does
* change way stream is buffered
* control size
* control location of buffer
* **must** be called before a stream is opened

modes
* _IOFBF (full buffering): 
    * full buffering
    * data is read from stream when buffer full
    * default for all streams
* _IOLBF (line buffering):
    * one line at a time
    * data is read from the stream or written to the stream **one line at a time**
* _IONBF (no buffering):
    * no buffering
    * data is read from the stream or written to stream directly

the buf pointer is the pointer (address) to the buffer if not null pointer.
* buffer may
    * static storage duration
    * automatic storage duration
    * allocated dynamically

the buf size
* number of bytes of the buffer
* larger buffer = better perf, more memory usage
* smaller buffer = saves space

**Example**
```c
char buffer[N];
// ...
setvbuf(stream, buffer, _IOFBF, N);
```

## Formated IO
### fprintf and printf
```c
fprintf(FILE * restrict stream, const char * restrict format, ...); -> to file
printf(const char * restrict format, ...)-> always to stdout
```

* both write a variable to output stream.
* using string format, to control the appearance of the result
* both return number of characters written or -1 (negative return) if error
* fprintf to write to specified stream
    * most commonly to write to stderr

Use **format strings** to 

### scanf and fscanf
```c
int fscan(FILE * restrict stream, const char * restrict format, ...);
int scanf(const char * restrict format, ...);
```
* **Read data items** from input stream
* using format to indicate layout of the input
* after the "format string", any number of pointers
* input items converted
    * according to conversion specified in format string
    * stored in the objects (the pointers?)

`scanf` always reads from **stdin**

```c
scanf("%d%d", &i, &j); // reads from stdin
fscanf(fp, "%d%d", &i, &j); // reads from fp
```

the scan funcs return prematurely 
* if input fails (no more characters to read) 
* or match fails
* return the n data items read and assigned; 
* return EOF if input failure before any data items were read

Loops testing for scan EOF is common in C programs
```c
while(scanf("%d", &i) == 1){}
```
