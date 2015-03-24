/* 
 * File:   main.cpp
 * Author: caitlinswafford
 *
 * Created on March 12, 2015, 10:18 PM
 *      Purpose: Batting Average
 */

//System Libraries
#include <iostream>//I//O System Libraries
using namespace std;

//User Libraries

//Function Prototypes

//Global Constants

//Execution Starts Here!
int main(int argc, char** argv) {
    //Declare Variables
    int hits;
    int atbat;
    float average = ((float) hits / atbat);
    #define average ((float) hits / atbat)
    //Input 
    cout<< "Enter how many times you were up to bat: "<<endl;
    cin>>atbat;
    cout<<"Enter how many hits you got: "<<endl;
    cin>>hits;
    //Output
    cout<<"The average is "<<average<<endl;
    return 0;
}

