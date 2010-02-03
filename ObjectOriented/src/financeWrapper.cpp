#include "financeWrapper.h"

financeWrapper::financeWrapper()
{
}

void financeWrapper::payFees(string student, Fees fee)
{
    this->feesPaid[student].push_back(fee);
}
