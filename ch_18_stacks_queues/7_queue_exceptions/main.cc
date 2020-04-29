// This program is written to make it easy to attempt to overflow
// the scores staticqueue to show the overflow exception catches.
#include <iostream>

#include "StaticQueue.h"

int main() {
  int numScores; 
  double score = -1;
  std::cout << "How many scores? ";
  std::cin >> numScores;

  StaticQueue<double> scores(numScores);

  try {
      std::cout << "Enter score (-1 to finish): ";
      std::cin >> score;
    while (score >= 0) {
      scores.enqueue(score);
      std::cout << "Enter score (-1 to finish): ";
      std::cin >> score;
    }
  } catch (StaticQueue<double>::Overflow) {
    std::cout << "You said you only had " << numScores << " scores.\n";
    std::cout << "You just tried to enter score #" << numScores+1 << ".\n";
    std::cout << "Why did you lie to me? :(\n";
  }

  std::cout << "Scores: ";
  for (int i = 0; i < numScores; i++) {
    scores.dequeue(score);
    std::cout << score << " ";
  }
  std::cout << "\n";
    

  return 0;
}