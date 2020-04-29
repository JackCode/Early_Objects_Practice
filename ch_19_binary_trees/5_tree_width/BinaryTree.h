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
  int size();
  int leafCount();
  int height();
  int width();

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
  std::vector<int> levelWidth;
  bool search(double value, TreeNode* tree);
  void inorder(std::vector<double> &v, TreeNode* tree);
  int size(TreeNode* tree);
  int leafCount(TreeNode* tree);
  int height(TreeNode* tree);
};

}

#endif