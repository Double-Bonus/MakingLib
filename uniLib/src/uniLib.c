#include "uniLib.h"
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 10
#define MAX_GRADE 100
#define MIN_GRADE 40 // 40% - minimum to graduate
#define LITHUANIA "Lithuania"

uint32_t entries_cnt = 0;
sUniData uni_data[MAX_ENTRIES] = {0};

void greatStudent(void)
{
    printf("Welcome to university application!!!\n");
}

void loadUniData(bool is_mast)
{
    char line[200];
    FILE* pf = NULL;

    if (is_mast) {
        pf = fopen("../../../mastData.txt", "r");
    } else {
        pf = fopen("../../../bacData.txt", "r");
    }

    if (NULL == pf) {
        printf("could not open file\n");
    } else {
        uint8_t i = 0;
        while (i < MAX_ENTRIES && (fgets(line, sizeof(line), pf))) {
            if ((sscanf(line, "%20[^,],%40[^,],%40[^,],%d\n]"
                , uni_data[i].uniName, uni_data[i].program, uni_data[i].country, &uni_data[i].minGrade)) == 4) {
                printf("%d %s %s %s\n", uni_data[i].minGrade, uni_data[i].uniName, uni_data[i].program, uni_data[i].country);
                i++;
            }
        }
        entries_cnt = i;
        fclose(pf);
    }
}

/// <summary>
/// Finds and prints to console studies wich you could apply based on GPA
/// </summary>
/// <param name="grade">Grade % from universery/school </param>
void findByGPA(int32_t grade)
{
    bool found = false;
    if (NULL == uni_data) {
        return;
    }

    for (uint8_t i = 0; i < entries_cnt; i++) {
        if(grade >= uni_data[i].minGrade) {
          printf("Min grade: %d%% %s %s %s\n", uni_data[i].minGrade, uni_data[i].uniName, uni_data[i].program, uni_data[i].country);
          found = true;
        }
    }
    if (!found) {
        printf("There are no studies with your GPA :(");
    }
}

bool isGradeValid(int32_t gpa)
{
    return (gpa <= MAX_GRADE && gpa >= MIN_GRADE);
}


/// <summary>
/// Function calculates number of studies in Lithuania, and returns indexes of these data entries
/// </summary>
/// <param name="data">Input of studies data</param>
/// <param name="cnt">Entries count</param>
/// <param name="out_index">Array for indexes</param>
/// <returns>Total number of studies in given data set</returns>
uint32_t getLitCountries(sUniData data[], uint32_t cnt, uint32_t out_index[])
{
  uint32_t lit_cnt = 0;
  int32_t result = -1;
  for (uint32_t i = 0; i < cnt; i++) {
    result = strcmp(data[i].country, LITHUANIA);
    if (0 == result) {
      out_index[lit_cnt] = i;
      lit_cnt++;
    }
  }
  return lit_cnt;
}


void searchLith(void) 
{
  uint32_t lit_indexs[MAX_ENTRIES] = {0};
  uint32_t lit_cnt = 0;
  sUniData temp_data = {0};

  if (0 != entries_cnt) {
    lit_cnt = getLitCountries(uni_data, entries_cnt, lit_indexs);
      for (uint32_t i = 0; i < lit_cnt; i++) {
      temp_data = uni_data[lit_indexs[i]];
        printf("%d %s %s %s\n", temp_data.minGrade, temp_data.uniName,
             temp_data.program, temp_data.country);
      }
  }
}
