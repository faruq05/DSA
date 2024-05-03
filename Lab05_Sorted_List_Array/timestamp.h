#ifndef TIMESTAMP_H_INCLUDED
#define TIMESTAMP_H_INCLUDED
#include<iostream>
using namespace std;
class timeStamp{
private:
    int seconds;
    int minutes;
    int hours;
public:
    timeStamp();
    timeStamp(int,int,int);
    int getSeconds();
    int getMinutes();
    int getHours();
    void setSeconds(int);
    void setMinutes(int);
    void setHours(int);
    bool operator == (timeStamp t);
    bool operator != (timeStamp t);
    bool operator > (timeStamp t);
    bool operator < (timeStamp t);
    void print();
};

#endif // TIMESTAMP_H_INCLUDED
