#include <iostream>
#include <memory>
using namespace std;

template <typename T>
struct Node {
  Node(T data): data(data), left(nullptr), right(nullptr){}
  T data;
  shared_ptr<Node<T>> left;
  shared_ptr<Node<T>> right;
};

template <typename T>
class BTree {
public:
  BTree():root(nullptr){}
  BTree(const BTree<T>&);
  BTree<T>& operator=(const BTree<T>&);
  void insert(const T& item);
  void preOrder();
  void inOrder();
  void postOrder();
  int nodeCount();
  int leavesCount();
  shared_ptr<Node<T>> find(const T& item);
  shared_ptr<Node<T>> findParent(shared_ptr<Node<T>> ptr);
  shared_ptr<Node<T>> findRightMostNode(shared_ptr<Node<T>> ptr);
  void remove(const T& item);
private:
  void preOrder(shared_ptr<Node<T>> ptr);
  void inOrder(shared_ptr<Node<T>> ptr);
  void postOrder(shared_ptr<Node<T>> ptr);
  void insert(const T& item,  shared_ptr<Node<T>> ptr);
  int nodeCount(shared_ptr<Node<T>> ptr);
  int leavesCount(shared_ptr<Node<T>> ptr);
  shared_ptr<Node<T>> copyNode(shared_ptr<Node<T>> ptr);
  shared_ptr<Node<T>> root;
  shared_ptr<Node<T>> find(const T& item, shared_ptr<Node<T>> ptr);
  shared_ptr<Node<T>> findParent(shared_ptr<Node<T>> childPtr, shared_ptr<Node<T>> ptr);
  void remove(shared_ptr<Node<T>> parent, shared_ptr<Node<T>> toBeRemoved);
};

template<typename T>
BTree<T>::BTree(const BTree<T>& b){
  root = copyNode(b.root);
}

template<typename T>
BTree<T>& BTree<T>::operator=(const BTree<T>&){
  return BTree(*this);
}

template<typename T>
shared_ptr<Node<T>> BTree<T>::copyNode(shared_ptr<Node<T>> ptr){
  if(ptr == nullptr){
    return nullptr;
  }
  auto ptrCopy = make_shared<Node<T>>(ptr->data);
  ptrCopy->left = copyNode(ptr->left);
  ptrCopy->right = copyNode(ptr->right);
  return ptrCopy;
}

template<typename T>
void BTree<T>::preOrder(){
  preOrder(root);
}

template<typename T>
void BTree<T>::preOrder(shared_ptr<Node<T>> ptr){
  if(ptr){
    cout << ptr->data << ' ';
    preOrder(ptr->left);
    preOrder(ptr->right);
  }
}

template<typename T>
void BTree<T>::insert(const T& item){
  if(root == nullptr){
    root = make_shared<Node<T>>(item);
  }
  else{
    insert(item, root);
  }
}

template<typename T>
void BTree<T>::insert(const T& item,  shared_ptr<Node<T>> ptr){
  if(item < ptr->data){
    if(ptr->left == nullptr){
      ptr->left = make_shared<Node<T>>(item);
    }
    else{
      insert(item, ptr->left);
    }
  }
  else{
    if(ptr->right == nullptr){
      ptr->right = make_shared<Node<T>>(item);
    }
    else{
      insert(item, ptr->right);
    }
  }
}

template<typename T>
int BTree<T>::nodeCount(){
  return nodeCount(root);
}

template<typename T>
int BTree<T>::nodeCount(shared_ptr<Node<T>> ptr){
  if(ptr){
    return 1 + nodeCount(ptr->left) + nodeCount(ptr->right);
  }
  return 0;
}

template<typename T>
void BTree<T>::postOrder(){
  postOrder(root);
}

template<typename T>
void BTree<T>::postOrder(shared_ptr<Node<T>> ptr){
  if(ptr){
    postOrder(ptr->left);
    postOrder(ptr->right);
    cout << ptr->data << ' ';
  }
}

template<typename T>
void BTree<T>::inOrder(){
  inOrder(root);
}

template<typename T>
void BTree<T>::inOrder(shared_ptr<Node<T>> ptr){
  if(ptr){
    inOrder(ptr->left);
    cout << ptr->data << ' ';
    inOrder(ptr->right);
  }
}

template<typename T>
int BTree<T>::leavesCount(){
  return leavesCount(root);
}

template<typename T>
int BTree<T>::leavesCount(shared_ptr<Node<T>> ptr){
  if(!ptr){
    return 0;
  }
  if(ptr->right != nullptr || ptr->left != nullptr){
    return leavesCount(ptr->left) + leavesCount(ptr->right);
  }
  if(ptr->right == nullptr && ptr->left == nullptr){
    return 1;
  }
  return 0;
}

template<typename T>
shared_ptr<Node<T>> BTree<T>::find(const T& item){
  return find(item, root);
}

template<typename T>
shared_ptr<Node<T>> BTree<T>::find(const T& item, shared_ptr<Node<T>> ptr){
  if(item < ptr->data){
    if(ptr->left != nullptr){
      return find(item, ptr->left);
    }
  }
  else if(item > ptr->data){
    if(ptr->right != nullptr){
      return find(item, ptr->right);
    }
  }
  else{
    return ptr;
  }
  return nullptr;
}

template<typename T>
shared_ptr<Node<T>> BTree<T>::findRightMostNode(shared_ptr<Node<T>> ptr){
  if(!ptr){
    return nullptr;
  }
  if(ptr->right == nullptr){
    return ptr;
  }
  return findRightMostNode(ptr->right);
}

template<typename T>
shared_ptr<Node<T>> BTree<T>::findParent(shared_ptr<Node<T>> ptr){
  return findParent(ptr, root);
}

template<typename T>
shared_ptr<Node<T>> BTree<T>::findParent(shared_ptr<Node<T>> childPtr, shared_ptr<Node<T>> ptr){
  if(ptr->left == childPtr || ptr->right == childPtr){
    return ptr;
  }
  else if(childPtr->data < ptr->data){
    if(ptr->left != nullptr){
      return findParent(childPtr, ptr->left);
    }
  }
  else if(childPtr->data > ptr->data){
    if(ptr->right != nullptr){
      return findParent(childPtr, ptr->right);
    }
  }
  else{
    return ptr;
  }
  return nullptr;
}

template<typename T>
void BTree<T>::remove(const T& item){
  auto child = find(item);
  remove(findParent(child), child);
}

template<typename T>
void BTree<T>::remove(shared_ptr<Node<T>> parent, shared_ptr<Node<T>> toBeRemoved){
  if(toBeRemoved->right != nullptr && toBeRemoved->left != nullptr){
    auto temp = findRightMostNode(toBeRemoved->left);
    if(temp != nullptr){
      T dta = temp->data;
      remove(temp->data);//Crashing
      toBeRemoved->data = dta;
    }
  }
  else if(toBeRemoved->left == nullptr){
    if(parent->right == toBeRemoved){
      parent->right = toBeRemoved->right;
    }
    else if(parent->left == toBeRemoved){
      parent->left = toBeRemoved->right;
    }
  }
  else if(toBeRemoved->right == nullptr){
    if(parent->right == toBeRemoved){
      parent->right = toBeRemoved->left;
    }
    else if(parent->left == toBeRemoved){
      parent->left = toBeRemoved->left;
    }
  }
  toBeRemoved = nullptr;
}
