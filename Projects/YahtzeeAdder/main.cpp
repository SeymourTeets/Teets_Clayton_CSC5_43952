/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 9, 2015, 5:40 PM
 * Purpose    : 
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Output Formatting
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort */
#include <fstream>
#include <string>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio

int main(int argc, char** argv) {
    int hScore, score = 70;
    string hName;
    string name = "Rick";
    ifstream high;
    high.open("highscore.txt");
    high >> hScore >> hName;
    cout << hScore << endl;
    cout << hName << endl;
    high.close();
    if (hScore < score) {
        ofstream high;
        high.open("highscore.txt");
        high<<score<<endl;
        high<<name<<endl;
        high.close();
        
    }
  return 0;
}
