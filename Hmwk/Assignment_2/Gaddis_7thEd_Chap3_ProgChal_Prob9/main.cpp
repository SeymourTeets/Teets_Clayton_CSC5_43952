/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on March 16, 2015, 10:18 AM
 *      Purpose: Cookie Calorie Calculator
 */
//System Libraries
#include <iostream>
using namespace std;
//User Libraries

//Function Prototype

//Global Constants

//Executio Incipio
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short cookies, tCal;
    char cal = 1.0e2;
    //Prompt for Input
    cout<<"How many cookies have you eaten?"<<endl;
    cin>>cookies;
    //Calculate
    tCal=cookies*cal;
    //Output results
    cout<<"You have consumed "<<tCal<<" calories"<<endl;
    //Executio Disicere
    return 0;
}

