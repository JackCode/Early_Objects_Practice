#include <iostream>
#include <vector>
#include "BinaryTree.h"

int main() {
  jw::BinaryTree tree;
  std::vector<double> values;

  try {
    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(12);
    tree.insert(9);
  } catch (jw::BinaryTree::TreeMemError) {
    std::cout << "ERROR: Memory error.\n";
  }

  tree.inorder(values);

  std::cout << "Inorder: ";
  for (const double &v : values) {
    std::cout << v << " ";
  }

  std::cout << "\n";
  std::cout << "Size: " << tree.size() << "\n";
  std::cout << "Leaves: " << tree.leafCount() << "\n";

  std::cout << "\n";

  return 0;
}