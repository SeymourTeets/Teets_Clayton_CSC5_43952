/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on March 9, 2015, 9:46 AM
 *       Purpose: Candy Bar Calculator
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
    unsigned short wt, ht, age;
    char mf;
    unsigned char cBar=230;
    float bmrMale,bmrFem,nCbars;
    //Prompt for input
    cout<<"How many candy bars does it take to maintain your weight?"<<endl;
    cout<<"Input your weight in pounds."<<endl;
    cin>>wt;
    cout<<"Input height in inches."<<endl;
    cin>>ht;
    cout<<"Input your age in years."<<endl;
    cin>>age;
    cout<<"Are you male or female?"<<endl;
    cout<<"Enter as m or f."<<endl;
    cin>>mf;
    //Calculate
    bmrFem = 655 + 4.3 * wt + 4.7 * ht - 4.7 * age;
    bmrMale = 66 + 6.3 * wt + 12.9 * ht - 6.8 * age;
    //     Ques          if Male       if Female
    nCbars=((mf=='m')?(bmrMale/cBar):(bmrFem/cBar));
    //Output the results
    cout<<"Your weight = "<<wt<<"(lbs)."<<endl;
    cout<<"Your height = "<<ht<<"(in)."<<endl;
    cout<<"Your age = "<<age<<"(years)."<<endl;
    cout<<"Your sex = "<<((mf=='m')?"Male.":"Female.")<<endl;
    cout<<"You can eat "<<nCbars<<" candy bars every day and maintain your current BMR."<<endl;
    return 0;
}

