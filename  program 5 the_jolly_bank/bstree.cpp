/*
 * @Author: Hao Yang
 * @Date: 2021-11-26 16:33:59
 * @LastEditTime: 2021-12-15 21:15:52
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /342/bstree.cpp
 */
#include "bstree.h"

/**
 * @description:
 * @param {*}
 * @return {*}
 */
BSTree::BSTree() { root_ = nullptr; }

/**
 * @description:
 * @param {*}
 * @return {*}
 */
BSTree::~BSTree() {}

/**
 * @description:
 * @param {*}
 * @return {*}
 */
bool BSTree::recrusiveInsert(Acoount* acc, Node*& root) {
  if (root == nullptr) {
    root = new Node;
    root->pAcc_ = acc;
    root->left_ = nullptr;
    root->right_ = nullptr;
    return true;
  } else {
    if (root->pAcc_->getAccountID() > acc->getAccountID()) {
      if (root->left_ == nullptr) {
        Node* temp = new Node;
        temp->pAcc_ = acc;
        temp->left_ = nullptr;
        temp->right_ = nullptr;
        root->left_ = temp;
        return true;
      } else {
        return recrusiveInsert(acc, root->left_);
      }
    } else if (root->pAcc_->getAccountID() < acc->getAccountID()) {
      if (root->right_ == nullptr) {
        Node* temp = new Node;
        temp->pAcc_ = acc;
        temp->left_ = nullptr;
        temp->right_ = nullptr;
        root->right_ = temp;
        return true;
      } else {
        return recrusiveInsert(acc, root->right_);
      }
    } else {
      return false;
    }
  }
}

/**
 * @description:
 * @param {*}
 * @return {*}
 */
bool BSTree::Insert(Acoount* acc) { return recrusiveInsert(acc, root_); }

/**
 * @description:
 * @param {const} int
 * @return {*}
 */
bool BSTree::Retrieve(const int& AccountID, Acoount*& acc) const {
  if (root_ == nullptr) {
    return false;
  }
  return recrusiveRetrieve(AccountID, acc, root_);
}

/**
 * @description:
 * @param {int} AccountID
 * @return {*}
 */
bool BSTree::recrusiveRetrieve(int AccountID, Acoount*& acc, Node* root) const {
  if (root == nullptr) {
    acc = nullptr;
    return false;
  } else if (AccountID == root->pAcc_->getAccountID()) {
    acc = root->pAcc_;
    return true;
  } else if (AccountID < root->pAcc_->getAccountID()) {
    return recrusiveRetrieve(AccountID, acc, root->left_);
  } else {
    return recrusiveRetrieve(AccountID, acc, root->right_);
  }
}

/**
 * @description:
 * @param {*}
 * @return {*}
 */
void BSTree::Display() const {
  if (root_ != nullptr) {
    recrusiveDisplay(root_);
  }
}

/**
 * @description:
 * @param {*}
 * @return {*}
 */
void BSTree::recrusiveDisplay(Node* root) const {
  if (root != nullptr) {
    recrusiveDisplay(root->left_);
    cout << root->pAcc_->getFirstName() << " " << root->pAcc_->getLastName()
         << " Account ID: " << root->pAcc_->getAccountID() << endl;
    for (int i = 0; i < 8; i++) {
      cout << "  " << root->pAcc_->getFundtype(i) << ": $"
           << root->pAcc_->getBalance(i) << endl;
    }
    cout << endl;
    recrusiveDisplay(root->right_);
  }
}

/**
 * @description:
 * @param {*}
 * @return {*}
 */
void BSTree::Empty() {
  delete root_;
  root_ = nullptr;
}

/**
 * @description:
 * @param {*}
 * @return {*}
 */
bool BSTree::isEmpty() const { return root_ == nullptr; }
