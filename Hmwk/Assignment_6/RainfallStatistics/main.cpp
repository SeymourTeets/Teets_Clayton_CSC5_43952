/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 21, 2015, 4:10 PM
 * Purpose    : Rainfall Statistics
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Output Formatting
#include <string>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes
float tRain(float[], const short);
float aRain(float[], const short);
int dMonth(float[], const short);
int wMonth(float[], const short);
//Executio Incipio

int main(int argc, char** argv) {
    //Declare Variables
    const short month= 12;
    float rain[month] = {};
    string mName[month] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    //Collect rainfall data for each month
    cout<<"Enter rainfall data, pressing enter after each month"<<endl;
    for (int i=0; i<month; i++){
        cout<<setw(9)<<mName[i]<<" : ";
        cin>>rain[i];
    }
    cout<<endl;
    //Output results
    cout<<"Rain Report For a Region In Severe Drought"<<endl;
    cout<<"Total rainfall           : "<<tRain(rain, month)<<" inches"<<endl;
    cout<<"Average monthly rainfall : "<<aRain(rain, month)<<" inches"<<endl;
    cout<<"The least rain fell in "<<mName[dMonth(rain, month)]<<" with "<<rain[dMonth(rain, month)]<<" inches."<<endl;
    cout<<"The most rain fell in "<<mName[wMonth(rain, month)]<<" with "<<rain[wMonth(rain, month)]<<" inches."<<endl;
    //Executio Disicere
    return 0;
}

float tRain(float rain[], const short month){
    cout<<fixed<<setprecision(2)<<showpoint;
    //Declare total variable for return
    float total = 0;
    //Calculate total rainfall
    for (int i=0; i<month; i++){
        total += rain[i];
    }
    return total;
}

float aRain(float rain[], const short month){
    cout<<fixed<<setprecision(2)<<showpoint;
    //Declare average variable for return
    float average = 0;
    //Add rainfall from each month
    for (int i=0; i<month; i++){
        average += rain[i];
    }
    //Divide by total of months to find average
    average /= month;
    return average;
}

int dMonth(float rain[], const short month){
    //Declare dry and dMonth variable for return
    float dry = rain[0];
    int dMonth = 0;
    //Determine the driest month
    for (int i=1; i<month; i++){
        if (rain[i]<dry){
            dry = rain[i];
            dMonth = i;
        }
    }
    return dMonth;
}

int wMonth(float rain[], const short month){
     //Declare dry and dMonth variable for return
    float wet = rain[0];
    int wMonth = 0;
    //Determine the driest month
    for (int i=1; i<month; i++){
        if (rain[i]>wet){
            wet = rain[i];
            wMonth = i;
        }
    }
    return wMonth;
}