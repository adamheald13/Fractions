#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
public:
  Fraction(int numerator, int denominator);

  int getNumerator();
  int getDenominator();
  void convertToMixedNumber();
  void reduce();
  void printFraction();

  static Fraction add(Fraction firstAddend, Fraction secondAddend);
  static Fraction xAdd(Fraction firstAddend, Fraction secondAddend);

private:
  int numerator;
  int denominator;
  int wholeNumber;  //used for mixed numbers
                    //If this variable is filled it indicates this
                    //object represents a mixed number.
};

#endif
