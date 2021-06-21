#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

static void getUserGpa(void)
{
    int32_t cnt_gpa = 0;
    int32_t gpa = 0;

    printf("Enter your GPA (out of 100):");

    cnt_gpa = scanf("%d", &gpa);
    if (1 != cnt_gpa) {
        printf("Invalid entry\n");
    }
    else {
        findByGPA(gpa);
    }
}

static void showLITStudies(bool hide)
{
    if (!hide) {
        printf("\nStudies in Lithuania:\n");
        searchLith();
    }

}

int main(int argc, char* argv[])
{
    int32_t result = -1;
    bool is_masters = false;
    bool hide_lit = false;

    greatStudent();

    if (1 == argc) {
        printf("Loaded bachelor studies\n");
    } else if (argc >= 2) {
        for (uint32_t counter = 0; counter < argc; counter++) {
            printf("\nargv[%d]: %s", counter, argv[counter]);
            result = strcmp(argv[counter], "mas");
            if (0 == result) {
                is_masters = true;
            }
            result = strcmp(argv[counter], "lit");
            if (0 == result) {
                hide_lit = true;
            }
        }
    }

    loadUniData(is_masters);

    getUserGpa();
    showLITStudies(hide_lit);

    return 0;
}