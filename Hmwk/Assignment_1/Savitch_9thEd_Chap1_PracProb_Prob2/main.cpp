
/* 
 * File:   main.cpp
 * Author: Clayton Teets
 * Created on March 9, 2015, 1:09 PM
 *      Purpose: Sample 1.8 Add Hello/Goodbye
 */
    #include <iostream>
      using namespace std;
      int main( )
      //Executio Incipio
      {
         //Declare Variables
            int number_of_pods, peas_per_pod, total_peas;
         //Prompt user for Input
            cout<<"Hello!\n";
            cout << "Press return after entering a number.\n";
            cout << "Enter the number of pods:\n";
            cin >> number_of_pods;
            cout << "Enter the number of peas in a pod:\n";
            cin >> peas_per_pod;
         //Calculate
            total_peas = number_of_pods * peas_per_pod;
         //Output results
            cout << "If you have ";
            cout << number_of_pods;
            cout << " pea pods\n";
            cout << "and ";
            cout << peas_per_pod;
            cout << " peas in each pod, then\n";
            cout << "you have ";
            cout << total_peas;
            cout << " peas in all the pods.\n";
            cout<<"Good-Bye.\n";
         //Executio Disicere
         return 0;
     }
