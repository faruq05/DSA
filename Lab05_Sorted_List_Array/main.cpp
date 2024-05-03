#include <iostream>
#include "sortedtype.cpp"
#include "timeStamp.h"
using namespace std;

//print function
template <class T>
void Print(SortedType<T> s){
    int length = s.LengthIs();
    T value;
    for(int i=0; i<length; i++){
        s.GetNextItem(value);
        cout<<value<<" ";
    }
    cout<<endl;
}

//retrieve function
template <class T>
void Retrieve(SortedType<T> s, T value){
    bool found;
    s.RetrieveItem(value, found);
    if(found){
        cout<<"Item "<<value<<" is found"<<endl;
    }else{
        cout<<"Item not found"<<endl;
    }
}

void fullCheck(bool check){
     if(check){
        cout<<endl<<"List is full"<<endl;
    }else{
        cout<<endl<<"List is not full"<<endl;
    }
}

int main()
{
    SortedType<int> st;
    //length of the list
    cout<<"Length of the list: "<<st.LengthIs()<<endl;
    //Insert
    st.InsertItem(5);
    st.InsertItem(7);
    st.InsertItem(4);
    st.InsertItem(2);
    st.InsertItem(1);
    //print list
    Print(st);
    //Retrieve 6, found or not
    Retrieve(st,6);
    //retrieve 5
    Retrieve(st,5);
    //full check
    fullCheck(st.IsFull());
    //delete 1
    st.DeleteItem(1);
    st.ResetList();
    cout<<"List after deleting 1: ";
    Print(st);
    fullCheck(st.IsFull());

//  timestamp task
    SortedType<timeStamp> stl;
    timeStamp t1(15,34,23);
    timeStamp t2(13,13,02);
    timeStamp t3(43,45,12);
    timeStamp t4(25,36,17);
    timeStamp t5(52,02,20);
    //insert timeStamp
    stl.InsertItem(t1);
    stl.InsertItem(t2);
    stl.InsertItem(t3);
    stl.InsertItem(t4);
    stl.InsertItem(t5);
    timeStamp t6;
    cout<<"The timeStamp list:"<<endl;
    for(int i=0 ; i<stl.LengthIs();i++)
    {
        stl.GetNextItem(t6);
        t6.print();
    }
    //delete 25, 36, 17
    stl.DeleteItem(t4);
    stl.ResetList();
    cout<<endl<<"The timeStamp list after deleting (25:36:17):"<<endl;
    for(int i=0 ; i<stl.LengthIs();i++)
    {
        stl.GetNextItem(t6);
        t6.print();
    }
    return 0;
}
