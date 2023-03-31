#pragma once
#include <iostream>
#include <string>
using namespace std;


class Person {
public:
  Person(string name, int amount) : name(name), amount(amount) {}
  bool operator>(const Person &g);
  bool operator ==(const Person &g);
  bool operator >=(const Person &g);
  bool operator <(const Person &g);
  bool operator <=(const Person &g);
  bool operator !=(const Person &g);
  int getAmount() const;
  friend bool operator >(int number, const Person &g);
  friend bool operator ==(int number, const Person &g);
  friend bool operator >=(int number, const Person &g);
  friend bool operator <(int number, const Person &g);
  friend bool operator <=(int number, const Person &g);
  friend bool operator !=(int number, const Person &g);
  friend ostream& operator <<(ostream &out, const Person &g);
private:
  string name;
  int amount;
};


bool Person::operator >(const Person &g) {
  return amount > g.amount;
}

bool Person::operator ==(const Person &g){
  return amount == g.amount;
}

bool Person::operator >=(const Person &g){
  return amount >= g.amount;
}

bool Person::operator <(const Person &g){
  return amount < g.amount;
}

bool Person::operator <=(const Person &g){
  return amount <= g.amount;
}

bool Person::operator !=(const Person &g){
  return amount != g.amount;
}

int Person::getAmount() const {
  return amount;
}

bool operator >(int number, const Person &g){
  return number > g.amount;
}

bool operator ==(int number, const Person &g){
  return number == g.amount;
}

bool operator >=(int number, const Person &g){
  return number >= g.amount;
}

bool operator <(int number, const Person &g){
  return number < g.amount;
}

bool operator <=(int number, const Person &g){
  return number <= g.amount;
}

bool operator !=(int number, const Person &g){
  return number != g.amount;
}

ostream& operator <<(ostream &out, const Person &g) {
  out << g.name << ": " << g.amount;
  return out;
}
