#include <stdio.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    int32_t gpa = 0;
    printf("Hello mate!\n");

    if (argc == 1) {
        printf("No extra arguments used\n");
    }
    else if (argc >= 2) {
        printf("Used %d argumets/n", argc);
        printf("What was passed:/n");
        for (uint32_t counter = 0; counter < argc; counter++)
            printf("\nargv[%d]: %s", counter, argv[counter]);
    }

    greatStudent();
    loadUniData();

    printf("Enter your GPA:");

    scanf("%d", &gpa);
    findByGPA(gpa);
    return 0;
}