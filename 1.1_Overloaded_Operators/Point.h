#pragma once
#include <iostream>
using std::ostream;
using std::istream;
using std::cout;
using std::endl;

template <class Type>
class Point;

template <class Type> 
ostream& operator << (ostream &, const Point<Type> &);

template <class Type>
istream& operator >> (istream &, Point<Type> &);

template <class Type>
class Point{
  public:
    Point<Type>(){x=0; y=0;}
    Point<Type>(Type x, Type y): x(x), y(y){}
    Point<Type> operator+(const Point<Type> &);
    Point<Type> operator +=(const Point<Type> &);
    Point<Type> operator-(const Point<Type> &);
    Point<Type> operator -=(const Point<Type> &);
    friend ostream& operator << <>(ostream &, const Point<Type> &);
    friend istream& operator >> <>(istream &, Point<Type> &);
  private:
    Type x;
    Type y;
};

template <class Type>
Point<Type> Point<Type>::operator+(const Point<Type> &toAdd){
  Point<Type> result(x+toAdd.x, y+toAdd.y);
  return result;
}

template <class Type>
Point<Type> Point<Type>::operator +=(const Point<Type> &toAdd){
  x += toAdd.x;
  y += toAdd.y;
  return *this;
}

template <class Type>
Point<Type> Point<Type>::operator-(const Point<Type> &toSubtract){
  Point<Type> result(x-toSubtract.x, y-toSubtract.y);
  return result;
}

template <class Type>
Point<Type> Point<Type>::operator -=(const Point<Type> &toSubtract){
  x -= toSubtract.x;
  y -= toSubtract.y;
  return *this;
}

template <class Type>
ostream& operator <<(ostream & out, const Point<Type> & output){
  out << "(" << output.x << ", " << output.y << ")";
  return out;
}

template <class Type>
istream& operator >>(istream & in, Point<Type> & input){
  cout << "Enter x and y coordinates" << endl;
  in >> input.x >> input.y;
  return in;
}
