#include <stdio.h>
#include <stdlib.h>


// Recursive function
int fibRec( int num ) {

   if (num <= 1) {

      return 0;

   } else if (num == 2) {

      return 1;

   }

   return fibRec(num - 1) + fibRec(num - 2);
}


// Iterative function
int fibIter( int num ) {

   int a = 0;

   int b = 1;

   int c;

   if (num == 1) {
      return 0;
   }

   for (int i = 3; i <= num; i++) {

      c = a + b;

      a = b;

      b = c;

   }
   return b;
}



int main( int argc , char *argv[] ) {
   if (argc != 4) {
      printf("Usage: %s <integer> <r/i> <filename>\n", argv[0]);
      return 1;
   }

   int file_num;

   int num;

   int compute;

   FILE *file = fopen(argv[3], "r");

   if (file == NULL) {
      printf("Error checking of file and params is not necessary '%s'\n", argv[3]);
      return 1;
   }
   fscanf(file, "%d", &file_num);
   fclose(file);

   num = atoi(argv[1]) + file_num;

   if (argv[2][0] == 'r') 
      compute = fibRec(num);
   else 
      compute = fibIter(num);

   printf("%d\n", compute);

   return 0;
}