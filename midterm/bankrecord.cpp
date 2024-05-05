#include "bankrecord.h"
using namespace std;

BankRecord::BankRecord()
{
    customerName = "";
    customerID = 0;
    numAccounts = 0;
    branchName = "";
}

BankRecord::BankRecord(string name, int id, int amount, string branch)
{
    customerName = name;
    customerID = id;
    numAccounts = 0;
    branchName = branch;
}

string BankRecord::getCustomerName()
{
    return customerName;
}

int BankRecord::getCustomerID()
{
    return customerID;
}

int BankRecord::getNumAccounts()
{
    return numAccounts;
}

string BankRecord::getBranchName()
{
    return branchName;
}

void BankRecord::print()
{
    cout << "Customer Name: " << getCustomerName() << endl;
    cout << "Customer ID (Amount): " << getCustomerID() << endl;
    cout << "Amounts: " << getNumAccounts() << endl;
    cout << "Branch Name: " << getBranchName() << endl;
}

bool BankRecord::operator<(BankRecord other)
{
    if (numAccounts < other.numAccounts)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool BankRecord::operator>(BankRecord other)
{
    if (numAccounts > other.numAccounts)
    {
        return true;
    }
    else
    {
        return false;
    }
}
