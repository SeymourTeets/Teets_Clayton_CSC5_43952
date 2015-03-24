/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on March 23, 2015, 5:59 PM
 *      Purpose: Software Sales
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
    unsigned char bCost = 99;//Standard price of the software
    unsigned int quant;//Quantity of purchases
    float price;//Total price
    //Prompt for units purchased
    cout<<"Given the quantity of units purchased, I will determine the final cost "
        <<"of the purchase and notify you of the bulk discount received (if available)"<<endl;
    cout<<"Enter quantity of purchased units: ";
    cin>>quant;
    //Specify 2 decimal points for dollars and cents
    cout<<fixed<<showpoint<<setprecision(2);
    //Determine final price
    if ((quant >= 0)&&(quant <= 9)){
        price = bCost * quant;
        cout<<"You did not receive a discount and the total price is $"<<price<<endl;
    }
    else if ((quant >= 10)&&(quant <= 19)){
        price = (bCost * .8f) * quant;
        cout<<"You received a discount of 20% and the total price is $"<<price<<endl;
    }
    else if ((quant >= 20)&&(quant <= 49)){
        price = (bCost * .7f) * quant;
        cout<<"You received a discount of 30% and the total price is $"<<price<<endl;
    }
    else if ((quant >= 50)&&(quant <= 99)){
        price = (bCost * .6f) * quant;
        cout<<"You received a discount of 40% and the total price is $"<<price<<endl;
    }
    else if (quant >= 100){
        price = (bCost * .5f) * quant;
        cout<<"You received a discount of 50% and the total price is $"<<price<<endl;
    }
    return 0;
}

