#include <iostream>

int main() {
  double numBallsPurchased, pricePerBall, totalCost;

  std::cout << "How many balls were purchased? ";
  std::cin >> numBallsPurchased;
  std::cout << "What was the price per ball? $";
  std::cin >> pricePerBall;

  totalCost = numBallsPurchased * pricePerBall;

  std::cout << "You spent $" << totalCost << " on baseballs.\n";

  return 0;
}