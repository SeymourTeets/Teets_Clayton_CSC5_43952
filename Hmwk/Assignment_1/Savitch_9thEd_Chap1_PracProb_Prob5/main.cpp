/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on March 9, 2015, 1:09 PM
 *      Purpose: Area Calculator
 */
    #include <iostream>
      using namespace std;
      //Execution begins here
      int main( )
      {
         //Declare Variables
            int number_of_pods, peas_per_pod, total_peas;
         //Prompt for Input
            cout<<"Hello!\n";
            cout << "Press return after entering a number.\n";
            cout << "Enter the height:\n";
            cin >> number_of_pods;
            cout << "Enter the width:\n";
            cin >> peas_per_pod;
         //Calculate Area
            total_peas = number_of_pods * peas_per_pod;
         //Output the results
            cout << "If, the total height is:  ";
            cout << number_of_pods;
            cout << " feet\n";
            cout << "and the total width is: ";
            cout << peas_per_pod;
            cout<<" feet\n";
            cout << "Then, the total area is ";
            cout << total_peas;
            cout << " (feet*feet).\n";
            cout<<"Good-Bye.\n";
         //Execution Disicere
         return 0;
     }
