/* 
 * File       : main.cpp
 * Author     : Clayton Teets
 * Created on : May 18, 2015, 8:07 AM
 * Purpose    : Erotosthenes Sieve
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void sieve(bool [],int);
void prntPrm(const bool [],int,int);
void initial(bool [],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables
    const int SIZE=2000001;
    bool prime[SIZE];
    //Initialize the array
    initial(prime,SIZE);
    //Perform the Sieve
    sieve(prime,SIZE);
    //Print the results
    prntPrm(prime,SIZE,6);
    //Exit Stage Right!!
    return 0;
}

void prntPrm(const bool primes[],int n,int perLine){
    //Print out only the prime numbers
    int nPrimes=0;
    for(int i=0;i<n;i++){
        if(primes[i]){
            cout<<setw(8)<<i;
            if(nPrimes%perLine==(perLine-1))cout<<endl;
            nPrimes++;
        }
    }
    cout<<endl<<"Total number of primes "
        <<"between 0 and "<<n-1<<" = "<<nPrimes<<endl;
}

void sieve(bool primes[],int n){
    //Outer loop to process the sieve
    for(int i=2;i<sqrt(n);i++){
        if(primes[i]){
            //Inner Loop of sieve
            for(int j=2*i;j<n;j+=i){
                primes[j]=false;
            }
        }
    }
}

void initial(bool primes[],int n){
    for(int i=0;i<n;i++){
        primes[i]=true;
    }
    primes[0]=false;
    primes[1]=false;
}