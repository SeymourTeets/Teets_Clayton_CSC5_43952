/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 25, 2015, 2:18 PM
 * Purpose    : Number Guessing Game
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Output Formatting
#include <ctime>
#include <cstdlib>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio

int main(int argc, char** argv) {
    //Initialize Random number seed
    srand(static_cast<unsigned int> (time(0)));
    //Declare Variables
    int number = rand() % 100 + 1;
    int guess;
    int tries = 0;
    bool correct = false;
    //Prompt for input
    cout << "Let's play a guessing game!" << endl;
    cout << "I've chosen a number between 1 and 100." << endl;
    do {
        cout << "What number am I thinking of? ";
        cin>>guess;
        while (guess < 0 || 100 < guess) {
            cout << "Invalid Input. Enter your guess : ";
            cin>>guess;
        }
        if (number == guess) {
            cout << "That's correct!" << endl;
            correct = true;
        } else if (number < guess) {
            cout << "Too high, guess something lower." << endl;
        } else {
            cout << "Too low, guess something higher." << endl;
        }
        tries += 1;
    } while (!correct);
    cout << endl << "It took " << tries << " tries to guess " << number << "!" << endl;
    //Executio Disicere
    return 0;
}
