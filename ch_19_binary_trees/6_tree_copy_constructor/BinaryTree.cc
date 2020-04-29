#include <new>
#include <vector>
#include <algorithm> // max

#include "BinaryTree.h"

// Constructor
jw::BinaryTree::BinaryTree() {
  this->root = nullptr;
}

// Copy Constructor
jw::BinaryTree::BinaryTree(jw::BinaryTree &sourceTree) {
  std::vector<double> v;
  root = nullptr;

  sourceTree.preorder(v);

  for (const double &value : v)
    insert(value);
}

// Destructor
jw::BinaryTree::~BinaryTree() {

}

// Insert new node into tree -- This code is a mess.
void jw::BinaryTree::insert(double value) {
  int level = 0; // Used to update levelSize vector

  // If tree is empty
  if (!root) {  
    try {
      root = new TreeNode(value, root, root);
      levelWidth.push_back(0);
      return;
    } catch (std::bad_alloc) {
      throw jw::BinaryTree::TreeMemError();
    }
  }
  
  // If tree is not empty
  TreeNode* ptr = root;

  while (ptr) {
    // Left Branch
    if (value < ptr->value) {
      if (!ptr->left) {
        try {
          ptr->left = new TreeNode(value, nullptr, nullptr);
        } catch (std::bad_alloc) {
          throw jw::BinaryTree::TreeMemError();
        }
      } 
      ptr = ptr->left;
      level++;
      if (levelWidth.size()-1 < level) { levelWidth.push_back(0); }
      // Right Branch
    } else if (ptr->value < value) {
      if (!ptr->right) { 
        try {
          ptr->right = new TreeNode(value, nullptr, nullptr);
        } catch (std::bad_alloc) {
          throw jw::BinaryTree::TreeMemError();
        }
      }
      ptr = ptr->right;
      level++;
      if (levelWidth.size()-1 < level) { levelWidth.push_back(0); }
    }

    if (ptr->value == value) {
      levelWidth[level]++;
      return;
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
  if (root)
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

// Return vector with tree values preorder
void jw::BinaryTree::preorder(std::vector<double> &v) {
  if (root)
    preorder(v, root);
}

// Priate recursive preorder
void jw::BinaryTree::preorder(std::vector<double> &v, TreeNode* tree) {
  v.push_back(tree->value);

  if (tree->left)
    preorder(v, tree->left);

  if (tree->right)
    preorder(v, tree->right);
}

// Returns number of nodes
int jw::BinaryTree::size() {
  if (!root)
    return 0;

  return size(root);
}

// Private recursive size
int jw::BinaryTree::size(TreeNode* tree) {
  int leftSize = 0, 
      rightSize = 0;

  if (tree->left)
    leftSize = size(tree->left);
  if (tree->right)
    rightSize = size(tree->right);

  return 1 + leftSize + rightSize;
}

// Returns number of leaves
int jw::BinaryTree::leafCount() {
  if (!root)
    return 0;

  return leafCount(root);
}

// Private recursive leaf count
int jw::BinaryTree::leafCount(TreeNode* tree) {
  int isLeaf = 1;
  int leftCount = 0, 
      rightCount = 0;
  
  if (tree->left) {
    leftCount = leafCount(tree->left);
    isLeaf = 0;
  }
  
  if (tree->right) {
    rightCount = leafCount(tree->right);
    isLeaf = 0;
  }

  return isLeaf + leftCount + rightCount;
}

// Returns height of tree
int jw::BinaryTree::height() {
  if (!root)
    return 0;

  return height(root);
}

// Private recursive height
int jw::BinaryTree::height(TreeNode* tree) {
  int leftHeight = 0,
      rightHeight = 0;

  if (tree->left)
    leftHeight = height(tree->left);
  if (tree->right)
    rightHeight = height(tree->right);

  return 1 + std::max(leftHeight, rightHeight);
}

// Returns width of tree
int jw::BinaryTree::width() {
  if (!root)
    return 0;

  return *std::max_element(levelWidth.begin(), levelWidth.end());
}