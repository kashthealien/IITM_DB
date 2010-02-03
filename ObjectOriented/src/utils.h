#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <termios.h>

#include "IITM_global.h"

using namespace std;

inline static void horizLine()
{
	cout<<"________________________________________________________________________________\n\n";
}
int readInt(int & x);
int readFloat(float &y);
int readDate(Date &d);
int readFees(Fees &f);
bool checkdate(short d, short m, int y);

// Enumeration printing functions
void printENUM_BG();
void printENUM_DEPT();
void printENUM_HOS();
void printENUM_DEG();

#endif // UTILS_H
