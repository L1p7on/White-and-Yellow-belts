#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

// class Rational {
// private:
//   int numerator;
//   int denominator;
// public:
//   Rational() : numerator(0), denominator(1) {};
//   Rational(int numerator, int denominator) {

//   }

//   int Numerator() const {
//   }

//   int Denominator() const {
//   }
// };

void TestConstruct() {
  Rational r;
  AssertEqual(0, r.Numerator());
  AssertEqual(1, r.Denominator());
  Rational r1(1, 2);
  AssertEqual(1, r1.Numerator());
  AssertEqual(2, r1.Denominator());
  Rational r2(0, 2);
  AssertEqual(0, r2.Numerator());
  AssertEqual(1, r2.Denominator());
  Rational r3(-1, 2);
  Assert(r3.Numerator() < 0 && r3.Denominator() > 0, "Sing of Numerator");
  Rational r4(-2, -3);
  Assert(r4.Numerator() > 0 && r4.Denominator() > 0, "Positive number with negative constructor");
  Rational r5(4, 6);
  AssertEqual(r5.Numerator(), 2);
  AssertEqual(r5.Denominator(), 3);
}

int main() {
  TestRunner runner;
  runner.RunTest(TestConstruct, "TestConstruct");
  return 0;
}