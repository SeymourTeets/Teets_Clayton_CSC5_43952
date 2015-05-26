/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 25, 2015, 8:13 PM
 * Purpose    : Arrowhead Display
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
cout << "This program wil display an arrowhead on the screen.\n\n";

	// For first part
	for (int i = 0 ; i < 3 ; i++)
	{
		// For spaces
		int k = 0;
    
		while (k < 8)
		{
			cout << " ";
			k++; 
		}
		// For + sign
		for (int j = 0 ; j <= i ; j++)
		{
			cout << "+";
		}
		cout << endl;
	}
	// For second part
	for (int l = 0 ; l < 1 ; l++)
	{
		// For + sign
		for (int m = 0 ; m <= 11 ; m++)
		{
			cout << "+";
		}
		cout << endl;
	}
	// For third part
	for (int n = 3 ; n > 0 ; n--)
	{
		// For spaces
		int o = 8;

		while (o > 0)
		{
			cout << " ";
			o--;
		}
		// For + sign
		for (int p = n ; p > 0 ; p--)
		{
			cout << "+";
		}
		cout << endl;
	}
    //Executio Disicere
    return 0;
}
