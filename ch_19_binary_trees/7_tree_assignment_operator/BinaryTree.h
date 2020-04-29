#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <vector>

namespace jw {

class BinaryTree {
 public:
  BinaryTree();
  BinaryTree(jw::BinaryTree &sourceTree);
  ~BinaryTree();

  // Member functions
  void insert(double value);
  bool search(double value);
  void inorder(std::vector<double> &v);
  void preorder(std::vector<double> &v);
  int size();
  int leafCount();
  int height();
  int width();
  void clear();

  // Overload functions
  jw::BinaryTree &operator=(jw::BinaryTree &sourceTree);

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
  void preorder(std::vector<double> &v, TreeNode* tree);
  int size(TreeNode* tree);
  int leafCount(TreeNode* tree);
  int height(TreeNode* tree);
  void deleteNode(TreeNode* tree);
};

}

#endif