#pragma once
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

template <class Type>
class Range;

template <class Type>
ostream& operator << (ostream &, const Range<Type> &);

template <class Type>
class Range{
    public:
      Range(Type start, Type end): start(start), end(end), step(1){}
      Range(Type start, Type end, Type step): start(start), end(end), step(step){}
      int length(){
        int l = 0;
        if(step > 0){
          for(Type i = start; i <= end; i = i + step){
            l++;
          }
          return l;
        }
        else{
          for(Type i = start; i >= end; i = i + step){
            l++;
          }
          return l;
        }
      }
      Type sum(){
        Type result = 0;
        if(step > 0){
          for(Type i = start; i <= end; i = i + step){
            result += i;
          }
        }
        else{
          for(Type i = start; i >= end; i = i + step){
            result += i;
          }
        }
        return result;
      }
      Type average(){
        Type l = length();
        Type result = sum() / l;
        return result;
      }
      Type min(){
        Type result = start;
        for(Type i = start + step; i >= end; i = i + step){
          if(i < result){
            result = i;
          }
        }
        return result;
      }
      Type max(){
        Type result = start;
        for(Type i = start + step; i <= end; i = i + step){
          if(i > result){
            result = i;
          }
        }
        return result;
      }
    friend ostream& operator << <>(ostream &, const Range<Type> &);
    private:
        Type start;
        Type end;
        Type step;
};

template <class Type>
ostream& operator << (ostream & out, const Range<Type> &r){
  if(r.step > 0){
    for(Type i = r.start; i <= r.end; i = i + r.step){
      out << i << " ";
    }
  }
  else{
    for(Type i = r.start; i >= r.end; i = i + r.step){
      out << i << " ";
    }
  }
  out << endl;
  return out;
}
