#include "Queue.h"
#include "Person.h"
#include <iostream>
using namespace std;

main(){
  Queue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(4);
  queue.enqueue(3);
  queue.enqueue(5);
  cout << queue;
}
