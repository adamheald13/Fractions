#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
public:
  Fraction();
  Fraction(int numerator, int denominator);

  int getNumerator();
  int getDenominator();
  void fractionToMixedNumber();
  void mixedNumberToFraction();
  void reciprocate();
  void reduce();
  void printFraction();

  static Fraction add(Fraction f1, Fraction f2);
  static Fraction xAdd(Fraction f1, Fraction f2);
  static Fraction subtract(Fraction f1, Fraction f2);
  static Fraction multiply(Fraction f1, Fraction f2);
  static Fraction divide(Fraction f1, Fraction f2);
  static Fraction xDivide(Fraction f1, Fraction f2);
  static Fraction decimalToFraction(float decimal);
  static Fraction addMixedNumbers(Fraction f1, Fraction f2);
  static Fraction less(Fraction f1, Fraction f2);

private:
  int numerator;
  int denominator;
  int wholeNumber;  //used for mixed numbers
                    //If this variable is filled it indicates this
                    //object represents a mixed number.
  int gcd(int a, int b);
};

#endif
