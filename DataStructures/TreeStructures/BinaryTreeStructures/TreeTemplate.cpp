#include "TreeTemplate.h"
#include <iostream>
#include <queue>

template <typename Entry>
Binary_node<Entry>::Binary_node() {
  root = NULL;
}

template <typename Entry>
Binary_node<Entry>::Binary_node(const Entry& x) {
  data = x;
  left = NULL;
  right = NULL;
}

// Binary Tree

template <typename Entry>

Binary_tree<Entry>::Binary_tree() {
  root = NULL;
  treeSize = 0;
}

template <typename Entry>
bool Binary_tree<Entry>::empty() const {
  return root == NULL;
}

template <typename Entry>
int Binary_tree<Entry>::size() const {
  treeSize = 0;
  preorder(countNodes);
  return treeSize;
}

template <typename Entry>
void Binary_tree<Entry>::countNodes(const Binary_node<Entry>*& node) {
  if (node) treeSize++;
}

template <typename Entry>
void Binary_tree<Entry>::clear() {
  postorder(destroyNode);
}

template <typename Entry>
void Binary_tree<Entry>::destroyNode(Binary_node<Entry>* node) {
  if (node) delete node;
  node = NULL;
  return;
}

template <typename Entry>
int Binary_tree<Entry>::height() const {
  treeHeight = 0;
  preorder(countHeight);
}

template <typename Entry>
void Binary_tree<Entry>::countHeight(Binary_node<Entry>* node) {
  // TODO build this function
}

template <typename Entry>
void Binary_tree<Entry>::levelOrder(void (*visit)(Binary_node<Entry>*&)) {
  std::queue<struct Binary_node*> q;
  q.push(root);
  Binary_node<Entry> current;
  while (!q.empty()) {
    int q_size = q.size();
    for (int i = 0; i < q_size; i++) {
      current = q.front();
      visit(current->data) q.push(q.front()->left);
      q.push(q.front()->right);
    }
  }
}