/* 
 * File:   Die.h
 * Author: Clayton
 *
 * Created on June 1, 2015, 9:43 AM
 */

#ifndef DIE_H
#define	DIE_H
#include <iostream>
using namespace std;

class Die {
private:
    unsigned short die[5];
    unsigned short counter;
public:
    void dev();
    unsigned short getDie(int i);
    void setDie(int hand[], int i);
    void setCount(int i);
    void roll();
    void printDie();
    void reRollset();
    bool getCount();
};

#endif	/* DIE_H */

