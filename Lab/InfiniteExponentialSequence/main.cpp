/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : April 29, 2015, 8:00 AM
 * Purpose    : 
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Output Formatting
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes
float ourExp(float x);
double ourExp(double x);
//Executio Incipio

int main(int argc, char** argv) {
    //Set the Random Number Generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare and Initialize Variables
    const unsigned int MAX= pow(2,31)-1;
    float xf=1.0f*rand()/MAX*3+1;//(1, 4)
    //Call the functions and compare
    float expAprx=ourExp(xf);
    float libExp=exp(xf);
    float prcntEr=(libExp-expAprx)/libExp*100;
    cout<<"exp("<<xf<<")="<<libExp<<","<<expAprx<<","<<prcntEr<<"%"<<endl;
    //Executio Disicere
    return 0;
}

float ourExp(float x){
    //Declare Variables
    float term=1, exp=1, tol=x*1e-7f;
    for(int nterm=1; term>tol; nterm++){
        term*x/nterm;
        exp+=term;
    }
    return exp;
}

 ourExp(float x){
    //Declare Variables
    float term=1, exp=1, tol=x*1e-7f;
    for(int nterm=1; term>tol; nterm++){
        term*x/nterm;
        exp+=term;
    }
    return exp;
}