#include <new>
#include <vector>

#include "BinaryTree.h"

// Constructor
jw::BinaryTree::BinaryTree() {
  this->root = nullptr;
}

// Destructor
jw::BinaryTree::~BinaryTree() {

}

// Insert new node into tree
void jw::BinaryTree::insert(double value) {
  if (this->root == nullptr) {  // If tree is empty
    try {
      root = new TreeNode(value, root, root);
    } catch (std::bad_alloc) {
      throw jw::BinaryTree::TreeMemError();
    }
  } else {  // If tree is not empty
    TreeNode* ptr = root;

    while (ptr != nullptr) {
      if (value == ptr->value) {  // If value already exists in tree, return
        return;
      } else if (value < ptr->value) {  // If value is less than, look left
        if (ptr->left == nullptr) { // If current node is a leaf, add new node
          try {
            ptr->left = new TreeNode(value, nullptr, nullptr);
          } catch (std::bad_alloc) {
            throw jw::BinaryTree::TreeMemError();
          }
          return;
        } else {
          ptr = ptr->left;  // If current node isn't a leaf, go left
        }
      } else {  // If value is greater than, look right
        if (ptr->right == nullptr) {  // If current node is a leaf, add new node
          try {
            ptr->right = new TreeNode(value, nullptr, nullptr);
          } catch (std::bad_alloc) {
            throw jw::BinaryTree::TreeMemError();
          }
          return;
        } else {
          ptr = ptr->right;  // If current node isn't a leaf, go right
        }
      }
    }
  }
}

// Search for value in tree
bool jw::BinaryTree::search(double value) {
  if (root == nullptr) {
    return false;
  }

  return search(value, root);
}

// Private recursive search
bool jw::BinaryTree::search(double value, TreeNode* tree) {
  if (value == tree->value) {
    return true;
  }

  if (value < tree->value && tree->left != nullptr) {
    return search(value, tree->left);
  }

  if (value > tree->value && tree->right != nullptr) {
    return search(value, tree->right);
  }

  return false;
}

// Return vector with tree values inorder
void jw::BinaryTree::inorder(std::vector<double> &v) {
  if (!root) {
    return;
  }
  inorder(v, root);
}

// Private recursive inorder
void jw::BinaryTree::inorder(std::vector<double> &v, TreeNode* tree) {
  if(tree->left) 
    inorder(v, tree->left);

  v.push_back(tree->value);

  if (tree->right)
    inorder(v, tree->right);
}