#ifndef PERSON_H
#define PERSON_H

#include "IITM_global.h"
#include "utils.h"

#include <termios.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
class person 
{
public:
	person(){password="password";}
    person(string nameP, string addressP, BloodGroup bloodGroupP, Date DOBP);
	string getName(){return name;}
	string getAddress(){return address;}
	BloodGroup getBlodGroup(){return bloodGroup;}
	Date getDateOfBirth(){return DOB;}
	void resetPassword()
	{
		for(int i=0;i<3;i++){
			cout<<"Enter old password\n";
			string oldp;
			cin>>oldp;
			if(oldp == password)
			{
				cout<<"Enter new password\n";
				cin>>password;
				return;
			}
			cout<<"Error, try again\n";
		}
		cout<<"Sorry, authentication failure, try again later\n";
	}
	bool authenticate();

protected:
    string name;
    string address;                 // Permanent Address
    BloodGroup bloodGroup;
    Date DOB;
	string password;
};

#endif // PERSON_H
