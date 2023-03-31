#pragma once
#include "LinkedList.h"

template<typename Type>
class FifthElement:public LinkedList<Type>{
  public:
    FifthElement():LinkedList<Type>(){}
    Type getFifthElement();
    void insertNewFifthElement(const Type&value);
    void deleteFifthElement();
    void swapFourthAndFifthElement();
};

template<typename Type>
Type FifthElement<Type>::getFifthElement(){
  Type elem = LinkedList<Type>::peek(4);
  return elem;
}

template<typename Type>
void FifthElement<Type>::insertNewFifthElement(const Type&value){
  if(this->count < 4){
    LinkedList<Type>::insert(value);
  }
  auto temp = make_shared<Node<Type>>();
  temp->data = value;
  /*if(this->count == 4){
    this->back->data = value;
    this->back->next = nullptr;
  }*/
  int currNodeNum = 0;
  auto currentNode = this->front;
  while(currNodeNum != 3){
    currNodeNum++;
    currentNode = currentNode->next;
  }
  temp->next = currentNode->next;
  currentNode->next = temp;
}

template<typename Type>
void FifthElement<Type>::deleteFifthElement(){
  auto curNode = this->front;
  if(this->count == 5){
    while(curNode->next != this->back){
      curNode = curNode->next;
    }
    this->back = curNode;
    this->back->next = nullptr;
  }
  else if(this->count > 5){
    LinkedList<Type>::remove(4);
  }
  else{
    throw runtime_error("Out of Range");
  }
}

template<typename Type>
void FifthElement<Type>::swapFourthAndFifthElement(){
  auto curNode = this->front;
  auto temp = this->front->next;
  int nodeNum = 0;
  while(nodeNum < 2){
    nodeNum++;
    curNode = curNode->next;
    temp = temp->next;
  }
  auto fifth = temp->next;
  //curNode = 3 temp = 4
  temp->next = fifth->next;
  fifth->next = temp;
  curNode->next = fifth;

}
