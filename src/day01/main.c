#include <stdio.h>
#include <stdlib.h>

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
     char buf[256];
     long max_cals = 0, total = 0;
     int base = 10;

     while(fgets(buf, sizeof(buf), fd) != NULL) {
          if (buf[0] == '\n' || buf[0] == '\r') {
               if (total > max_cals) {
                    max_cals = total;
               }
               total = 0;
          } else {
               total += strtol(buf, NULL, base);
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
     char buf[256];
     long total = 0, first_elf = 0, second_elf = 0, third_elf = 0;
     int base = 10;

     while(fgets(buf, sizeof(buf), fd) != NULL) {
          if (buf[0] == '\n' || buf[0] == '\r') {
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
               total += strtol(buf, NULL, base);
          }
     }

     fprintf(stdout, "The sum of the top three elves is %ld.\n", first_elf + second_elf + third_elf);
}