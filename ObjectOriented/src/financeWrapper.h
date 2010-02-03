#ifndef FINANCEWRAPPER_H
#define FINANCEWRAPPER_H

#include <string>
#include <list>
#include <map>
#include <string>
#include <map>
#include <termios.h>

#include "IITM_global.h"

class financeWrapper
{
public:
    financeWrapper();
    void payFees(string student, Fees fee);

private:
    map< string, list<Fees> > feesPaid;
};

#endif // FINANCEWRAPPER_H
