/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on March 2, 2015, 4:55 PM
 *      Purpose: Addition and Multiplication Calculator
 */
//System Libraries
#include <iostream>//I/O System Libraries
using namespace std;//System Libraries using standard namespace

//User Libraries

//Global Constants

//Function Prototype

//Execution starts here

int main(int argc, char** argv) {
    //Declare Variables
        double num1,num2,sum,product;
        //Prompt for x input
            cout<<"Input first value"<<endl;
            cout<<"Enter as xxx.xx"<<endl;
            cin>>num1;
        //Prompt for time
            cout<<"Input second value"<<endl;
            cout<<"Enter as xxx.xx"<<endl;
            cin>>num2;
    //Prompt Finish
            cout<<"Calculation Complete."<<endl;
    //Calculate Sum and Display
        sum = num1 + num2;
        cout<<"Sum = "<<sum<<endl;
    //Calculate for Product and Display
        product = num1 * num2;
        cout<<"Product = "<<product<<endl;
    return 0;
}

