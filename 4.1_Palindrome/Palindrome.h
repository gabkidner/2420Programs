#pragma once
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

class Palindrome{
  public:
    Palindrome(string sent) : sentence(sent){}
    bool isPalindrome() const;
    friend ostream &operator << (ostream &out, const Palindrome &p);
  private:
    string sentence;
    string stripSentece() const;
};

string Palindrome::stripSentece() const{
  string clean = "";
  for(char c : sentence){
    c = tolower(c);
    if(c >= 'a' && c <= 'z'){
      clean += c;
    }
  }
  return clean;
}

bool Palindrome::isPalindrome() const{
  string clean = stripSentece();
  stack<char>s;
  queue<char>q;
  for(char c:clean){
    s.push(c);
    q.push(c);
  }
  while(!s.empty()){
    if(s.top() != q.front()){
      return false;
    }
    s.pop();
    q.pop();
  }
  return true;
}

ostream &operator << (ostream &out, const Palindrome &p){
  out << p.sentence << " is ";
  if(!p.isPalindrome()){
    out << "not ";
  }
  out << "a palindrome.";
}
