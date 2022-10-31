#include <stdio.h> 
#define START_ID 1000

struct student {
    ;    
    ;  
    ; 
};

int main(int argc, char* argv[]) 
{  
   struct student record;
   FILE *fp;

   if (argc != 2) {
      fprintf(stderr, "Usage: %s [file name]\n", argv[0]);
      return 1; 
   }

   fp = fopen(argv[1], "w");
   printf("%-6s %-5s %-4s\n", "ID",  "Name",  "Score"); 	

   while (                          ) 
      fprintf(fp,                          );
	
   fclose(fp);
   return 0;
}  
