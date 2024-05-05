#include <iostream>
#include "unsortedtype.cpp"
#include "unsortedtype.h"
#include "studentInfo.h"
#include "studentInfo.cpp"
using namespace std;

int main()
{
    //Create a list of integers
    UnsortedType <int> ut;
    //Insert four items
    ut.InsertItem(5);
    ut.InsertItem(7);
    ut.InsertItem(6);
    ut.InsertItem(9);
    //Print the list
    int input;
    for(int i=0; i<ut.LengthIs(); i++)
    {
        ut.GetNextItem(input);
        cout<<input<<" ";
    }
    //Print the length of the list
    cout<<endl<<"Length of the list is = "<<ut.LengthIs()<<endl;
    //Insert one item
    ut.InsertItem(1);
    //Print the list
    ut.ResetList();
    for(int i=0; i<ut.LengthIs(); i++)
    {
        ut.GetNextItem(input);
        cout<<input<<" ";
    }

    //Retrieve 4 and print whether found or not
    int a = 4;
    bool found;
    ut.RetrieveItem(a,found);
    if(found ){
        cout<<endl<<"Item "<<a<<" is found";
    }
    else{
        cout<<endl<<"Item is not found";
    }
    //Retrieve 5 and print whether found or not
    a = 5;
    //bool found;
    ut.RetrieveItem(a,found);
    if(found ){
        cout<<endl<<"Item "<<a<<" is found";
    }
    else{
        cout<<endl<<"Item is not found";
    }
    //Retrieve 9 and print whether found or not
    a = 9;
    //bool found;
    ut.RetrieveItem(a,found);
    if(found ){
        cout<<endl<<"Item "<<a<<" is found";
    }
    else{
        cout<<endl<<"Item is not found";
    }
    //Retrieve 10 and print whether found or not
    a = 10;
    // bool found;
    ut.RetrieveItem(a,found);
    if(found ){
        cout<<endl<<"Item "<<a<<" is found";
    }
    else{
        cout<<endl<<"Item is not found";
    }
    //Print if the list is full or not
    if(ut.IsFull()){
        cout<<endl<<"List is full";
    }
    else
    {
        cout<<endl<<"List is not full";
    }
    //Delete 5
    ut.DeleteItem(5);
    ut.ResetList();
    cout<<endl;
    for(int i=0; i<ut.LengthIs(); i++)
    {
        ut.GetNextItem(input);
        cout<<input<<" ";
    }

    //Print if the list is full or not
    if(ut.IsFull()){
        cout<<endl<<"List is full";
    }
    else
    {
        cout<<endl<<"List is not full";
    }
    //Delete 1
    ut.DeleteItem(1);
    //Print the list
    ut.ResetList();
    cout<<endl;
    for(int i=0; i<ut.LengthIs(); i++)
    {
        ut.GetNextItem(input);
        cout<<input<<" ";
    }
    //Delete 6
    ut.DeleteItem(6);
    //Print the list
    ut.ResetList();
    cout<<endl;
    for(int i=0; i<ut.LengthIs(); i++)
    {
        ut.GetNextItem(input);
        cout<<input<<" ";
    }
    cout<<endl;
    UnsortedType <StudentInfo> ut1;
    StudentInfo s1(15234,"Jhon",2.6);
    StudentInfo s2(13732,"Tyrion",3.9);
    StudentInfo s3(13569,"Sandor",1.2);
    StudentInfo s4(15467,"Ramsey 2",3.1);
    StudentInfo s5(16285,"Arya",3.1);

    ut1.InsertItem(s1);
    ut1.InsertItem(s2);
    ut1.InsertItem(s3);
    ut1.InsertItem(s4);
    ut1.InsertItem(s5);

    StudentInfo s6;
    //ut1.ResetList();
    for(int i=0 ; i<ut1.LengthIs();i++)
    {
        ut1.GetNextItem(s6);
        s6.print();
    }

    //delete 15467 id
    ut1.DeleteItem(s4);
    cout << "\nStudent Records (after deletion):\n";
    ut1.ResetList();
    for (int i = 0; i < ut1.LengthIs(); ++i) {
        ut1.GetNextItem(s6);
        s6.print();
    }


//    s3 retrieve
    ut1.RetrieveItem(s3, found);

    // Check if the item was found and print the result
    if (found) {
         cout << "Item " << s3.getId() <<  " is found\n";
    } else {
        cout << "Item " <<  " is not found\n";
    }

}


