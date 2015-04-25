/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on April 10, 2015, 2:51 PM
 *      Purpose: Distance Traveled
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
        unsigned int dstance, speed, time, number;
        number = 1;
   //Prompt User for Inputs
        cout<<"I will calculate the distance you have gone per hour."<<endl;
        cout<<"How long have you traveled in hours (Enter as whole number)? ";
        cin>>time;
        cout<<"What speed did you travel at?(Enter in miles per hour ";
        cin>>speed;
    //Loop
        while (number <= time){
            dstance += speed;
            cout<<"On hour "<<number<<" you have traveled "<<dstance<<endl;
            number++;
        }
    //Executio Disicere
    return 0;
}