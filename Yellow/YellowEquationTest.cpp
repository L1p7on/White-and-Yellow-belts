#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>

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

int GetDistinctRealRootCount(double a, double b, double c);

void TestTwoRoots() {
  AssertEqual(2, GetDistinctRealRootCount(2, 3, 1));
  AssertEqual(2, GetDistinctRealRootCount(2.5, 4, 1));
}

void TestRepeatedRoot() {
  AssertEqual(1, GetDistinctRealRootCount(1, 2, 1));
}

void TestLinearEquation() {
  AssertEqual(1, GetDistinctRealRootCount(0, 2.5, 4));
}

void TestNoRoots() {
  AssertEqual(0, GetDistinctRealRootCount(0, 0, 4));
  AssertEqual(0, GetDistinctRealRootCount(1, 4, 8));
}

int GetDistinctRealRootCount(double a, double b, double c) {
  int result = 0;
  if (std::fabs(a) < 10e-14) {
    if (std::fabs(b) > 10e-14) {
      ++result;
      // std::cout << result << std::endl;
    }
  } else {
    if (b*b - 4*c*a < 0) {
      return 0;
    }
    if (std::sqrt(b*b - 4*c*a) < 10e-14) {
      ++result;
      // result += 2;
      // std::cout << result << std::endl;
    } else {
      ++result;
      // std::cout << result << " ";
      ++result;
      // std::cout << result << std::endl;
    }
  }
  return result;
}

int main() {
  TestRunner runner;
  runner.RunTest(TestTwoRoots, "TestTwoRoots");
  runner.RunTest(TestLinearEquation, "TestLinearEquation");
  runner.RunTest(TestNoRoots, "TestNoRoots");
  runner.RunTest(TestRepeatedRoot, "TestRepeatedRoot");
  // std::cout << GetDistinctRealRootCount(2, 3, 1) << std::endl;
  return 0;
}