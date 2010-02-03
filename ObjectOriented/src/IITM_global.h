#ifndef IITM_GLOBAL_H
#define IITM_GLOBAL_H

#include <string>
#include <iostream>
#include <termios.h>
using namespace std;

// Define types for readability

typedef string RollNum;
typedef string StaffId;
typedef string CourseId;

struct Date
{
    short int day;
    short int month;
    int year;
    Date()
    {
        day = 1;
        month = 1;
        year = 1950;
    }
    Date(short dayP, short monthP, short yearP)
    {
        day = dayP;
        month = monthP;
        year = yearP;
    }
		
};

struct Fees
{
    int mode;
    string chequeNo;
    string DDNo;
    Date datePaid;
    Fees()
    {
        mode = 1;
    }
};

enum BloodGroup {
    Apos,
    Aneg,
    Bpos,
    Bneg,
    Opos,
    Oneg,
    ABpos,
    ABneg,
    UNKNOWN_BG
};

enum Department {
    Aerospace,
    Biotech,
    Chemical,
    Civil,
    ComputerScience,
    Electrical,
    EngineeringPhysics,
    Mechanical,
    Metallurgical,
    NavalArchitecture,
    Humanities,
    Physics,
    Chemistry,
    Mathematics,
    Management,
    UNKNOWN_DEPT
};

enum Hostel{
    Tapti,
    Ganga,
    Jamuna,
    Sharav,
    Alakananda,
    UNKNOWN_HOS
};

enum Degree{
    BTech,
    Dual,
    MTech,
    MSc,
    PhD,
    UNKNOWN_DEG
};

enum Grade
{
    S,
    A,
    B,
    C,
    D,
    E,
    U,
    W,
    UNASSIGNED
};

#endif // IITM_GLOBAL_H
