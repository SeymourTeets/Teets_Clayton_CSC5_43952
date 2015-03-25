/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on March 24, 2015, 1:58 PM
 *      Purpose: Book Club Points
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
        unsigned short nBooks;//Number of books purchased this month
    //Prompt user for inputs
        cout<<"How many books did you purchase this month?"<<endl;
        cout<<"Enter number of books: ";
        cin>>nBooks;
    //Determine and output points received for the given month
        if (nBooks == 0)
            cout<<"You received 0 points this month."<<endl;
        else if (nBooks == 1)
            cout<<"You received 5 points this month."<<endl;
        else if (nBooks == 2)
            cout<<"You received 15 points this month."<<endl;
        else if (nBooks == 3)
            cout<<"You received 30 points this month."<<endl;
        else if (nBooks >= 4)
            cout<<"You received 60 points this month."<<endl;
    //Executio Disicere
    return 0;
}

