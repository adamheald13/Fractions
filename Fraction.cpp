#include <iostream>
#include <stdlib.h>
#include "Fraction.h"
using namespace std;

Fraction::Fraction(int numerator, int denominator)
{
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
}

Fraction* Fraction::add(Fraction* f1, Fraction* f2)
{
  return f1;
}

Fraction Fraction::reduce(Fraction fraction)
{

}

int Fraction::getNumerator()
{
  return this->numerator;
}

int Fraction::getDenominator()
{
  return this->denominator;
}

void Fraction::printFraction()
{
  cout << this->getNumerator() << "/" << this->getDenominator();
}
