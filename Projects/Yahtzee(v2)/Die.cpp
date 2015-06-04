#include "Die.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>

void Die::dev() {
    char x;
    cout << "How many die would you like to re roll? ";
    cin>>x;
    while (x != '1' && x != '2' && x != '3' && x != '4' && x != '5') {
        cout << "How many die would you like to re roll? ";
        cin>>x;
    }
    int y = x - 48;
    cout << endl;
    //Loop for die not held
    for (int i = 0; i <= y - 1; i++) {
        int c;
        cout << "Enter the die to re roll: ";
        cin>>c;
        cout << "Change to ";
        int z;
        cin>>z;
        die[c - 1] = z;
        cout << "Dice " << c;
        cout << " - |" << die[c - 1] << "|" << endl << endl;
    }
}

unsigned short Die::getDie(int i) {
    return die[i];
}

void Die::setCount(int i) {
    counter = i;
}

void Die::roll() {
    //Loop for Die Roll
    for (int i = 0; i < 5; i++) {
        do {
            die[i] = rand() % 6 + 1;
        } while (die[i] == 0);
    }
    counter += 1;
}

void Die::printDie() {
    //Output Die
    cout << "Your role:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Dice " << i + 1;
        cout << " - |" << die[i] << "|" << endl;
    }
    cout << endl;
}

void Die::reRollset() {
    char x;
    cout << "How many die would you like to re roll? ";
    cin>>x;
    while (x != '0' && x != '1' && x != '2' && x != '3' && x != '4' && x != '5') {
        cout << "How many die would you like to re roll? ";
        cin>>x;
    }
    int y = x - 48;
    cout << endl;
    //Loop for die not held
    for (int i = 0; i <= y - 1; i++) {
        int c;
        cout << "Enter the die to re roll: ";
        cin>>c;
        die[c - 1] = rand() % 6 + 1;
        cout << "Dice " << c;
        cout << " - |" << die[c - 1] << "|" << endl << endl;
    }
    counter += 1;
}

void Die::setDie(int hand[], int i) {
    die[i] = hand[i];
}

bool Die::getCount() {
    if (counter < 2) {
        return true;
    } else {
        return false;
    }
}