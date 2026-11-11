#include "../include/Task.hpp"

Task::Task() {
  id = '.';
  computing = 9999999;
  period = deadline = 0;
}

Task::Task(char i, unsigned c, unsigned p, unsigned d) {
  id = i;
  computing = c;
  period = p;
  deadline = d;
}

char Task::getId() const { return id; }
unsigned Task::getComputing() const { return computing; }
unsigned Task::getPeriod() const { return period; }
unsigned Task::getDeadline() const { return deadline; }

std::istream &operator>>(std::istream &in, Task &t) {
  in >> t.computing >> t.period >> t.deadline;
  return in;
}

std::ostream &operator<<(std::ostream &out, Task &t) {
  out << t.id << ": " << t.computing << " " << t.period << " " << t.deadline;
  return out;
}
