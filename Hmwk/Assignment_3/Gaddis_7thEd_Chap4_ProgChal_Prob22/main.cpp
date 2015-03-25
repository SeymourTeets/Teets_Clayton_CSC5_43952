/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on March 24, 2015, 11:42 AM
 *      Purpose: Internet Service Provider
 */
//System Libraries
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio
int main(int argc, char** argv) {
    //Declare Variable
    ofstream out ;//Output to file
    float hours;//Hours online
    char package;//Package Subscription
    const int SIZE = 40;//Max name size is 39 characters
    char name[SIZE];//Customer name
    float bill;//Cable bill in $
    //Open File
    out.open("CableBill.txt");
    //Prompt for inputs
    cout<<"How many hours of internet did you view this month? "<<endl;
    cin>>hours;
    cout<<"What is you package? (A, B, or C) "<<endl;
    cin>>package;
    cout<<"What is the name of the customer? "<<endl;
    cin.ignore();
    cin.getline(name,SIZE);
    //Calculate Bill
    switch (package){
            case 'A':
            case 'a':{
                bill=9.95;
                if (hours > 10) bill += 2*(hours-10);
                break;
            }
            case 'B':
            case 'b':{
                bill=14.95;
                if (hours > 20) bill += (hours-20);
                break;
            }
            case 'c':
            case 'C':{
                bill=19.95;
                break;
            }
            
            default:
                cout<<"Invalid Input"<<endl;
    };
    //Output results to specified bill file
    out<<fixed<<setprecision(2)<<showpoint;
    out<<"Your Bill from 'The Cable Guy Inc.'\r\n"<<endl;
    out<<"Customer Name: "<<name<<"\r\n"<<endl;
    out<<"Package: "<<package<<"\r\n"<<endl;
    out<<"Hours Used: "<<hours<<"\r\n"<<endl;
    out<<"Amount Owed: $"<<bill<<"\r\n"<<endl;
    //Close file
    out.close();
    return 0;
}