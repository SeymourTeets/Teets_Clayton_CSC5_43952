/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on April 10, 2015, 2:51 PM
 *      Purpose: Speed Conversion Chart
 */
//System Libraries
#include <iostream>
using namespace std;
//User Libraries

//Global Constants
float KMTM=.6214;
//Function Prototypes

//Executio Incipio
int main(int argc, char** argv) {
    //Declare Variables
        unsigned int kph;
        kph=60;//Starts at 60 KPH
        float mph;
    //Loop
        while (kph<=130){
            mph = kph*KMTM;
            cout<<"At "<<kph<<" kilometers per hour, you are traveling at "<<mph<<" miles per hour"<<endl;
            kph +=5;//At 5 km intervals
        }
    //Executio Disicere
    return 0;
}