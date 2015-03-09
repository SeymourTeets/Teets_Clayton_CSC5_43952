/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on March 2, 2015, 8:29 AM
 *      Purpose: Free fall problem from Savitch
 */
//System Libraries
#include <iostream> //Input/Output Stream
using namespace std; //I/O Stream under standard namespace

//User Libraries

//Global Constants
const float G=3.2174e1f;//Acceleration in ft/sec^2
const float CNVFTMT=3.048e-1f;//Conversion for feet to meters

//Function Prototype

//Execution Begins Here.

int main(int argc, char** argv) {
    //Declare Variables
    float time,dstnce;
    //Prompt for time
    cout<<"Free Fall Problem"<<endl;
    cout<<"Input the time to drop x.xx (seconds)"<<endl;
        cin>>time;
    //Calculate the distance
    dstnce=G*0.5f*time*time;
    //Output:
    cout<<"Distance fallen = "<<dstnce<<"(feet)"<<endl;
    cout<<"Distance fallen = "<<dstnce*CNVFTMT<<"(meters)"<<endl;
    return 0;
}

