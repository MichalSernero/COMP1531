#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

   int a = 5;
   char b = 'f';

   int *aPointer = &a;
   char *bPointer = &b;

   printf("a = %d and is at %p\n", a, &a);
   printf("b = %c and is at %p\n", b, &b);

   printf("aPointer = %p\n", aPointer);
   printf("bPointer = %p\n", bPointer);

   // Print out a
   printf("a is %d\n", *aPointer);

   // Add 1 to a
   *aPointer = *aPointer + 1; // a = a + 1

   // Print out a
   printf("a is %d\n", *aPointer);


   return EXIT_SUCCESS;
}
