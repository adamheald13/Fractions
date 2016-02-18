#include <iostream>
#include <stdlib.h>
#include "Fraction.h"
using namespace std;

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

void Fraction::convertToMixedNumber() {
  if(this->numerator <= this->denominator && this->numerator * -1 <= this->denominator) {
    //the fraction is proper, cannot be changed to a mixed number
  } else {
    this->wholeNumber = this->numerator / this->denominator;
    this->numerator = this->numerator % this->denominator;
    if(this->numerator < 0) {
      this->numerator *= -1;
    }
  }
}

void Fraction::reduce() {
  //TODO
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
  cout << endl;
}

Fraction Fraction::add(Fraction f1, Fraction f2) {
  // (a/b) + (c/d)
  // = (a * d + c * b) / (d * b)
  Fraction sum = Fraction(f1.getNumerator() * f2.getDenominator() +
                          f2.getNumerator() * f1.getDenominator(),
                          f1.getDenominator() * f2.getDenominator());

  return sum;
}

Fraction Fraction::xAdd(Fraction f1, Fraction f2) {
  Fraction mixedSum = Fraction::add(f1, f2);
  mixedSum.convertToMixedNumber();
  return mixedSum;
}
