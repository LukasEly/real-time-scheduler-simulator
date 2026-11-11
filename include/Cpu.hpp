#ifndef CPU_HPP
#define CPU_HPP

#include <string>
#include <vector>
#include "Task.hpp"

class Cpu {
private:
    int pid;
    char symbol;
    int numPreemp;
    int numContSwitch;
    std::string grid;
    int comput;
    int deadline;
    unsigned int time;

public:
    Cpu();
    ~Cpu();
    void load(int p, char s, int c, int d);
    void run(const std::vector<Task>& tasks, unsigned time);
    std::string getGrid() const;
    int getNumPreemp() const;
    int getNumContSwitch() const;
};

#endif