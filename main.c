#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>


int main(int argc, char* argv[])
{
    int32_t gpa = 0;
    int32_t result = -1;
    int32_t cnt_gpa = 0;
    bool isMasters = false;

    greatStudent();

    if (argc == 1) {
        printf("Loaded bachelor studies\n");
    } else if (argc >= 2) {
        for (uint32_t counter = 0; counter < argc; counter++) {
            printf("\nargv[%d]: %s", counter, argv[counter]);
            result = strcmp(argv[counter], "mas");
            if (0 == result) {
                isMasters = true;
            }
        }
    }

    loadUniData(isMasters);

    printf("Enter your GPA (out of 100):");

    cnt_gpa = scanf("%d", &gpa);
    if (1 != cnt_gpa) {
      printf("Invalid entry\n");
    } else {
      findByGPA(gpa);
    }

    printf("\nStudies in lithuania:\n");
    searchLith();
    return 0;
}