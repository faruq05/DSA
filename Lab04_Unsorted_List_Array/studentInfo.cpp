#include"studentInfo.h"

StudentInfo::StudentInfo()
{
    studentId = 0;
    studentName = "";
    studentCgpa = 0.0;
}

StudentInfo::StudentInfo(int n, string s, double d)
{
    studentId = n;
    studentName = s;
    studentCgpa = d;
}


void StudentInfo::setId(int id)
{
    studentId = id;
}

void StudentInfo::setName(string name)
{
    studentName = name;
}

void StudentInfo::setCgpa(double cgpa)
{
    studentCgpa = cgpa;
}

int StudentInfo::getId()
{
    return studentId;
}

string StudentInfo::getName()
{
    return studentName;
}

double StudentInfo::getCgpa()
{
    return studentCgpa;
}

void StudentInfo::print(){
cout<<getId()<<" "<<getName()<<" "<<getCgpa()<<endl;
}
bool StudentInfo::operator==(StudentInfo s) {
    if (studentId == s.studentId)
        return true;
    else
        return false;
}

bool StudentInfo::operator!=(StudentInfo s) {
    if (studentId != s.studentId)
        return true;
    else
        return false;
}
