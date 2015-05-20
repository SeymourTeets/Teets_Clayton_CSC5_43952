/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 19, 2015, 2:14 PM
 * Purpose    : 
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Output Formatting
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio

int main(int argc, char** argv) {
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
    //Executio Disicere
    return 0;
}
