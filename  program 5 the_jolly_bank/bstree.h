/*
 * @Author: Hao Yang
 * @Date: 2021-11-26 16:34:09
 * @LastEditTime: 2021-12-15 19:11:30
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /342/bstree.h
 */
#ifndef BSTREE_H_
#define BSTREE_H_
#include <iostream>

#include "account.h"
using namespace std;

class BSTree {
 public:
  BSTree();
  ~BSTree();

  bool Insert(Acoount* acc);
  bool Retrieve(const int& AccountID, Acoount*& acc) const;
  void Display() const;
  void Empty();
  bool isEmpty() const;

 private:
  struct Node {
    Acoount* pAcc_;
    Node* right_;
    Node* left_;
  };
  Node* root_;
  bool recrusiveInsert(Acoount* acc, Node*& root);
  bool recrusiveRetrieve(int AccountID, Acoount*& acc, Node* root) const;
  void recrusiveDisplay(Node* root) const;
};

#endif