/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on April 10, 2015, 5:02 PM
 *      Purpose: Membership Fee Increase
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
        int n;
        float cost = 2500, inc = 1.04;
    //Input
        cout<<fixed<<showpoint<<setprecision(2);
    //Loop
        for (n=1; n<=6; n++){
            cost*=inc;
            cout<<"Year: "<<n<<" Cost: "<<cost<<endl;
    }
    //Executio Incipio
    return 0;
}

