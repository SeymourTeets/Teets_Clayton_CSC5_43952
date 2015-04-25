/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on April 20, 2015, 2:51 PM
 *      Purpose: Error Test
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
        float sum1=0, sum2=0, exSum1, exSum2;
        float val1=1e-1f, val2=5e-1f;
        int nXSum = 1e7;
    //Calculate the sum
        for(int i=1; i<=nXSum; i++){
            sum1+=val1;
            sum2+=val2;}
    //Exact Sum
        exSum1 = nXSum*val1;
        exSum2 = nXSum*val2;
    //Compare Results
        cout<<"Exact Sum 1  = "<<exSum1<<endl;
        cout<<"Summed Sum 1 = "<<sum1<<endl;
        cout<<"Percentage Error = "<<(exSum1-sum1)/exSum1*100<<"%"<<endl;
        cout<<"Exact Sum 2  = "<<exSum2<<endl;
        cout<<"Summed Sum 2 = "<<sum2<<endl;
        cout<<"Percentage Error = "<<(exSum2-sum2)/exSum2*100<<"%"<<endl;
    //Executio Disicere
    return 0;
}