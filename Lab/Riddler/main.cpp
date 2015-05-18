/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 18, 2015, 8:10 AM
 * Purpose    : 
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins here!
int main(int argc, char** argv) {
    //Loop for all possible digits
    //Defined as the method of exhaustion
    for(int d1000=0;d1000<=9;d1000++){//1000's digit
       for(int d100=0;d100<=9;d100++){//100's  digit
          for(int d10=0;d10<=9;d10++){//10's   digit
             for(int d1=0;d1<=9;d1++){//1's    digit
                if((d1000==3*d10)            && 
                   (d1%2==1   )              &&
                   ((d1000+d100+d10+d1)==27) &&
                   (d1!=d10&&d1!=d100&&d1!=d1000&&d10!=d100&&d10!=d1000&&d100!=d1000)){
                      cout<<"The Address Number = ";
                      cout<<d1000<<d100<<d10<<d1<<endl;
                }
             }
          }
       }
    }
    //Exit stage right
    return 0;
}
