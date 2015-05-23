/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 22, 2015, 9:44 PM
 * Purpose    : Driver's License Exam
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Output Formatting
#include <string>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio

class TestGrader {
public:
    char answers[20];

    void setKey(string test, const short max) {
        for (int i = 0; i < max; i++) {
            answers[i] = test[i];
        }
    }

    void grade(char *test, const short max) {
        int equal = 0;
        for (int i = 0; i < max; i++) {
            if (answers[i] == test[i]) {
                equal += 1;
            }
        }
        if (equal < 15) {
            cout << "You have failed your exam!" << endl;
            cout << equal << "/20";
        } else {
            cout << "You have passed!" << endl;
            cout << equal << "/20";
        }
    }
};

int main(int argc, char** argv) {
    //Declare Variables
    short const max = 20;
    char input[max] = {};
    //Declare answers object and fill
    TestGrader a;
    a.setKey("BDAACABACDBCDADCCBDA", max);
    //Prompt for inputs
    cout << "Input answers here using caps-lock :" << endl;
    for (int i = 0; i < max; i++) {
        cout << setw(2) << i + 1 << ". ";
        cin >> input[i];
        while (input[i] != 'A' && input[i] != 'B' && input[i] != 'C' && input[i] != 'D') {
            cout << "Invalid input, answer must be A, B, C, or D. ";
            cin >> input[i];
        }
    }
    //Grade test and output pass or fail
    a.grade(input, max);
    return 0;
}
