/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on March 12, 2015, 10:26 PM
 *      Purpose: Test Averages
 */
//System Libraries
#include <iostream>//I//O System Libraries
using namespace std;
//User Libraries

//Function Prototypes

//Global Constants

//Executio Incepio
int main(int argc, char** argv) {
    //Declare Variables
        int average;
        int tScore1; 
        int tScore2; 
        int tScore3; 
        int tScore4;
        int tScore5;
    //Input Scores
        cout<<"Enter results for test 1:"<<endl;
        cin>>tScore1;
        cout<<"Enter results for test 2:"<<endl;
        cin>>tScore2;
        cout<<"Enter results for test 3:"<<endl;
        cin>>tScore3;
        cout<<"Enter results for test 4:"<<endl;
        cin>>tScore4;
        cout<<"Enter results for test 5:"<<endl;
        cin>>tScore5;
    //Calculate Test Scores
        average = (tScore1 + tScore2 + tScore3 + tScore4 + tScore5)/5;
    //Output Average of all Scores
        cout<<"The average for all 5 tests is "<<average<<"%"<<endl;
    //Executio Disicere
    return 0;
}

