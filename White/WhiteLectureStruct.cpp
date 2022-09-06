#include <iostream>
#include <string>

struct Specialization {
  std::string spec;
  explicit Specialization(std::string s) :
  spec(s) {}
};

struct Course {
  std::string course;
  explicit Course(std::string s) :
  course(s) {}
};

struct Week {
  std::string week;
  explicit Week(std::string s) :
  week(s) {}
};

struct LectureTitle {
  std::string specialization;
  std::string course;
  std::string week;

  explicit LectureTitle(Specialization s, Course c, Week w) :
  specialization(s.spec),
  course(c.course),
  week(w.week){}
};

int main() {
  LectureTitle title(
    Specialization("C++"),
    Course("White belt"),
    Week("4th")
  );
}