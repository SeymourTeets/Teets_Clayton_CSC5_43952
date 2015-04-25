/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on April 10, 2015, 7:55 AM
 *      Purpose: Assignment [4] Menu
 */
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;
//User Libraries

//Global Constants
float KMTM = .6214;
//Function Prototype

//Executio Incipio
int main(int argc, char** argv) {
    cout<<"Type 0 to solve problem 2  (Sum of Numbers)"<<endl;
    cout<<"Type 1 to solve problem 3  (Distance Traveled)"<<endl;
    cout<<"Type 2 to solve problem 4  (Celsius to Fahrenheit Table)"<<endl;
    cout<<"Type 3 to solve problem 5  (Speed Conversion Chart)"<<endl;
    cout<<"Type 4 to solve problem 6  (Ocean Levels)"<<endl;
    cout<<"Type 5 to solve problem 7  (Pennies for Pay)"<<endl;
    cout<<"Type 6 to solve problem 8  (Calories Burned)"<<endl;
    cout<<"Type 7 to solve problem 9  (Membership Fees Increase)"<<endl;
    cout<<"Type 8 to solve problem 12 (The Greatest and Least of These)"<<endl;
    cout<<"Type 9 to solve problem 14 (Rate of Inflation)"<<endl;
    cout<<"Type anything else to quit with no solutions."<<endl;
    cout<<endl;
    //Read the choice
    char choice;
    cout<<"I would like to solve problem: ";
    cin>>choice;
    cout<<endl;
    //Solve a problem that has been chosen.
    switch(choice){
            case '0':{
                //Declare Variables
                    unsigned int x, sum;
                //Prompt user for input
                    cout<<"I will calculate the sum of the numbers from one to the number of you choose."<<endl;
                    cout<<"Please enter a number: ";
                    cin>>x;
                if (x>0){
                //Begin loop
                    while (x>0){
                        sum+=x;
                        x--;
                    }
                //Output the results
                    cout<<sum<<endl;
            }
                else cout<<"You did not input a positive number";
                break;
            }
            case '1':{
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
                        number++;}
                break;
            }
            case '2':{
                //Declare Variables
                    float fhrnht;//Temperature in Fahrenheit
                    float celsius;//Temperature in Celsius
                    celsius = 0;
                //Calculation begins here with a loop!
                    while (celsius <= 20){
                        fhrnht=static_cast<float>((celsius*9)/5)+32;
                        cout<<"When the temperature in celsius is "<<celsius<<", the temperature in fahrenheit is "<<fhrnht<<" degrees"<<endl;
                        celsius++;}
                break;
            }
            case '3':{
                //Declare Variables
                    unsigned int kph;
                    kph=60;//Starts at 60 KPH
                    float mph;
                //Loop
                    while (kph<=130){
                        mph = kph*KMTM;
                        cout<<"At "<<kph<<" kilometers per hour, you are traveling at "<<mph<<" miles per hour"<<endl;
                        kph +=5;//At 5 km intervals}
                break;
            }
            case '4':{
                //Declare Variables
                    float rLvl,num;
                    num=1;
                //Loop
                    while(num<=25){
                        rLvl+=3.1;
                        cout<<"The ocean level in "<<num<<" years, will rise "<<rLvl<<" mm"<<endl;
                        num++;}
                break;
            }
            case '5':{
                //Declare Variables
                    unsigned int days, number;
                    float penny, salary;
                    penny = 1e-2;
                    number = 1;
                //Prompt for inputs
                    cout<<"How many days did you work this month? ";
                    cin>>days;
                //Set for dollars precision
                    cout<<fixed<<showpoint<<setprecision(2);
                //Loop
                    if (days>=0 && days<=31){
                        while (number <= days){
                            cout<<"On day "<<number<<" you made "<<penny<<" dollars"<<endl;
                            salary += penny;
                            penny *= 2;
                            number++;}
                //Output
                    cout<<"Your total salary for this month is "<<salary<<endl;
            }
                //Input Validation
                    else cout<<"The value you have entered is outside the parameters of a month. Please try again.";
                break;
            }
            case '6':{
                //Declare Variables
                    int calories = 3.9; 
                    int calburn;
                //Output
                    for (int minutes = 10; minutes < 30; minutes += 5){
                        calburn= calories * minutes;
                       cout<<"Calories burned in "<<minutes<<" minutes: "<<calburn<<endl;}
                break;
            }
            case '7':{
                //Declare Variables
                    int n;
                    float cost = 2500, inc = 1.04;
                //Input
                    cout<<fixed<<showpoint<<setprecision(2);
                //Loop
                    for (n=1; n<=6; n++){
                        cost*=inc;
                        cout<<"Year: "<<n<<" Cost: "<<cost<<endl;}
                break;
            }
            case '8':{
                //Declare Variables
                    int num;
                //Input
                    cout << "How many numbers would you like to enter?" << endl;
                    cin >> num;
                    cout << "You would like to enter "<< num <<" numbers"<<endl;
                    cout << "Please enter your numbers: "<<endl;
                //Output
                    int highNum;
                    cin >> highNum;// save 1st value as highest
                    int inNum;// for reading the rest of the values
                //Looping
                    for(int i = 2; i <= num; ++i ){
                        cin >> inNum;// read input
                        if( inNum > highNum ){// compare to highest yet
                            highNum = inNum;}// replace highest   
                            }
                    cout << "The highest number entered was: " << highNum;
                break;
            }
            case '9':{
                //Declare Variables
                    float money, infl, rate, num;
                    num=1;
                    money=1000;
                //Prompt for Inputs
                    cout<<"Enter the yearly inflation rate as xx.xx"<<endl;
                    cin>>infl;
                //Convert Intrest to Decimal Form
                    rate=infl/100;
                    rate=1-rate;
                    cout<<fixed<<showpoint<<setprecision(2);
                //Input Validation and Calculation
                    if(infl<=15 && infl>=1){
                        while(num<=10){
                            money*=rate;
                            cout<<"The purchasing power for year "<<num<<" is "<<money<<" dollars"<<endl;
                            num++;}
            }else cout<<"Please repeat the whole problem again"<<endl;
                break;
            }
    }
    return 0;
}
