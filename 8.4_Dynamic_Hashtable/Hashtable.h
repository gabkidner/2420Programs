#pragma once
#include <memory>
#include <cmath>
#include <iostream>
using std::make_unique;
using std::unique_ptr;
using std::runtime_error;


template<class Type>
struct Bucket {
	Type data;
	bool empty = true;
};

template<class Type>
class Hashtable{
  public:
    Hashtable(){size = 0; capacity = 17; thresh = .65; htable = make_unique<Bucket<Type>[]>(capacity);}
    Hashtable(int cap){size = 0; capacity = cap; thresh = .65; htable = make_unique<Bucket<Type>[]>(capacity);}
    Hashtable(int cap, double thr){size = 0; capacity = cap; thresh = thr; htable = make_unique<Bucket<Type>[]>(capacity);}
    Hashtable(const Hashtable& other);
    Hashtable& operator=(const Hashtable<Type>& other);
    int getSize() const;
    int getCapacity() const;
    double getLoadFactorThreshold() const;
    bool empty() const;
    void insert(const Type item);
    void rehash();
    static bool isPrime(int number);
    static int nextPrime(int number);
    void remove(Type value);
    bool contains(Type value) const;
    int indexOf(Type value) const;
    void clear();
  private:
  	int hash(Type v) const;
    int capacity;
    int size;
    double thresh;
    unique_ptr<Bucket<Type>[]> htable;

};

template<class Type>
Hashtable<Type>::Hashtable(const Hashtable<Type>& other){
  capacity = other.capacity;
	size = other.size;
	htable = make_unique<Bucket<Type>[]>(capacity);
	for(int i = 0; i < capacity; i++){
		htable[i] = other.htable[i];
	}
}

template<class Type>
Hashtable<Type>& Hashtable<Type>::operator=(const Hashtable<Type>& other){
  capacity = other.capacity;
	size = other.size;
	htable = make_unique<Bucket<Type>[]>(capacity);
	for(int i = 0; i < capacity; i++){
		htable[i] = other.htable[i];
	}
	return *this;
}

template<class Type>
int Hashtable<Type>::hash(Type v) const {
	return fmod(v, capacity);
}

template<class Type>
int Hashtable<Type>::getSize() const{
  return size;
}

template<class Type>
int Hashtable<Type>::getCapacity() const{
  return capacity;
}

template<class Type>
double Hashtable<Type>::getLoadFactorThreshold() const{
  return thresh;
}

template<class Type>
bool Hashtable<Type>::empty() const{
  return size == 0;
}

template<class Type>
void Hashtable<Type>::insert(const Type value){
  if(size >= capacity){
    throw runtime_error("Hashtable Full");
  }
  int i = 0;
  while(!htable[hash(value + pow(i,2))].empty){
    i++;
  }
  htable[hash(value + pow(i,2))] = {value, false};
  size++;
  if((double)size/capacity > thresh){
    rehash();
  }
}

template<class Type>
void Hashtable<Type>::rehash(){
  int oldCap = capacity;
  capacity = nextPrime(capacity*2);
  unique_ptr<Bucket<Type>[]> temp;
  temp = make_unique<Bucket<Type>[]>(capacity);
  for(int i = 0; i < oldCap; i++){
    temp[i] = htable[i];
  }
  clear();
  htable = make_unique<Bucket<Type>[]>(capacity);
  for(int i = 0; i < capacity; i++){
    if(!temp[i].empty){
      insert(temp[i].data);
    }
  }
}

template<class Type>
bool Hashtable<Type>::isPrime(int number){
  if(number == 1 || number == 0){
    return false;
  }
  for(int i = number-1; i > 1; i--){
    if(fmod(number,i) == 0){
      return false;
    }
  }
  return true;
}

template<class Type>
int Hashtable<Type>::nextPrime(int number){
  for(int i = number; i < 100000000000000000; i++){
    if(isPrime(i)){
      return i;
    }
  }
  return -1;
}

template<class Type>
void Hashtable<Type>::remove(Type value){
  int i = 0;
	while(htable[hash(value+i)].data != value && i < capacity){
		i++;
	}
	if(i == capacity){
		return;
	}
	htable[hash(value+i)] = {0, true};
	size--;
}

template<class Type>
bool Hashtable<Type>::contains(Type value) const{
  int i = 0;
	while(htable[hash(value+i)].data != value && i < capacity){
		i++;
	}
	if(htable[hash(value+i)].data == value){
		return true;
	}
	return false;
}

template<class Type>
int Hashtable<Type>::indexOf(Type value) const{
  int i = 0;
  while(htable[hash(value+i)].data != value && i < capacity){
    i++;
  }
  if(htable[hash(value+i)].data == value){
    return hash(value+i);
  }
  else{
    return -1;
  }
}

template<class Type>
void Hashtable<Type>::clear(){
  size = 0;
	htable = make_unique<Bucket<Type>[]>(capacity);
}
