#ifndef BANKRECORD_H_INCLUDED
#define BANKRECORD_H_INCLUDED
#include <string>
#include <iostream>
using namespace std;
class BankRecord
{
private:
    string customerName;
    int customerID;
    int numAccounts;
    string branchName;

public:
    BankRecord();
    BankRecord(string name, int id, int amount, string branch);

    string getCustomerName();
    int getCustomerID();
    int getNumAccounts();
    string getBranchName();

    void print();

    bool operator<(BankRecord other);
    bool operator>(BankRecord other);
};

#endif // BANKRECORD_H_INCLUDED
