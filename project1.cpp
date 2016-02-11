#include <iostream>
#include "Fraction.h"
using namespace std;

int main() {
  Fraction f1(2, 3);
  Fraction f2(1, 2);
  Fraction f4(-11, 3);

  // Fraction f3 = Fraction::xAdd(f1, f2);
  f4.convertToMixedNumber();

  f4.printFraction();
}
