#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <vector>

namespace jw {

class BinaryTree {
 public:
  BinaryTree();
  ~BinaryTree();

  void insert(double value);
  bool search(double value);
  void inorder(std::vector<double> &v);

  // Exception Classes
  class TreeMemError {};

 private:
  class TreeNode {
    friend class BinaryTree;
    double value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(double value, TreeNode* left, TreeNode* right) {
      this->value = value;
      this->left = left;
      this->right = right;
    }
  };
  TreeNode* root;
  bool search(double value, TreeNode* tree);
  void inorder(std::vector<double> &v, TreeNode* tree);
};

}

#endif