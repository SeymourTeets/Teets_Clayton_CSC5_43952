/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on March 24, 2015, 7:27 AM
 *      Purpose: Mass and Weight
 */
//System Libraries
#include <iostream>
using namespace std;
//User Libraries

//Global Constants
float CONVMTW = 9.8f;//Converts mass (kilograms) to weight (newtons)
//Function Prototypes

//Executio Incipio
int main(int argc, char** argv) {
    //Declare Variables
    float mass, weight;//Input and output
    //Prompt user for weight in kg
    cout<<"I will calculate the weight of an object in newtons and determine if it"
        <<"to heavy or to light"<<endl;
    cout<<"Enter mass in kilograms as XXX.XX: ";
    cin>>mass;
    //Calculate Weight
    weight = mass * CONVMTW;
    //Output weight and notify user to weight status
    cout<<"The objects weight in newtons is "<<weight<<" and ";
    if (weight < 10)
        cout<<"the object is too light";
    else if (weight > 1000)
        cout<<"the object is too heavy";
    else
        cout<<"the object is optimal weight";
    return 0;
}

