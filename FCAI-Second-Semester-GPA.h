#ifndef FCAI-SECOND-SEMESTER-GPA_H_INCLUDED
#define FCAI-SECOND-SEMESTER-GPA_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include "FCAI-Second-Semester-GPA.h"

using namespace std;

double degree (string subject);
int intLength( int N );
bool is_Integer (string number);
int Length ( double n );
void enterData (string grades[], string subjects[], int degrees[], double points[]);
void printData (string grades[], string subjects[], int degrees[]);
void gpaCal (string grades[], double points[], int creditHours[], float GPA, int value, int totalHours);

#endif // FCAI-SECOND-SEMESTER-GPA_H_INCLUDED
