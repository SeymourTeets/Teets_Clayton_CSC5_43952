/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 25, 2015, 11:45 AM
 * Purpose    : Spectrum Analysis
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Output Formatting
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio

int main(int argc, char** argv) {
    //Declare Variables
    float wLength;
    //Prompt for inputs
    cout<<"What is length of the electromagnetic wave (meters)? ";
    cin>>wLength;
    //Output wave type
    if (0<wLength && wLength<=1e-11){
        cout<<"The wave is a gamma ray."<<endl;
    }
    else if (1e-11<wLength && wLength<=1e-8){
        cout<<"The wave is a x-ray."<<endl;
    }
    else if (1e-8<wLength && wLength<=4e-7){
        cout<<"The wave is ultraviolet."<<endl;
    }
    else if (4e-7<wLength && wLength<=4e-7){
        cout<<"The wave is visible light."<<endl;
    }
    else if (7e-11<wLength && wLength<=1e-3){
        cout<<"The wave is a infrared light."<<endl;
    }
    else if (1e-3<wLength && wLength<=1e-2){
        cout<<"The wave is a microwave."<<endl;
    }
    else if (1e-2<wLength){
        cout<<"The wave is a radio radio wave."<<endl;
    }
    else {
        cout<<"Are you sure you measured right?"<<endl;
    }
    //Executio Disicere
    return 0;
}
