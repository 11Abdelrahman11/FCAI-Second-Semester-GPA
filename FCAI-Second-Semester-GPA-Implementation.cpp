#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include "FCAI-Second-Semester-GPA.h"

using namespace std;

double degree (string subject){
    string degreeVal;
    cout << "Enter " << subject << " Degree: ";
    cin >> degreeVal;
    int Intdegree;
    if (is_Integer(degreeVal) == false){
        while(is_Integer(degreeVal) == false){
            cout << "Please Insure to Enter A Valid Degree (number between (0-100)): ";
            cin >> degreeVal;
            if (is_Integer(degreeVal)){
                Intdegree = stoi(degreeVal);
                while(Intdegree > 100 || Intdegree < 0){
                    cout << "Please Insure to Enter A Valid Degree (number between (0-100)): ";
                    cin >> Intdegree;
                }
            }
        }
    }
    else{
        Intdegree = stoi(degreeVal);
        while(Intdegree > 100 || Intdegree < 0){
            cout << "Please Insure to Enter A Valid Degree (number between (0-100)): ";
            cin >> Intdegree;
        }
    }
    return Intdegree;
}
bool is_Integer(string number){
    bool is_integer = false;
    for (int i = 0; i < number.length(); i++){
        if (isdigit(number[i]) == false){
            is_integer = false;
            break;
        }
        else{
            is_integer = true;
        }
    }
    return is_integer;
}
int intLength ( int N ){
    if      ( N < 0  ) return 1 + intLength( -N );
    else if ( N < 10 ) return 1;
    else               return 1 + intLength( N / 10 );
}
int Length ( double n){  // just for double type
    string str_Number;
    str_Number = to_string(n);
    int length = 0;
    for (char i = 0; i < str_Number.length(); i++){
        length++;
    }
    return length-2;
    cout << "Hello world!" << endl;
    return 0;
}
void enterData(string grades[], string subjects[], int degrees[], double points[]){
    for (int i = 0; i < 7; i++){
            degrees[i] = degree(subjects[i]);
        }
        cout << setfill('-');
        cout << setw(36) << "" << endl;
        cout << setfill(' ');
        for (int j = 0; j < 7; j++){
            if (degrees[j] >= 90){
                grades[j] = "A+";
                if (j < 6){
                    points[j] = 4;
                }
            }
            else if (degrees[j] >= 85){
                grades[j] = "A";
                if (j < 6){
                    points[j] = 3.7;
                }
            }
            else if (degrees[j] >= 80){
                grades[j] = "B+";
                if (j < 6){
                    points[j] = 3.3;
                }
            }
            else if (degrees[j] >= 75){
                grades[j] = "B";
                if (j < 6){
                    points[j] = 3;
                }
            }
            else if (degrees[j] >= 70){
                grades[j] = "C+";
                if(j < 6){
                    points[j] = 2.7;
                }
            }
            else if (degrees[j] >= 65){
                grades[j] = "C";
                if (j < 6){
                    points[j] = 2.4;
                }
            }
            else if (degrees[j] >= 60){
                grades[j] = "D+";
                if (j < 6){
                    points[j] = 2.2;
                }
            }
            else if (degrees[j] >= 50){
                grades[j] = "D";
                if (j < 6){
                    points[j] = 2;
                }
            }
            else{
                grades[j] = "F";
                if (j < 6){
                    points[j] = 0;
                }
            }
        }
}
void printData(string grades[], string subjects[], int degrees[]){
    cout << "Subject" << setw(10) << "" << "| " << "Degree" << setw(4) << "" << "| " << "Grade" << endl;
        for (int k = 0; k < 7; k++){
            cout << subjects[k] << setw(17-subjects[k].length()) << "" << "| " << degrees[k] << setw(10 - intLength(degrees[k])) << "" << "| " << grades[k] << endl;
        }
}
void gpaCal (string grades[], double points[], int creditHours[], float GPA, int value, int totalHours){
    for (int l = 0; l < 6; l++){
            value += (points[l] * creditHours[l]);
            totalHours += creditHours[l];
        }
        GPA = value/totalHours;
        if (GPA == 4){
            grades[8] = "A+";
        }
        else if (GPA < 4 && GPA >= 3.7 ){
            grades[8] = "A";
        }
        else if (GPA < 3.7 && GPA >= 3.3){
            grades[8] = "B+";
        }
        else if (GPA < 3.3 && GPA >= 3){
            grades[8] = "B";
        }
        else if (GPA < 3 && GPA >= 2.7){
            grades[8] = "C+";
        }
        else if (GPA < 2.7 && GPA >= 2.4){
            grades[8] = "C";
        }
        else if (GPA < 2.4 && GPA >= 2.2){
            grades[8] = "D+";
        }
        else if (GPA < 2.2 && GPA >= 2){
            grades[8] = "D";
        }
        else{
            grades[8] = "F";
        }
        if (GPA == 0 ||GPA == 1 ||GPA == 2 ||GPA == 3 ||GPA == 4){
            cout << "GPA" << setw(14) << "" << "| " << GPA << setw(9) << "" << "| " << grades[8] << endl;
        }
        else{
            cout << "GPA" << setw(14) << "" << "| " << setprecision(2) << GPA << setw(7) << "" << "| " << grades[8] << endl;
        }
}
