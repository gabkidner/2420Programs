#include "Hashtable.h"
#include <iostream>
using namespace std;

bool isPrime(int number);

main(){
  Hashtable<int> table;
  for(int i = 0; i < 100; i++){
    cout << i << " is ";
    if(table.isPrime(i)){
      cout << "Prime" << endl;
    }
    else{
      cout << "Not Prime" << endl;
    }
  }
}

bool isPrime(int number){
  for(int i = number-1; i > 1; i--){
    if(fmod(number,i) == 0){
      return false;
    }
  }
  return true;
}
