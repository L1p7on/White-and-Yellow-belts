#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
  throw std::runtime_error("test");
}

class TimeServer {
public:
    string GetCurrentTime() {
      try {
        std::string new_time = AskTimeServer();
        last_fetched_time = new_time;
        return last_fetched_time;
      } catch (std::system_error& e) {
        return last_fetched_time;
      }
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}