#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Date {
public:
  Date(int y): year(y), month(1), day(1){}
  Date(int y, int m): year(y), month(m), day(1){}
  Date(int y, int m, int d): year(y), month(m), day(d){}
  Date& addMonths(int n){
    year  += (month + n) / 12;
    month = (month + n) % 12;
    return *this;
  }

  Date& addDays(int n) {
    int d = daysToDate() + n;
    int y = year, m = 1;
    while(d > daysInMonth(y, m)){
      d -= daysInMonth(y, m);
      m++;
      if(m > 12){
        m = 1;
        y++;
      }
    }
    day = d;
    month = m;
    year = y;

    return *this;
  }

  static bool isLeapYear(int y) {
    return (y % 4 || (y % 100 == 0 && y % 400)) ? false : true;
  }

  string toString() const{
    string output = "";
    switch(month){
      case 1:output += "Jan ";break;
      case 2:output += "Feb ";break;
      case 3:output += "Mar ";break;
      case 4:output += "Apr ";break;
      case 5:output += "May ";break;
      case 6:output += "Jun ";break;
      case 7:output += "Jul ";break;
      case 8:output += "Aug ";break;
      case 9:output += "Sep ";break;
      case 10:output += "Oct ";break;
      case 11:output += "Nov ";break;
      case 12:output += "Dec ";break;
    }
    output += to_string(day);
    output += ", ";
    output += to_string(year);
    return output;
  }

  int daysToDate(){
    int days_in_month[]{31, isLeapYear(year) ? 29 : 28, 31,
                        30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;
    for(int m = 0; m < month - 1; m++){
      days += days_in_month[m];
    }
    days += day;
    return days;
  }

  Date operator+(int n){
    addDays(n);
    return *this;
  }

  friend ostream& operator <<(ostream & out, const Date & d){
    string blah = d.toString();
    out << blah;
    return out;
  }


private:
  int year, month, day;

  static int daysInMonth(int y, int m){
    int days_in_month[]{31, isLeapYear(y) ? 29 : 28, 31,
                        30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days_in_month[m - 1];
  }
};
