#pragma once
#include <stack>
#include <iostream>
using std::ostream;
using std::string;
using std::stack;
using std::cout;
using std::endl;

class BracketCheck{
  public:
    BracketCheck(string exp):expression(exp){}
    int numBrackets();
    bool isBalanced();
    friend ostream & operator <<(ostream &out, const BracketCheck &bc);
  private:
    string expression;
};

int BracketCheck::numBrackets(){
  stack<char> temp;
  for(char i:expression){
    if(i == '{' || i == '}' || i == '[' || i == ']' || i == '(' || i == ')'){
      temp.push(i);
    }
  }
  double number = temp.size()/2.0 + .5;
  return (int)number;
}

bool BracketCheck::isBalanced(){
  int tru = 0;
  stack<char> brackets;
  for(char i:expression){
    if(i == '{' || i == '[' || i == '('){
      brackets.push(i);
    }
    if(i == '}' || i == ']' || i == ')'){
      if(!brackets.empty()){
        if(brackets.top() == '{' && i == '}' || brackets.top() == '[' && i == ']' || brackets.top() == '(' && i == ')'){
          tru++;
        }
        else{
          return false;
        }
        brackets.pop();
      }
      else{
        return false;
      }
    }
  }
  int number = numBrackets();
  if(number == tru){
    return true;
  }
  return false;
}

ostream & operator <<(ostream &out, BracketCheck &bc){
  if(!bc.isBalanced()){
    out << "Not ";
  }
  out << "Balanced";
  return out;
}
