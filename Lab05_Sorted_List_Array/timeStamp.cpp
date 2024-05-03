#include "timeStamp.h"
timeStamp::timeStamp() {
    seconds = 0;
    minutes = 0;
    hours = 0;
}

timeStamp::timeStamp(int h, int m, int s) {
    seconds = s;
    minutes = m;
    hours = h;
}

int timeStamp::getSeconds() {
    return seconds;
}

int timeStamp::getMinutes() {
    return minutes;
}

int timeStamp::getHours() {
    return hours;
}

void timeStamp::setSeconds(int s) {
    seconds = s;
}

void timeStamp::setMinutes(int m) {
    minutes = m;
}

void timeStamp::setHours(int h) {
    hours = h;
}


void timeStamp::print() {
//    cout << seconds << ":" << minutes << ":" << hours <<endl;
    cout << hours << ":" << minutes << ":" << seconds <<endl;
}

bool timeStamp::operator == (timeStamp t) {
    if ((seconds == t.seconds) && (minutes == t.minutes) && (hours == t.hours))
        return true;
    else
        return false;
}

bool timeStamp::operator != (timeStamp t) {
    if ((seconds != t.seconds) && (minutes != t.minutes) && (hours != t.hours))
        return true;
    else
        return false;
}

bool timeStamp::operator < (timeStamp t) {
    if ((hours < t.hours) || ((hours == t.hours) && (minutes < t.minutes)) || ((hours == t.hours) && (minutes == t.minutes) && (seconds < t.seconds)))
        return true;
    else
        return false;
}

bool timeStamp::operator > (timeStamp t) {
    if ((hours > t.hours) || ((hours == t.hours) && (minutes > t.minutes)) || ((hours == t.hours) && (minutes == t.minutes) && (seconds > t.seconds)))
        return true;
    else
        return false;
}


