/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 25, 2015, 1:53 PM
 * Purpose    : Characters for ASCII Codes
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Output Formatting
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio

int main(int argc, char** argv) {
    int count = 0;
    cout << "This will generate ASCII codes 32 through 127." << endl;
    for (int u = 32; u <= 127; u++) {
        char x = u;
        cout << x << " ";
        count += 1;
        if (count % 16 == 0) {
            cout << endl;
        }
    }
    //Executio Disicere
    return 0;
}
