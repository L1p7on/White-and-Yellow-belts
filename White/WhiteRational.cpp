#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int Euclid(int a, int b) {
  if (a < b) {
    int tmp = a;
    a = b;
    b = tmp;
  }
  if (a == b) {
    return a;
  }
  int delta = a/b;
  if (a == delta * b) {
    return b;
  }
  a -= delta * b;
  return Euclid(b, a);
}

class Rational {
public:
  Rational() : _numerator(0), _denominator(1) {}
  Rational(int numerator, int denominator) {
    if (denominator == 0) {
      throw std::invalid_argument("denominator is 0");
    }
    if (numerator == 0) {
      _numerator = 0;
      _denominator = 1;
    } else {
      int GCD = Euclid(std::abs(numerator), std::abs(denominator));
      _numerator = numerator/GCD;
      _denominator = denominator/GCD;
      if (_numerator < 0 && _denominator < 0) {
        _numerator *= -1;
        _denominator *= -1;
      } else if (_denominator < 0 && _numerator > 0) {
        _numerator *= -1;
        _denominator *= -1;
      }
    }
  }

  int Numerator() const {
    return _numerator;
  }
  int Denominator() const {
    return _denominator;
  }
private:
  int _numerator;
  int _denominator;
};

bool operator< (const Rational& lhs, const Rational rhs) {
  return lhs.Numerator() * rhs.Denominator() < lhs.Denominator() * rhs.Numerator();
}

bool operator== (const Rational& lhs, const Rational& rhs) {
  return lhs.Numerator() == rhs.Numerator() && rhs.Denominator() == lhs.Denominator();
}

Rational operator+ (const Rational& lhs, const Rational& rhs) {
  return Rational(rhs.Numerator() * lhs.Denominator() + rhs.Denominator() * lhs.Numerator(),
                  lhs.Denominator() * rhs.Denominator());
}
Rational operator- (const Rational& lhs, const Rational& rhs) {
  return Rational(-1 * rhs.Numerator() * lhs.Denominator() + rhs.Denominator() * lhs.Numerator(),
                  lhs.Denominator() * rhs.Denominator());
}

Rational operator* (const Rational& lhs, const Rational& rhs) {
  return Rational(rhs.Numerator() * lhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/ (const Rational& lhs, const Rational& rhs) {
  if (lhs.Denominator() * rhs.Numerator() == 0) {
    throw std::domain_error("division by 0");
  }
  return Rational(rhs.Denominator() * lhs.Numerator(), lhs.Denominator() * rhs.Numerator());
}

istream& operator>>(istream& in, Rational& r){
  int numerator = 0;
  int denominator = 1;
  char c = ' ';
  if (!(in >> numerator) || !(in >> c) || !(in >> denominator) || (c != '/'))  {
    return in;
  }
  r = Rational(numerator, denominator);
  return in;
}

std::ostream& operator<< (std::ostream& out, const Rational& r) {
  out << r.Numerator() << '/' << r.Denominator();
  return out;
}

int main()
{
  try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }
    
    cout << "OK" << endl;
    return 0;
}