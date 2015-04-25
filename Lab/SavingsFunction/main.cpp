/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on April 20, 2015
 *      Purpose: Savings Function
 */
//System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes
float save1(float, float, int);//Power Function
float save2(float, float, int);//Log and Exponential Function
float save3(float, float, int);//For loop
float save4(float, float, int);//Recursive -> Calling if 
float save5(float=1e2f, float=8e-2f, int=9);//Default
void save6(float &, float, float, int);//Pass by reference
void save7(float &, float, int);//Pass by reference
float save1(float, float, float);//Over ridden function
//Executio Incipio
int main(int argc, char** argv) {
    //Declare Variables
    float pv = 1e2f;//Present value in $'s
    float ir = 8e-2f;//Interest rate %/yr
    int nC = 9;//Number of compounding interests
    //Output Inputs
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Present value = $"<<pv<<endl;
    cout<<"Interest rate = "<<ir*100<<"%"<<endl;
    cout<<"Number of compounding periods = "<<nC<<" (years)"<<endl;
    //Calculate savings
    cout<<"Savings Function 1 = $"<<save1(pv, ir, nC)<<endl;
    float nCf=nC;
    cout<<"Savings Function 2 = $"<<save2(pv, ir, nC)<<endl;
    cout<<"Savings Function 3 = $"<<save3(pv, ir, nC)<<endl;
    cout<<"Savings Function 4 = $"<<save4(pv, ir, nC)<<endl;
    cout<<"Savings Function 5 = $"<<save5(pv, ir, nC)<<endl;
    cout<<"Savings Function 5 = $"<<save5(pv, ir)<<endl;
    cout<<"Savings Function 5 = $"<<save5(pv)<<endl;
    cout<<"Savings Function 5 = $"<<save5()<<endl;
    float fv;
    save6(fv, pv, ir, nC); 
    cout<<"Savings Function 6 = $"<<fv<<endl;
    save7(pv, ir, nC);
    cout<<"Savings Function 7 = $"<<pv<<endl;
    
    //Executio Disicere
    return 0;
}

//Function for future value calculation
//Inputs
//      p-> Present Value $'s
//      i-> Interest Rate $/Compound interest period
//      n-> Compounding Period Yr's
//Outputs
//      fv-> Future value in $'s

float save1(float p, float i, int n){
    return p*pow(1+i, n);}

float save2(float p, float i, int n){
    return p*exp(n*log(1+i));}

float save3(float p, float i, int n){
    for(int year=1; year<=n;year++){
        p*=(1+i);}
    return p;}

float save4(float p, float i, int n){
    if(n<=0) return p;//1st return
    return save4(p,i,n-1)*(i+1);}

float save5(float p, float i, int n ){
    return p*pow((1+i), n);}

void save6(float &f, float p, float i, int n){
    f=p*pow((1+i), n);}

void save7(float &p, float i, int n){
    p=p*pow((1+i), n);}