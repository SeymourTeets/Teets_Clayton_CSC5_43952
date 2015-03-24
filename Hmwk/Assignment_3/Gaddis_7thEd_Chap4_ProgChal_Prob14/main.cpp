/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on March 23, 2015, 10:56 PM
 *      Purpose: Body Mass Index
 */
//System Libraries
#include <iostream>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio
int main(int argc, char** argv) {
    //Declare Variables
    float bmi, weight, height;
    //Prompt for Inputs
    cout<<"I will calculate your Body Mass Index and inform you of the status of your weight."<<endl;
    cout<<"Enter height in inches: ";
    cin>>height;
    cout<<"Enter weight in pounds: ";
    cin>>weight;
    cout<<endl;
    //Calculate BMI
    bmi = weight * (7.03e2f / (height * height));
    //Tell user of their BMI and their weight status
    if ((bmi >= 1.85e1f)&&(bmi <= 2.5e1f))
        cout<<"Your BMI is "<<bmi<<" and you are optimal weight."<<endl;
    else if (bmi < 1.85e1f)
        cout<<"Your BMI is "<<bmi<<" and you are underweight."<<endl;
    else
        cout<<"Your BMI is "<<bmi<<" and you are overweight."<<endl;
    return 0;
}

