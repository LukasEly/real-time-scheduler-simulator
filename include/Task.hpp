#ifndef TASK_HPP
#define TASK_HPP

#include <iostream>

class Task {
private:
  char id;
  unsigned computing, period, deadline;

public:
  Task();
  Task(char i, unsigned c = 0, unsigned p = 0, unsigned d = 0);

  char getId() const;
  unsigned getComputing() const;
  unsigned getPeriod() const;
  unsigned getDeadline() const;

  friend std::istream &operator>>(std::istream &in, Task &t);
  friend std::ostream &operator<<(std::ostream &out, Task &t);
};

#endif
