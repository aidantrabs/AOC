#include <stdio.h>
#include <stdlib.h>

/*
*
* Constants
*
*/
char BUF[256];
int BASE = 10;

/*
*
* Function prototypes
*
*/
int calculate_max_calories(FILE *fd);
void calculate_top_three(FILE *fd);


/*
*
* Main
*
*/
int main() {
     FILE *fd = fopen("input.txt", "r");
     
     fprintf(stdout, "The elf with the most calories has %d calories.\n", calculate_max_calories(fd));
     rewind(fd);
     calculate_top_three(fd);
     
     fclose(fd);

     return 0;
}

/*
*
* Calculates the maximum calories consumed by an elf.
*
*/
int calculate_max_calories(FILE *fd) {
     long max_cals = 0, total = 0;

     while(fgets(BUF, sizeof(BUF), fd) != NULL) {
          if (BUF[0] == '\n' || BUF[0] == '\r') {
               if (total > max_cals) {
                    max_cals = total;
               }
               total = 0;
          } else {
               total += strtol(BUF, NULL, BASE);
          }
     }

     return max_cals;
}

/*
*
* Calculates the maximum calories consumed by the three elves with the most calories.
*
*/
void calculate_top_three(FILE *fd) {
     long total = 0, first_elf = 0, second_elf = 0, third_elf = 0;

     while(fgets(BUF, sizeof(BUF), fd) != NULL) {
          if (BUF[0] == '\n' || BUF[0] == '\r') {
               if (total > first_elf) {
                    third_elf = second_elf;
                    second_elf = first_elf;
                    first_elf = total;
               } else if (total > second_elf) {
                    third_elf = second_elf;
                    second_elf = total;
               } else if (total > third_elf) {
                    third_elf = total;
               }
               total = 0;
          } else {
               total += strtol(BUF, NULL, BASE);
          }
     }

     fprintf(stdout, "The sum of the top three elves is %ld.\n", first_elf + second_elf + third_elf);
}