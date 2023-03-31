#pragma once
#include "Collection.h"

template<typename Item>
class SortedCollection:public Collection<Item>{
  public:
    SortedCollection():Collection<Item>(){}
    SortedCollection(int size):Collection<Item>(size){}
    SortedCollection(const SortedCollection<Item>&a):Collection<Item>(a){}
    virtual void add(Item num);
};

template<typename Item>
void SortedCollection<Item>::add(Item toAdd){
  Collection<Item>::add(toAdd);
  for(int i = this->curSize-1; i >= 0; i--){
    if(this->elements[i] > toAdd){
      this->elements[i+1] = this->elements[i];
      this->elements[i] = toAdd;
    }
    else if(this->elements[i] < toAdd){
      break;
    }
  }
}
