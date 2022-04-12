#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

double degree (string subject);
int intLength( int N );

int main()
{
    bool again = true;
    string grades[8], subjects[] = {"Programing 1", "Discrete Math", "Math 2", "Stat 1", "Economics", "Ethics", "Critical Thinking"};
    int degrees[7],creditHours[6] = {3, 3, 3, 3, 2, 2}, totalHours = 0;
    double points[7], value = 0, GPA = 0;
    char answer;
    while(again){
        again = false;
        cout << "Ahlan Ya User Ya Hapipy :)" << endl;
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
        cout << "Subject" << setw(10) << "" << "| " << "Degree" << setw(4) << "" << "| " << "Grade" << endl;
        for (int k = 0; k < 7; k++){
            cout << subjects[k] << setw(17-subjects[k].length()) << "" << "| " << degrees[k] << setw(10 - intLength(degrees[k])) << "" << "| " << grades[k] << endl;
        }
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
            cout << "GPA" << setw(14) << "" << "| " << setw(3) << GPA << setw(7) << "" << "| " << grades[8] << endl;
        }
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

double degree (string subject){
    int degree;
    cout << "Enter " << subject << " Degree: ";
    cin >> degree;
    while(degree > 100 || degree < 0){
        cout << "Please Insure to Enter A Valid Degree (0-100): ";
        cin >> degree;
    }
    return degree;
}
int intLength ( int N ){
    if      ( N < 0  ) return 1 + intLength( -N );
    else if ( N < 10 ) return 1;
    else               return 1 + intLength( N / 10 );
}
