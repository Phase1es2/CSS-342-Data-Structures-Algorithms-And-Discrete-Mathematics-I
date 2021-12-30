#ifndef LIST_342_H_
#define LIST_342_H_

#include <fstream>
#include <iostream>
#include <ostream>
using namespace std;
template <class T>
class List342;

template <class T>
class List342 {
 public:
  List342();
  List342(const List342& list);  // copy constuctor
  List342(string file);
  ~List342();  // desttuctor

  bool BuildList(string file_name);
  bool Insert(T* obj);
  bool Remove(T target, T& result);
  bool Peek(T target, T& result) const;
  bool isEmpty() const;
  void DeleteList();
  bool Merge(List342<T>& list1);

  // Put the ostream outside the class function cus error.
  // According to
  // https://stackoverflow.com/questions/13516720/where-to-put-overload-code
  friend ostream& operator<<(ostream& out_stream, const List342<T>& list) {
    Node* curr = list.head_;
    while (curr != nullptr) {
      out_stream << *curr->data;
      curr = curr->next;
    }
    return out_stream;
  }

  List342<T> operator+(const List342<T>& list) const;
  List342<T>& operator+=(const List342<T>& list);
  bool operator==(const List342<T>& list);
  bool operator!=(const List342<T>& list);
  List342<T>& operator=(const List342<T>& list);

 private:
  struct Node {
    /*
    T* data;
    data = nullptr;
    Node* next;
    next = nullptr;*/
    // Zero is an invalid address. A pointer variable equal to null with address
    // null means that the pointer variable variable does not point to a valid
    // memory location.
    T* data = nullptr;
    Node* next = nullptr;
  };
  Node* head_;
};
#endif  // !LIST_342_H_

template <class T>
inline List342<T>::List342() : head_(nullptr) {}

template <class T>
inline List342<T>::List342(const List342& list) : head_(nullptr) {
  *this = list;
}

template <class T>
inline List342<T>::List342(string file) {
  BuildList(file);
}

template <class T>
inline List342<T>::~List342() {
  DeleteList();
};

template <class T>
inline bool List342<T>::BuildList(string file_name) {
  ifstream in_file;
  in_file.open(file_name);
  if (in_file.is_open()) {
    while (!in_file.eof()) {
      T* tmp = new T();
      in_file >> *tmp;
      Insert(tmp);  // insert the value from the list
      cout << "File found and insert, mission complete" << endl;
    }
    return true;
    in_file.close();
  } else {
    cout << "file cannot be found " << endl;
    return false;
  }
}

// 1) empty list
// 2) first in-line
// 3) check duplicate
// 4) all others
template <class T>
inline bool List342<T>::Insert(T* obj) {
  Node* ins_node = new Node;
  ins_node->data = obj;

  // check if the list is empty
  if (head_ == nullptr) {
    head_ = ins_node;
    return true;
  }
  // check if there are repeated value;
  Node* tmp = head_;
  while (tmp != nullptr) {
    if (*tmp->data == *obj)  // duplicate of an object are not allowed and
                             // hsould return flase.
    {
      return false;
      cout << "There is same object inside the list" << endl;
    } else {
      tmp = tmp->next;  // go to next value
    }
  }

  // Traverse rest of linked list
  Node* p_node = head_;
  if (head_ == nullptr || *head_->data > *ins_node->data) {
    if (*p_node->data == *obj) {
      return false;
      cout << "There is same object inside the list" << endl;
    } else {
      ins_node->next = head_;
      head_ = ins_node;
    }
  } else {
    if (*p_node->data == *obj) {
      return false;
      cout << "There is same object inside the list" << endl;
    }
    p_node = head_;
    while (p_node->next != nullptr && *p_node->next->data < *ins_node->data) {
      p_node = p_node->next;  // go to next value
    }
    ins_node->next = p_node->next;
    p_node->next = ins_node;
  }
  return true;
  /*
          while((p_node->next!=nullptr) && *(p_node->next->data) < *obj)
          {
                  p_node = p_node->next;
          }
          ins_node->next = p_node->next;
          p_node->next = ins_node;
  }
  return true;
  */
}

// Find the previous node of the node to be deleted.
// Change the next of the previous node.
// Free memory for the node to be deleted.
template <class T>
inline bool List342<T>::Remove(T target, T& result) {
  // check if the list is empty

  if (head_ == nullptr)  // if(isEmpty())
  {
    return false;
  }
  Node* tmp;
  // if the first in-line
  if (*head_->data == target) {
    tmp = head_;
    head_ = head_->next;
    result = *tmp->data;
    delete tmp;
    tmp = nullptr;
    return true;
  }

  // Traverse rest of linked list
  Node* p_node = head_;
  while (p_node->next != nullptr && *p_node->next->data < target) {
    p_node = p_node->next;  // go to next value
  }
  if (p_node->next == nullptr) {
    return false;
    cout << "cant find the target" << endl;
  }
  if (*p_node->next->data == target) {
    tmp = p_node->next;
    result = *tmp->data;
    p_node->next = p_node->next->next;
    // The correct way to delete pointer:
    // https://stackoverflow.com/questions/13223399/deleting-a-pointer-in-c
    delete tmp;     // freed memory
    tmp = nullptr;  // pointed dangling ptr to NULL
    return true;
  }
  return false;
}

template <class T>
inline bool List342<T>::Peek(T target, T& result) const {
  // check if the list is empty;
  if (head_ == nullptr) {
    return false;
  }

  // check the first in-line
  if (*head_->data == target) {
    result = *head_->data;
    return true;
  }

  Node* tmp = head_;
  while (tmp->next != nullptr && *tmp->next->data != target) {
    tmp = tmp->next;
  }

  if (tmp->next == nullptr) {
    return false;
    cout << "There is no repeat value in the list" << endl;
  } else  // find the value
  {
    Node* value = tmp->next;
    tmp->next = tmp->next->next;
    result = *value->data;
    return true;
  }
}

template <class T>
inline bool List342<T>::isEmpty() const {
  if (head_ == nullptr) {
    return true;
    cout << "The List342 is empty" << endl;
  } else {
    return false;
  }
}

template <class T>
inline void List342<T>::DeleteList() {
  // if the list is not empty keep delete until it is empty
  while (!(head_ == nullptr)) {
    Node* tmp = new Node;
    tmp = head_;
    head_ = head_->next;
    delete tmp;     // freed memory
    tmp = nullptr;  // pointed dangling ptr to NULL
  }
}

// Same like Leetcode 21. Merge Two Sorted Lists
// No dupicates are allowed
template <class T>
inline bool List342<T>::Merge(List342<T>& list1) {
  if (*this == list1) {
    return false;
    cout << "two list are the same" << endl;
  }

  Node* tmp = head_;
  // Traverse both list while both of them have nodes.
  while (list1.head_ != nullptr && tmp != nullptr) {
    if (tmp->next == nullptr) {
      tmp->next = list1.head_;
      list1.head_ = nullptr;
      return true;
    }
    // To check if there is any repeat value in the head.
    else if (*head_->data == *list1.head_->data) {
      Node* repaetV = list1.head_;
      list1.head_ = list1.head_->next;
      delete repaetV;
    } else if (*head_->data > *list1.head_->data) {
      head_ = list1.head_;
      list1.head_ = list1.head_->next;
      head_->next = tmp;
      tmp = head_;
    }
    // Delete the repeat value.
    else if (*tmp->next->data == *list1.head_->data) {
      Node* repeatV = tmp->next;
      repeatV = list1.head_;
      list1.head_ = list1.head_->next;
      delete repeatV;
    } else if (*tmp->next->data > *list1.head_->data) {
      Node* p_node = tmp->next;
      tmp->next = list1.head_;
      list1.head_ = list1.head_->next;
      tmp = tmp->next;
      tmp->next = p_node;
    } else {
      tmp = tmp->next;
    }
  }
  return true;
}

template <class T>
inline List342<T> List342<T>::operator+(const List342<T>& list) const {
  List342<T> list1 = *this;
  List342<T> list2 = list;
  list1.Merge(list2);
  return *this;
}

template <class T>
inline List342<T>& List342<T>::operator+=(const List342<T>& list) {
  List342<T> newList;
  newList = list;
  Merge(newList);
  return *this;
}

template <class T>
inline bool List342<T>::operator==(const List342<T>& list) {
  Node* lhs = head_;
  Node* rhs = list.head_;
  if (this->isEmpty() && list.isEmpty()) {
    return true;
  }
  while (lhs != nullptr && rhs != nullptr) {
    if (lhs->next == nullptr && rhs->next == nullptr) {
      return true;
    }
    if ((lhs->next != nullptr && rhs->next == nullptr) ||
        (lhs->next == nullptr && rhs->next != nullptr)) {
      return false;
    }
    lhs = lhs->next;
    rhs = rhs->next;
  }
  return false;
}

template <class T>
inline bool List342<T>::operator!=(const List342<T>& list) {
  if (*this == list) {
    return false;
  } else {
    return true;
  }
  // TODO: insert return statement here
}

// chain all member' assignment operator
// manage all d memory taht has been utilized
// return this.
template <class T>
inline List342<T>& List342<T>::operator=(const List342<T>& list) {
  T value = *list.head_->data;
  T result;

  while (Remove(value, result))
    ;
  // Check to see if assigning to ourselves and retur nis so
  if (this == &list) {
    return *this;
  }

  // if source stack is empty return;
  if (list.head_ == nullptr) {
    return *this;
  }
  Node* s_node;
  Node* ins_node;
  Node* d_node = new Node;

  // copy over first node
  d_node->data = (list.head_)->data;
  head_ = d_node;
  s_node = list.head_->next;
  // new points to last node in new list;
  // orig point to node in original list

  // loop and copy over all others nodes
  while (!(s_node == nullptr)) {
    ins_node = new Node;
    ins_node->data = s_node->data;  // copy the data
    d_node->next = ins_node;
    d_node = d_node->next;
    s_node = s_node->next;
  }
  return *this;
}
