#ifndef STUDENTINFO_H_INCLUDED
#define STUDENTINFO_H_INCLUDED
//#include<string>
#include<iostream>
using namespace std;
class StudentInfo
{
private:
    int studentId;
    string studentName;
    double studentCgpa;
public:
    StudentInfo();
    StudentInfo(int, string, double);
    void setId(int);
    void setName(string);
    void setCgpa(double);
    int getId();
    string getName();
    double getCgpa();
    bool operator==(StudentInfo s);
    bool operator!=(StudentInfo s);
    void print();
};
#endif // STUDENTINFO_H_INCLUDED


