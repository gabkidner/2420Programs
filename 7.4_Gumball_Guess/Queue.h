#include <memory>
#include <iostream>
using std::shared_ptr;
using std::ostream;
using std::make_shared;
using std::runtime_error;

template<class Type>
struct Node{
	Node(Type data): data(data), next(nullptr){}
	Type data;
	shared_ptr<Node<Type>> next;
};

template<class Type>
class Queue;

template<class Type>
ostream &operator<<(ostream& out, const Queue<Type> &q);

template<class Type>
class Queue{
public:
  Queue();
  Queue(const Queue<Type> &q);
	Queue<Type> operator=(const Queue<Type>&q);
	void enqueue(Type data);
	Type peek();
	void dequeue();
	bool isEmpty();
	void clear();
	friend ostream& operator << <>(ostream& out, const Queue<Type> &q);
private:
  int cnt;
  shared_ptr<Node<Type>> front;
  shared_ptr<Node<Type>> back;
};

template<class Type>
Queue<Type>::Queue(){
  front = nullptr;
  back = nullptr;
  cnt = 0;
}

template<class Type>
Queue<Type>::Queue(const Queue<Type> &q){
	cnt = 0;
	auto temp = q.front;
	for(int i = 0; i < q.cnt; i++){
		enqueue(temp->data);
		temp = temp->next;
	}
}

template<class Type>
Queue<Type> Queue<Type>::operator=(const Queue<Type>&q){
	cnt = 0;
	auto temp = q.front;
	for(int i = 0; i < q.cnt; i++){
		enqueue(temp->data);
		temp = temp->next;
	}
	return *this;
}

template<class Type>
void Queue<Type>::enqueue(Type data){
	auto temp = make_shared<Node<Type>>(data);
	if(cnt == 0){
		front = temp;
		back = temp;
	}
	else{
		back->next = temp;
		back = back->next;
	}
	cnt++;
}

template<class Type>
Type Queue<Type>::peek(){
	if(cnt == 0){
		throw runtime_error("Empty Queue");
	}
	return front->data;
}

template<class Type>
void Queue<Type>::dequeue(){
	if(cnt == 0){
		throw runtime_error("Empty Queue");
	}
	front = front->next;
	cnt--;
}

template<class Type>
bool Queue<Type>::isEmpty(){
	return cnt == 0;
}

template<class Type>
void Queue<Type>::clear(){
	front = nullptr;
  back = nullptr;
  cnt = 0;
}

template<class Type>
ostream& operator << (ostream& out, const Queue<Type> &q){
	auto temp = q.front;
	while (temp) {
		out << temp->data;
		if (temp->next) out << " ";
		temp = temp->next;
	}
	return out;
}
