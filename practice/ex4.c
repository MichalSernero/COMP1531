#include <stdio.h>
#include <stdlib.h>

void multiplyByTwo(int *numPtr);

int main(int argc, char *argv[]) {

   int a = 5;
   multiplyByTwo(&a);
   printf("a is %d\n", a);

   return EXIT_SUCCESS;
}

void multiplyByTwo(int *numPtr) {
   *numPtr = *numPtr * 2;
}
