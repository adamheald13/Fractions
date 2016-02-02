#include <iostream>
#include "Fraction.h"
using namespace std;

int main()
{
  Fraction* f1 = new Fraction(-1, -2);
  Fraction* f2 = new Fraction(1, 2);
  Fraction* f3 = Fraction::add(f1, f2);

  f3->printFraction();
}
