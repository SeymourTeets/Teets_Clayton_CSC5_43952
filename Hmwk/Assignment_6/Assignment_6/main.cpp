/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 19, 2015, 3:16 PM
 * Purpose    : Assignment 6
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Output Formatting
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes
void problem0();
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
int countPerfect(int[], int);
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare menu variable choice
    char choice;
    //Repeat the menu
    do{
        //General Menu Format
        //Display the selection
        cout<<"Type 0 (Perfect Scores)          to solve problem 1"<<endl;
        cout<<"Type 1 (Roman Numeral Converter) to solve problem 2"<<endl;
        cout<<"Type 2 (Chips and Salsa)         to solve problem 3"<<endl;
        cout<<"Type 3 (Monkey Business)         to solve problem 4"<<endl;
        cout<<"Type 4 (Rain or Shine)           to solve problem 5"<<endl;
        cout<<"Type 5 (Lottery)                 to solve problem 6"<<endl;
        cout<<"Type 6 to solve problem "<<endl;
        cout<<"Type 7 to solve problem "<<endl;
        cout<<"Type 8 to solve problem "<<endl;
        cout<<"Type 9 to solve problem "<<endl;
        cout<<"Type anything else to quit with no solutions."<<endl;
        //Read the choice
        cout<<"Choice : ";
        cin>>choice;
        cout<<endl;
        //Solve a problem that has been chosen.
        switch(choice){
            case '0':problem0();break;
            case '1':problem1();break;
            case '2':problem2();break;
            case '3':problem3();break;
            case '4':problem4();break;
            case '5':problem5();break;
            case '6':problem6();break;
            case '7':problem7();break;
            case '8':problem8();break;
            case '9':problem9();break;
            default :cout<<"Exit"<<endl;
        };
    }while(choice>='0'&&choice<='9');
    //Exit Stage right
    return 0;
}

//*******************         Problem 0           ********************/
void problem0(){
    //Declare Variable
    int SIZE = 10;
    int scores[SIZE]={};
    int sCount = 0;
    //Prompt user for test scores
    cout<<"Enter 10 test scores"<<endl;
    for (int i=0; i<SIZE; i++){
        cout<<"Test "<<i+1<<" = ";
        cin>>scores[i];
        if (scores[i]<0 || 100<scores[i]) {
            cout<<"Invalid Input, Enter 0-100. ";
            cin>>scores[i];
        }
    }
    cout<<endl;
    //Call perfect score counter
    sCount = countPerfect(scores, SIZE);
    cout<<"You received "<<sCount<<" perfect scores"<<endl<<endl;
}

//*******************         Problem 1           ********************/
void problem1(){
//Declare Variable
    int SIZE = 21;
    string rNum[SIZE] = {"","I","II","III","IV","V","VI","VII","VIII","IX","X", 
                         "XI","XII","XIII","XIV","XV","XVI","XVII","XIII","XIX","XX"};
    int input;
    //Prompt for input
    cout<<"Enter numbers between 1-20 to convert to Roman numerals"<<endl;
    cout<<"Press 0 to quit"<<endl<<endl;
    while (input != 0){ //Do while input is not 0
        cout<<"Number = ";
        cin>>input;
        while (0>input || input>20){ //Input Validation
            cout<<"Invalid Input. Enter 1-20. ";
            cin>>input;
        }
        if (input == 0) {} //If input = 0, do nothing
        else { //If valid, output correct Roman numeral
            cout<<"Roman Numeral = "<<rNum[input]<<endl<<endl;
        }
    }
    cout<<endl;
}

//*******************         Problem 2           ********************/
void problem2(){
//Declare Variables
    int SIZE = 5;
    string sName[SIZE] = {"mild","medium","sweet","hot","zesty"};
    int sSold[SIZE] = {};
    int high, h;
    int low, l;
    //Prompt for input
    cout<<"Enter sales for all 5 salsa types."<<endl;
    for (int i=0; i<SIZE; i++){
        cout<<setw(7)<<sName[i]<<" = ";
        cin>>sSold[i];
    }
    cout<<endl;
    //Output Sales
    cout<<"Salsa Sales:"<<endl;
    for (int i=0; i<SIZE; i++){
        cout<<setw(7)<<sName[i]<<" = "<<sSold[i]<<endl;
    }
    cout<<endl;
    //Find highest and lowest sales
    high = sSold[0];
    low = sSold[0];
    for (int i=0; i<SIZE; i++){
        if (sSold[i] > high) {
            high = sSold[i];
            h=i;
        }
        if (sSold[i] < low) {
            low = sSold[i];
            l=i;
        }
    }
    //Output highest and lowest sales
    cout<<"The highest sales are "<<sName[h]<<" salsa, at "<<sSold[h]<<" sales."<<endl;
    cout<<"The lowest sales are "<<sName[l]<<" salsa, at "<<sSold[l]<<" sales."<<endl;
    cout<<endl;
}

//*******************         Problem 3           ********************/
void problem3(){
//Declare Variables
    string weekday[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    string mName[3] = {"Jimbo","Kong","Ceaser"};
    int monkey[3][7] = {};
    float average;
    int high, hName, hFood;
    int low, lName, lFood;
    //Collect food eaten for the week
    for (int i=0; i<3; i++){
        cout<<mName[i]<<endl;
        for (int u=0; u<7; u++){
            cout<<setw(9)<<weekday[u]<<" : ";
            cin>>monkey[i][u];
            while (monkey[i][u]<0){
                cout<<"Invalid Input. Enter a positive number. ";
                cin>>monkey[i][u];
            }
        }
        cout<<endl;
    }
    //Calculate Average
    for (int i=0; i<3; i++){
        for (int u=0; u<7; u++){
            average += monkey[i][u];
        }
    }
    average /= 7;
    //Find most and least food eaten
    high = monkey[0][0];
    hName = 0;
    hFood = 0;
    low = monkey[0][0];
    lName = 0;
    lFood = 0;
    for (int i=0; i<3; i++){
        for (int u=0; u<7; u++){
            if (monkey[i][u]>high){
                high = monkey[i][u];
                hName = i;
                hFood = u;
            }
            if (monkey[i][u]<low){
                low = monkey[i][u];
                lName = i;
                lFood = u;
            }
        }
    }
    //Output average, high, and low
    cout<<mName[hName]<<" ate the most food ("<<monkey[hName][hFood]<<" lbs) on "<<weekday[hFood]<<"."<<endl;
    cout<<mName[lName]<<" ate the least food ("<<monkey[lName][lFood]<<" lbs) on "<<weekday[lFood]<<"."<<endl;
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"The monkey family ate an average of "<<average<<" lbs of food per day."<<endl;
    cout<<endl;
}

//*******************         Problem 4           ********************/
void problem4(){
    //Initialize the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    int nMonths = 3; //Three months
    int days = 30; //Only collect for 30 days of each month
    char forcast[nMonths][days] = {}; //Array to store forecast
    int weather;
    int sCount[nMonths] = {}; //Sunny day counter
    int cCount[nMonths] = {}; //Cloudy day counter
    int rCount[nMonths] = {}; //Rainy day counter
    int sTotal = 0; //Total sunny days
    int cTotal = 0; //Total cloudy days
    int rTotal = 0; //Total rainy days
    int rHigh; //Highest rainy month
    int rLow; //Lowest rainy month
    short hMonth, lMonth;
    string month[nMonths] = {"June","July","August"};
    //Load random weather data for each day
    for (int i=0; i<nMonths; i++){
        cout<<month[i]<<":"<<endl;
        for (int u=0; u<days; u++){
            weather = (rand()%3);
            if (weather == 0){
                forcast[i][u] = 'S';
                cout<<"Day "<<setw(2)<<u+1<<" : ";
                cout<<forcast[i][u]<<endl;
                sCount[i] += 1;
            }
            else if (weather == 1){
                forcast[i][u] = 'C';
                cout<<"Day "<<setw(2)<<u+1<<" : ";
                cout<<forcast[i][u]<<endl;
                cCount[i] += 1;
            }
            else if (weather == 2){
                forcast[i][u] = 'R';
                cout<<"Day "<<setw(2)<<u+1<<" : ";
                cout<<forcast[i][u]<<endl;
                rCount[i] += 1;
            }
            else forcast[i][u] = 'E';
        }
        cout<<endl;
    }
    //Add weather type totals
    for (int i=0; i<nMonths; i++){
        sTotal += sCount[i];
        cTotal += cCount[i];
        rTotal += rCount[i];
    }
    //Determine month with highest days of rain
    rHigh = rCount[0];
    hMonth = 0;
    if (rCount[1]>rHigh){
        rHigh = rCount[1];
        hMonth = 1;
    }
    else if (rCount[2]>rHigh){
        rHigh = rCount[2];
        hMonth = 2;
    }
    //Determine month with lowest days of rain
    rLow = rCount[0];
    lMonth = 0;
    if (rCount[1]<rLow){
        rLow = rCount[1];
        lMonth = 1;
    }
    else if (rCount[2]<rLow){
        rLow = rCount[2];
        lMonth = 2;
    }
    //Output totals for all three months
    cout<<"The three month period contained "<<sTotal<<" sunny days, "<<cTotal;
    cout<<" cloudy days, "<<rTotal<<" rainy days."<<endl<<endl;
    //Output months with the most and least rainy days
    cout<<month[hMonth]<<" had the highest number of rainy days ("<<rCount[hMonth]<<")."<<endl;
    cout<<month[lMonth]<<" had the lowest number of rainy days ("<<rCount[lMonth]<<")."<<endl<<endl;
    //Output totals for each day of each month
    for (int i=0; i<nMonths; i++){
            cout<<month[i]<<":"<<endl;
            cout<<setw(3)<<sCount[i]<<" sunny day(s)"<<endl;
            cout<<setw(3)<<cCount[i]<<" cloudy day(s)"<<endl;
            cout<<setw(3)<<rCount[i]<<" rainy day(s)"<<endl<<endl;
    }
}

//*******************         Problem 5           ********************/
void problem5(){
    //Declare Variables
    short SIZE = 5;
    short same;
    int lottery[SIZE] = {};
    int player[SIZE] = {};
    //Initialize the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Set lottery numbers
    for (int i=0; i<SIZE; i++){
        lottery[i] = (rand()%10);
    }
    //Prompt for user input
    cout<<"Enter 5 single digit lottery numbers, pressing enter after each digit."<<endl;
    for (int i=0; i<SIZE; i++){
        cin>>player[i];
        while (player[i]<0 || 9<player[i]){
            cout<<"Invalid Input. Enter 0-9"<<endl;
            cin>>player[i];
        }
    }
    //Compare both arrays and count similar elements
    for (int i=0; i<SIZE; i++){
        if (lottery[i]==player[i]){
            same += 1;
        }
    }
    //Output Results
    cout<<endl;
    cout<<"*****************************"<<endl;
    cout<<"*Lottery";
    for (int i=0; i<SIZE; i++){
        cout<<"* "<<lottery[i]<<" ";
    }
    cout<<"*"<<endl;
    cout<<"*****************************"<<endl;
    cout<<"*Player ";
    for (int i=0; i<SIZE; i++){
        cout<<"* "<<player[i]<<" ";
    }
    cout<<"*"<<endl;
    cout<<"*****************************"<<endl;
    cout<<endl;
    cout<<"You have "<<same<<" matching element(s)."<<endl;
    cout<<endl;
}

//*******************         Problem 6           ********************/
void problem6(){
    
}

//*******************         Problem 7           ********************/
void problem7(){
    
}

//*******************         Problem 8           ********************/
void problem8(){
    
}

//*******************         Problem 9           ********************/
void problem9(){
    
}

int countPerfect(int scores[], int SIZE){
    //Declare Variables
    int sCount = 0;
    //Count perfect scores
    for (int i=0; i<SIZE; i++){
        if (scores[i]==100) {sCount += 1;}
    }
    return sCount;
}