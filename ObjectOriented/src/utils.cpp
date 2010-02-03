#include "utils.h"


bool checkdate(int d, int m, int y)
{
    //gregorian dates started in 1582
    if (! (1582<= y )  )
        return false;
    if (! (1<= m && m<=12) )
        return false;
    if (! (1<= d && d<=31) )
        return false;
    if ( (d==31) && (m==2 || m==4 || m==6 || m==9 || m==11) )
        return false;
    if ( (d==30) && (m==2) )
        return false;
    if ( (m==2) && (d==29) && (y%4!=0) )
        return false;
    if ( (m==2) && (d==29) && (y%400==0) )
        return true;
    if ( (m==2) && (d==29) && (y%100==0) )
        return false;
    if ( (m==2) && (d==29) && (y%4==0)  )
        return true;

    return true;
}

int readInt(int & num)
{
    int Integer = 0;
    
    while (!(cin >> Integer))
    {
        cin.clear();
        cout << "\t\tERROR: You must enter an integer\n";
		//remove the '\n'
		char ch;
		while ( cin.get ( ch ) && ch != '\n' );
	}
    num = Integer;
    return 1;
}
int readFloat(float & num)
{
    float Float = 0.0;
    while (!(cin>>Float))
    {
        cin.clear();
        cout << "\t\tERROR: You must enter a real number\n";
        char ch;
		while ( cin.get ( ch ) && ch != '\n' );
    }
    num = Float;
    return 1;
}

int readDate (Date & date)
{
    int dd, mm;
    int yyyy;
    readInt(dd);
	readInt(mm);
	readInt(yyyy);
	
    while (!checkdate(dd, mm , yyyy))
    {
        //cin.clear();
        // flushStream();
        cout << "\t\tERROR: You must enter a valid date\n";
		cin.clear();
		char ch;
		while ( cin.get ( ch ) && ch != '\n' );
        readInt(dd);
		readInt(mm);
		readInt(yyyy);
    }
	date = Date(dd,mm,yyyy);
	return 1;
}

int readFees(Fees &f)
{

    return 1;
}
void printENUM_BG()
{
	horizLine();
	cout<<"\t\tBlood Groups\n";
	horizLine();
    cout
    <<"Apos"<<" 0"<<'\n'
    <<"Aneg" <<" 1"<<'\n'
    <<"Bpos"<<" 2"<<'\n'
    <<"Bneg"<<" 3"<<'\n'
    <<"Opos"<<" 4"<<'\n'
    <<"Oneg"<<" 5"<<'\n'
    <<"ABpos"<<" 6"<<'\n'
    <<"ABneg"<<" 7"<<'\n'
    <<"UNKNOWN"<<" 8"<<endl;
}

void printENUM_DEPT()
{
	horizLine();
	cout<<"\t\tInstitue Departments\n";
	horizLine();
    cout
    <<"Aerospace"<<" 0"<<'\n'
    <<"Biotech"<<" 1"<<'\n'
    <<"Chemical"<<" 2"<<'\n'
    <<"Civil"<<" 3"<<'\n'
    <<"ComputerScience"<<" 4"<<'\n'
    <<"Electrical"<<" 5"<<'\n'
    <<"EngineeringPhysics"<<" 6"<<'\n'
    <<"Mechanical"<<" 7"<<'\n'
    <<"Metallurgical"<<" 8"<<'\n'
    <<"NavalArchitecture"<<" 9"<<'\n'
    <<"Humanities"<<" 10"<<'\n'
    <<"Physics"<<" 11"<<'\n'
    <<"Chemistry"<<" 12"<<'\n'
    <<"Mathematics"<<" 13"<<'\n'
    <<"Management"<<" 14"<<'\n'
    <<"UNKNOWN"<<" 15"<<endl;
}

void printENUM_HOS()
{
	horizLine();
	cout<<"\t\tInstitue Hostels\n";
	horizLine();
    cout
    <<"Tapti"<<" 0"<<'\n'
    <<"Ganga"<<" 1"<<'\n'
    <<"Jamuna"<<" 2"<<'\n'
    <<"Sharav"<<" 3"<<'\n'
    <<"Alakananda"<<" 4"<<'\n'
    <<"UNKNOWN"<<" 5"<<endl;
}

void printENUM_DEG()
{
	horizLine();
	cout<<"\t\tDegrees offered\n";
	horizLine();
    cout
    <<"BTech"<<" 0"<<'\n'
    <<"Dual"<<" 1"<<'\n'
    <<"MTech"<<" 2"<<'\n'
    <<"MSc"<<" 3"<<'\n'
    <<"Ph"<<" 4"<<'\n'
    <<"UNKNOWN"<<" 5"<<endl;
}
