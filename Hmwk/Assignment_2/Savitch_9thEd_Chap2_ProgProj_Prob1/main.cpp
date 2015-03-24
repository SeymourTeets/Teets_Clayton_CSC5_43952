/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on March 15, 2015, 9:51 AM
 *      Purpose: How many sodas can you drink before you die?
 */
//System Library
#include <iostream>
using namespace std;
//User Libraries

//Global Constants
const short CONVPTG = 454;
//Function Prototype

//Executio Incipio
int main(int argc, char** argv) {
    //Declare Variables
    unsigned int urWtGs;
    float lethSgr, nCans;
    unsigned short urWtLbs;
    short oneSoda = 350;
    unsigned char lethal= 7;
    //Prompt User for Inputs
    cout<<"I will inform you how many sodas you may consume before death. "<<endl;
    cout<<"Please enter your weight in pounds."<<endl;
    cin>>urWtLbs;
    //Calculate Number of Cans
    urWtGs = urWtLbs * CONVPTG;
    lethSgr = urWtGs / lethal;
    nCans = lethSgr / oneSoda;
    //Output Results
    cout<<"You may drink "<<nCans<<" cans of soda before consuming a lethal amount of artificial sugar"<<endl;
    //Executio Disicere
    return 0;
}

