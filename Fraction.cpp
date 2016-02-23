#include <iostream>
#include <stdlib.h>
#include "Fraction.h"
using namespace std;

Fraction::Fraction() {
  this->numerator = 0;
  this->denominator = 1;
  this->wholeNumber = 0;
}

Fraction::Fraction(int numerator, int denominator) {
  this->numerator = numerator;

  if(denominator == 0) {
    cout << "Invalid denominator. Denominator cannot equal zero." << endl;
    exit (EXIT_FAILURE);
  }
  else if(denominator < 0) {                //check if input fraction has negative denominator
    this->denominator = denominator * -1;   //make denominator positive
    this->numerator = numerator * -1;       //flip sign of the numerator
  } else
    this->denominator = denominator;        //given denominator is positive
    this->wholeNumber = 0;                  //indicates this is NOT a mixed number
}

int Fraction::getNumerator() {
  return this->numerator;
}

int Fraction::getDenominator() {
  return this->denominator;
}

void Fraction::fractionToMixedNumber() {
  if(this->numerator <= this->denominator && this->numerator * -1 <= this->denominator) {
    //the fraction is proper, cannot be changed to a mixed number
  } else {
    this->wholeNumber = this->numerator / this->denominator;
    this->numerator = this->numerator % this->denominator;
    if(this->numerator < 0) {
      this->numerator *= -1;
    }
  }

  this->reduce();
}

void Fraction::mixedNumberToFraction() {
  if(this->wholeNumber == 0) {
    //the fraction is not a mixed number and does not need to be changed
  } else {
    if(this->wholeNumber > 0) {
      this->numerator = this->wholeNumber * this->denominator + this->numerator;
    } else {
      this->numerator = this->wholeNumber * this->denominator - this->numerator;
    }

    this->wholeNumber = 0;
  }
}

void Fraction::reciprocate() {
  if(this->numerator < 0) { //preserve numerator containment of sign
    this->numerator *= -1;
    this->denominator *= -1;
  }

  int newNumerator = this->denominator;
  int newDenominator = this->numerator;

  this->denominator = newDenominator;
  this->numerator = newNumerator;
}

void Fraction::reduce() {
  int gcd = Fraction::gcd(this->denominator, this->numerator);
  this->numerator /= gcd;
  this->denominator /= gcd;

  if(this->denominator < 0) {
    this->denominator *= -1;
    this->numerator *= -1;
  }
}

int Fraction::gcd(int a, int b) {
  if(b == 0) {
    return a;
  } else {
    gcd(b, a % b);
  }
}

void Fraction::printFraction() {
  if(this->wholeNumber != 0) {
    cout << this->wholeNumber << " ";
  }
  if(this->numerator != 0) {
    cout << this->getNumerator() << "/" << this->getDenominator();
  }
  if(this->wholeNumber == 0 && this->numerator == 0) {
    cout << 0;
  }
}

Fraction Fraction::add(Fraction f1, Fraction f2) {
  // (a/b) + (c/d)
  // = (a * d + c * b) / (d * b)
  Fraction sum = Fraction(f1.getNumerator() * f2.getDenominator() +
                          f2.getNumerator() * f1.getDenominator(),
                          f1.getDenominator() * f2.getDenominator());

  sum.reduce();
  return sum;
}

Fraction Fraction::xAdd(Fraction f1, Fraction f2) {
  Fraction mixedSum = Fraction::add(f1, f2);
  mixedSum.fractionToMixedNumber();

  return mixedSum;
}

Fraction Fraction::subtract(Fraction f1, Fraction f2) {
  Fraction difference = Fraction(f1.getNumerator() * f2.getDenominator() -
                                 f2.getNumerator() * f1.getDenominator(),
                                 f1.getDenominator() * f2.getDenominator());
  difference.reduce();
  return difference;
}

Fraction Fraction::multiply(Fraction f1, Fraction f2) {
  Fraction product = Fraction(f1.getNumerator() * f2.getNumerator(),
                              f1.getDenominator() * f2.getDenominator());

  product.reduce();
  return product;
}

Fraction Fraction::divide(Fraction f1, Fraction f2) {
  f2.reciprocate();
  Fraction quotient = Fraction::multiply(f1, f2);

  //no need to reduce as multiply does that for us
  return quotient;
}

Fraction Fraction::xDivide(Fraction f1, Fraction f2) {
  Fraction mixedQuotient = Fraction::divide(f1, f2);
  mixedQuotient.fractionToMixedNumber();

  return mixedQuotient;
}

Fraction Fraction::decimalToFraction(float decimal) {
  float numerator = decimal;
  int denominator = 1;

  numerator *= 10000000;
  denominator *= 10000000;

  Fraction fraction = Fraction((int) numerator, denominator);
  fraction.reduce();
  return fraction;
}

Fraction Fraction::addMixedNumbers(Fraction f1, Fraction f2) {
  f1.mixedNumberToFraction();
  f2.mixedNumberToFraction();

  Fraction sum = Fraction::xAdd(f1, f2);
  return sum;
}

Fraction Fraction::less(Fraction f1, Fraction f2) {
  int f1TempNum = f1.getNumerator() * f2.getDenominator();
  int f2TempNum = f2.getNumerator() * f1.getDenominator();

  if(f1TempNum < f2TempNum) {
    return f1;
  } else if(f2TempNum < f1TempNum) {
    return f2;
  }
}
