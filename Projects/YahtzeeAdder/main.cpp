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
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Executio Incipio

int values[] = { 40, 10, 100, 90, 20, 25 };

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(int argc, char** argv) {
    //Declare Variables
        const int SIZE = 6;
        int die[SIZE] = {};//Yahtzee die
    for (int c=1; c<=10; c++) {
    //Loop for Die Roll
        for (int i=1; i<6; i++){
        die[i] = rand()%6+1;
        }
  qsort (die, 6, sizeof(int), compare);

  return 0;
}
