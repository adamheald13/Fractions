#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
public:
  Fraction(int numerator, int denominator);

  int getNumerator();
  int getDenominator();
  void printFraction();

  static Fraction* add(Fraction* firstAddend, Fraction* secondAddend);
  static Fraction xAdd(Fraction firstAddend, Fraction secondAddend);

private:
  int numerator;
  int denominator;

  static Fraction reduce(Fraction fraction);
};

#endif
