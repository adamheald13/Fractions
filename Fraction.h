#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
public:
  Fraction add(Fraction firstAddend, Fraction secondAddend);
  Fraction xAdd(Fraction firstAddend, Fraction secondAddend);

private:
  int numerator;
  int denominator;

  Fraction reduce(Fraction fraction);
};

#endif
