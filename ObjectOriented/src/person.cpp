#include "person.h"

person::person(string nameP, string addressP, BloodGroup bloodGroupP, Date DOBP)
{
	name = nameP;
	address = addressP;
	bloodGroup = bloodGroupP;
	DOB = DOBP;
	password = "password";
}

bool person::authenticate()
{
	cout<<"Enter password:";
	string enteredPassword;
	system("stty -echo");
	cin>>enteredPassword;
    system("stty echo");
	if(enteredPassword == password)
		return true;
	else 
		return false;
}
