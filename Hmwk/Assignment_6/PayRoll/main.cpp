/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 21, 2015, 6:39 PM
 * Purpose    : Pay Roll
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Output Formatting
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio

class PayRoll {
private:
    float PayRate;
    float Hours;
public:

    void setPayRate(float i) {
        PayRate = i;
    }

    void setHours(float i) {
        Hours = i;
    }

    float getPayRate() {
        return PayRate;
    }

    float getHours() {
        return Hours;
    }

    float getGrossPay() {
        return PayRate * Hours;
    }
};

int main(int argc, char** argv) {
    //Declare how many times the program will loop
    short nPeople;
    cout << "Enter number of employees to collect payroll information for : ";
    cin>>nPeople;
    cout << endl;
    //Declare Variabes
    PayRoll person[nPeople]; //Declare object array for people
    float PayRate[nPeople], Hours[nPeople];
    //Collect PayRate and hours worked for each employee
    for (int i = 0; i < nPeople; i++) {
        cout << "Employee " << i + 1 << ":" << endl;
        cout << "Hours Worked : ";
        cin >> Hours[i];
        cout << "Pay Rate     : ";
        cin >> PayRate[i];
        cout << endl;
    }
    //Call member functions to set data
    for (int i = 0; i < nPeople; i++) {
        person[i].setHours(Hours[i]);
        person[i].setPayRate(PayRate[i]);
    }
    //Call Member Functions to Output Data
    cout << "PayRoll Data:" << endl << endl;
    for (int i = 0; i < nPeople; i++) {
        cout << "Employee " << i + 1 << ":" << endl;
        cout << "Hours     : " << person[i].getHours() << endl;
        cout << "Pay Rate  : " << person[i].getPayRate() << endl;
        cout << "Gross Pay : " << person[i].getGrossPay() << endl;
        cout << endl;
    }
    //Executio Disicere
    return 0;
}
