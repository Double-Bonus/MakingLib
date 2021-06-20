#include <stdio.h>
#include "uniLib.h"

#define MAX_ENTRIES 10

typedef struct {
    char uniName[20];
    char program[40];
    char country[120];
    int32_t minGrade;
} sUniData;

uint8_t entries_cnt = 0;
sUniData uni_data[MAX_ENTRIES];

void greatStudent()
{
    printf("Welcome to university!!!\n");
}



void loadUniData()
{
    char line[200];
    FILE* pf = NULL;

    if ((pf = fopen("../../../user.txt", "r")) == NULL) {
        printf("could not open file\n");
        //return 1;
    } else {
        uint8_t i = 0;
        while (i < MAX_ENTRIES && (fgets(line, sizeof(line), pf))) {
            if ((sscanf(line, "%20[^,],%40[^,],%20[^,],%d\n]"
                , uni_data[i].uniName, uni_data[i].program, uni_data[i].country, &uni_data[i].minGrade)) == 4) {
                printf("%d %s %s %s\n", uni_data[i].minGrade, uni_data[i].uniName, uni_data[i].program, uni_data[i].country);
                i++;
            }
        }
        entries_cnt = i;
        fclose(pf);
    }
}


void findByGPA(int32_t grade)
{
    if (NULL == uni_data) {
        return;
    }

    for (uint8_t i = 0; i < entries_cnt; i++) {
        if(grade >= uni_data[i].minGrade) {
          printf("%d %s %s %s\n", uni_data[i].minGrade, uni_data[i].uniName, uni_data[i].program, uni_data[i].country);
        }
    }
}