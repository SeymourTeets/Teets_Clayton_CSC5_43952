/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on March 16, 2015, 9:15 AM
 *      Purpose: Box Office
 */
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio
int main(int argc, char** argv) {
    //Declare Variables
        unsigned char aTketP, cTketP;//Child and adult ticket prices
        float gross, net, distPay;//Total and proportional pay
        float netP, distP;//Net and distributor payment percentages
        unsigned int tAtkts, tCtkts;//Value of child and adult tickets in $
        unsigned int nAtkts, nCtkts;//Number of child and adult tickets
        const unsigned short size = 35;
        char movName[size];
        aTketP = 6;
        cTketP = 3;
        netP = 2e-1;
        distP = 8e-1;
    //Prompt user for inputs
        cout<<"Please enter the name of the movie"<<endl;
        cin.getline(movName, size);
        cout<<"Enter the amount of adult tickets sold"<<endl;
        cin>>nAtkts;
        cout<<"Enter the amount of child tickets sold"<<endl;
        cin>>nCtkts;
    //Make calculation
        tAtkts=aTketP*nAtkts;//Value of adult sales
        tCtkts=cTketP*nCtkts;//Value of child sales
        gross=tAtkts+tCtkts;//Total ticket sales
        net=gross*netP;
        distPay=gross*distP;
    //Output Results
        cout<<fixed<<setprecision(2)<<showpoint;
        cout<<"Movie Name =                  "<<setw(9)<<movName<<endl;
        cout<<"Adult Tickets Sold =          "<<setw(9)<<nAtkts<<endl;
        cout<<"Child Tickets Sold =          "<<setw(9)<<nCtkts<<endl;
        cout<<"Gross Box Office Profit =    $"<<setw(9)<<gross<<endl;
        cout<<"Net Box Office Profit =      $"<<setw(9)<<net<<endl;
        cout<<"Amount Paid to Distributor = $"<<setw(9)<<distPay<<endl;
    return 0;
}

