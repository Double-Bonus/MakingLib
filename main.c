#include <stdio.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
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

    return 0;
}