/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on April 10, 2015, 6:26 PM
 *      Purpose: Rate of Inflation
 */
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float money, infl, rate, num;
    num=1;
    money=1000;
    cout<<"Enter the yearly inflation rate as xx.xx"<<endl;
    cin>>infl;
    rate=infl/100;
    rate=1-rate;
    cout<<fixed<<showpoint<<setprecision(2);
    if(infl<=15 && infl>=1){
        while(num<=10){
            money*=rate;
            cout<<"The purchasing power for year "<<num<<" is "<<money<<" dollars"<<endl;
            num++;
        }
    }else 
        cout<<"Please repeat the whole problem again"<<endl;
    return 0;
}
