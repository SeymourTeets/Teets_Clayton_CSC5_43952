/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on March 24, 2015, 10:20 AM
 *      Purpose: Time Calculator
 */
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio
int main(int argc, char** argv) {
    //Declare Variables
        int time;//Time input in seconds
        float days, hours, minutes;//Adjustment for seconds
    //Collect inputs
        cout<<"After entering a value of time in seconds, I will adjust the time, if"
            <<" necessary, to the appropriate units."<<endl;
        cout<<"Enter time in seconds: ";
        cin>>time;
    //Decide whether to convert or leave unchanged
        if (time >= 8.64e4f){
            days = time / 8.64e4f;
            cout<<"Time = "<<days<<" day(s)"<<endl;
        }
        else if ((time >= 3.6e3f)&&(time < 8.64e4f)){
            hours = time / 3.6e3f;
            cout<<"Time = "<<hours<<" hour(s)"<<endl;
        }
        else if ((time >= 6e1f)&&(time < 3.6e3f)){
            minutes = time / 6e1f;
            cout<<"Time = "<<minutes<<" minute(s)"<<endl;
        }
        else
            cout<<"Time = "<<time<<" second(s)";
    //Executio Incipio
    return 0;
}

