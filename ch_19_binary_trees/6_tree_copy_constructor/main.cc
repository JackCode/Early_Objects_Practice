#include <iostream>
#include <vector>
#include "BinaryTree.h"

void printTree(jw::BinaryTree &tree);

int main() {
  jw::BinaryTree tree1;

  try {
    tree1.insert(5);
    tree1.insert(3);
    tree1.insert(8);
    tree1.insert(12);
    tree1.insert(9);
  } catch (jw::BinaryTree::TreeMemError) {
    std::cout << "ERROR: Memory error.\n";
  }

  std::cout << "TREE 1\n";
  printTree(tree1);

  jw::BinaryTree tree2 = tree1;
  std::cout << "TREE 2\n";
  printTree(tree2);
  
  return 0;
}

void printTree(jw::BinaryTree &tree) {
  std::vector<double> values;
  tree.inorder(values);

  std::cout << "Inorder: ";
  for (const double &v : values) {
    std::cout << v << " ";
  }
  std::cout << "\n";
  values.clear();

  tree.preorder(values);
  std::cout << "Preorder: ";
  for (const double &v : values) {
    std::cout << v << " ";
  }

  std::cout << "\n";
  std::cout << "Size: " << tree.size() << "\n";
  std::cout << "Leaves: " << tree.leafCount() << "\n";
  std::cout << "Height: " << tree.height() << "\n";
  std::cout << "Width: " << tree.width() << "\n";

  std::cout << "\n";

  return;
}