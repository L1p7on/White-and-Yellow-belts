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

bool IsPalindrom(const string& str) {
  if (str.empty()) {
    return true;
  }
  size_t j = str.size() - 1;
  size_t i = 0;
  for (; i <= str.size()/2 && j >= str.size()/2; ++i, --j) {
    if (str[i] != str[j]) {
      return false;
    }
  }
  return true;
}

void TestEmpty() {
  Assert(IsPalindrom(""), "EmptyTest1");
  Assert(IsPalindrom({}), "EmptyTest2");
}

void TestAlone() {
  Assert(IsPalindrom("c"), "Alone");
}

void TestMiddle() {
  Assert(!IsPalindrom("cbdebc"), "Middle1");
  Assert(!IsPalindrom("cDbddbc"), "Middle2");
  Assert(!IsPalindrom("cbEddbc"), "Middle3");
  Assert(!IsPalindrom("cbddLbc"), "Middle4");
  Assert(!IsPalindrom("cbddbKc"), "Middle5");
}

void TestEdge() {
  Assert(!IsPalindrom("bbbbbbbd"), "Edge0");
  Assert(!IsPalindrom("abbbbbbd"), "Edge1");
  Assert(!IsPalindrom("cfgbled"), "Edge2");
  Assert(!IsPalindrom("bebbbfb"), "Edge3");
  Assert(!IsPalindrom("qweY_Yew"), "Edge4");
  Assert(!IsPalindrom("ZweY_YewX"), "Edge5");
  Assert(!IsPalindrom("weY_Yewq"), "Edge6");
}

void TestSpaces() {
  Assert(IsPalindrom("acd dca"), "Spaces1");
  Assert(!IsPalindrom("acd d c a"), "Spaces2");
}

void TestNumbers() {
  Assert(IsPalindrom("131131"), "Numbers1");
  Assert(!IsPalindrom("ab13ba"), "Numbers2");
}

void TestPunctuation() {
  Assert(!IsPalindrom("Mama,maM"), "Punctuation");
}

void TestLowerUpper() {
  Assert(!IsPalindrom("Aa"), "LowerUpper");
  Assert(!IsPalindrom("mmaaMM"), "LowerUpper");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestEmpty, "TestEmpty");
  runner.RunTest(TestAlone, "TestAlone");
  runner.RunTest(TestEdge, "TestEdge");
  runner.RunTest(TestMiddle, "TestMiddle");
  runner.RunTest(TestSpaces, "TestSpaces");
  runner.RunTest(TestPunctuation, "TestPunctuation");
  runner.RunTest(TestNumbers, "TestNumbers");
  return 0;
}