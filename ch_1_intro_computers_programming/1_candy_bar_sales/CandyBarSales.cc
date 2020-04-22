#include <iostream>

int main() {
  double numBarsSold, pricePerBar, totalSales;

  std::cout << "How many bars were sold? ";
  std::cin >> numBarsSold;
  std::cout << "How much is each bar sold for? $";
  std::cin >> pricePerBar;

  totalSales = numBarsSold * pricePerBar;

  std::cout << "Your organization raised $" << totalSales << ".\n";

  return 0;
}