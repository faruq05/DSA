// Abdullah Ibne Abbas Munna
#include <iostream>
#include "sortedtype.cpp"
#include "sortedtype.h"
#include "bankrecord.h"
#include "bankrecord.cpp"
using namespace std;

int main()
{
    SortedType<int> sortedList;
    sortedList.InsertItem(55);
    sortedList.InsertItem(66);
    sortedList.InsertItem(44);
    sortedList.InsertItem(22);
    sortedList.InsertItem(77);

    cout << "Sorted List of Integers:" << endl;
    int item;
    sortedList.ResetList();
    for (int i = 0; i < sortedList.LengthIs(); ++i)
    {
        sortedList.GetNextItem(item);
        cout << item << endl;
    }

    // bank task
    SortedType<BankRecord> customerList;

    BankRecord c1("Lionel Messi", 197131, 1000, "Buenos");
    BankRecord c2("Emiliano Martinez", 866437, 2000, "Rosan");
    BankRecord c3("Angel Di Maria", 538345, 3000, "Mendoz");
    BankRecord c4("Enzo Fernandez", 308974, 4000, "La Plata");
    BankRecord c5("Rodrigo De Paul", 375065, 5000, "Salta");

    customerList.InsertItem(c1);
    customerList.InsertItem(c2);
    customerList.InsertItem(c3);
    customerList.InsertItem(c4);
    customerList.InsertItem(c5);

    BankRecord customerRecord;
    cout << "Initial List of Customer Records:" << endl;
    customerList.ResetList();
    for (int i = 0; i < customerList.LengthIs(); i++)
    {
        customerList.GetNextItem(customerRecord);
        customerRecord.print();
    }

    SortedType<BankRecord> highAmountCustomers;
    customerList.ResetList();
    for (int i = 0; i < customerList.LengthIs(); ++i)
    {
        customerList.GetNextItem(customerRecord);
        if (customerRecord.getNumAccounts() > 3000)
        {
            highAmountCustomers.InsertItem(customerRecord);
        }
    }

    cout << "\nList of Customers with Amount > 3000:" << endl;
    highAmountCustomers.ResetList();
    for (int i = 0; i < highAmountCustomers.LengthIs(); ++i)
    {
        highAmountCustomers.GetNextItem(customerRecord);
        customerRecord.print();
    }

    return 0;
}
