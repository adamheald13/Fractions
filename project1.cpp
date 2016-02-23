#include <iostream>
#include "Fraction.h"
using namespace std;

Fraction sum(int numOfFractions, Fraction listOfFractions[]);
void sort(int numOfFractions, Fraction listOfFractions[]);
void mean(int numOfFractions, Fraction listOfFractions[]);
void median(int numOfFractions, Fraction listOfFractions[]);
void mode(int numOfFractions, Fraction listOfFractions[]);

Fraction listOfFractions[16];

void initListOfFractions() {
  listOfFractions[0] = Fraction(1, 2);
  listOfFractions[1] = Fraction(1, 2);
  listOfFractions[2] = Fraction(1, 2);
  listOfFractions[3] = Fraction(-3, 4);
  listOfFractions[4] = Fraction(-3, 4);
  listOfFractions[5] = Fraction(-3, 4);
  listOfFractions[6] = Fraction(1, 8);
  listOfFractions[7] = Fraction(1, 8);
  listOfFractions[8] = Fraction(0, 5);
  listOfFractions[9] = Fraction(7, 3);
  listOfFractions[10] = Fraction(9, -2);
  listOfFractions[11] = Fraction(-6, 5);
  listOfFractions[12] = Fraction(-7, 12);
  listOfFractions[13] = Fraction(13, -20);
  listOfFractions[14] = Fraction(3, 7);
  listOfFractions[15] = Fraction(9, 10);
}

int main() {
  initListOfFractions();

  std::cout << "----- SUM function -----" << std::endl;
  sum(16, listOfFractions);

  std::cout << endl << "----- MEAN function -----" << std::endl;
  mean(16, listOfFractions);

  // Fraction f1 = Fraction(-5, 8);
  // Fraction f2 = Fraction(1, 8);

  // Fraction::add(f1, f2).printFraction(); cout << endl;
}

Fraction sum(int numOfFractions, Fraction listOfFractions[]) {
  Fraction sum = Fraction();

  for(int i = 0; i < numOfFractions; i++) {
    sum.printFraction(); cout << " + "; listOfFractions[i].printFraction(); cout << " = ";
    sum = Fraction::add(sum, listOfFractions[i]);
    sum.printFraction(); cout << endl;
  }

  return sum;
}

void mean(int numOfFractions, Fraction listOfFractions[]) {
  Fraction mean = sum(numOfFractions, listOfFractions);
  std::cout << "Sum: "; mean.printFraction(); cout << endl;
  mean.printFraction(); cout << " / " << numOfFractions << " = ";
  mean = Fraction::divide(mean, Fraction(numOfFractions, 1));
  mean.printFraction();
}
