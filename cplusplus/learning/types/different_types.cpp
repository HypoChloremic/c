#include <iostream>

using namespace std; 

int main(int argc, char const *argv[]){
  /*Note that the `char const *argv[]` must be read from RIGHT to LEFT

  when considering types in general, it is important to read them from RIGHT to LEFT

  char *const argv[]
  
                  ^^ Array of
        ^^^^^        const
       ^             pointer to
  ^^^^               char
  RESULTANTLY: An array of "const pointer" to char
*/
}
