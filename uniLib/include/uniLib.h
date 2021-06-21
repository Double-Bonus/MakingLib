#pragma once
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char uniName[20];
    char program[40];
    char country[40];
    int32_t minGrade;
} sUniData;

void greatStudent(void);
void loadUniData(bool isMast);
void findByGPA(int32_t grade);
bool isGradeValid(int32_t gpa);
void searchLith(void);
uint32_t getLitCountries(sUniData data[], uint32_t cnt, uint32_t out_index[]);

#ifdef __cplusplus
}
#endif
