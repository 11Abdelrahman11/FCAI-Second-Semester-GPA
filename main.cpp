// Program Name: GPA FCAI Second Semester Calculator
// Last Modification Date: 18/06/2022
// Author : Abdelrahman Mohamed

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include "FCAI-Second-Semester-GPA.h"

using namespace std;

int main()
{
    bool again = true;
    string grades[9], subjects[] = {"Programing 1", "Discrete Math", "Math 2", "Stat 1", "Economics", "Ethics", "Critical Thinking"};
    int degrees[7],creditHours[6] = {3, 3, 3, 3, 2, 2}, totalHours = 0;
    double points[7], value = 0;
    float GPA;
    char answer;
    while(again){
        again = false;
        cout << "Ahlan Ya User Ya Hapipy :)" << endl;
        enterData(grades, subjects, degrees, points);
        printData(grades, subjects, degrees);
        gpaCal(grades, points, creditHours, GPA, value, totalHours);
        cout << setfill('-');
        cout << setw(36) << "" << endl;
        cout << setfill(' ');
        cout << "Do You Want To Use Again !? y/n ";
        cin >> answer;
        if (answer == 'Y' || answer == 'y'){
            again = true;
        }
    }

return 0;
}
