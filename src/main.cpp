#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <limits> // Para std::numeric_limits

#include "../include/Task.hpp"
#include "../include/Cpu.hpp"

using namespace std;


int main() {
    unsigned numTasks, simTime;

    while (true) {
        cin >> numTasks >> simTime;
        if (numTasks == 0 || simTime == 0)
            break;

        vector<Task> tasks;
        for (unsigned i = 0; i < numTasks; i++) {
            Task t('A' + i);
            cin >> t;
            if (t.getComputing() > 0 && t.getPeriod() > 0) {
                tasks.push_back(t);
            } else {
                cerr << "Erro: Tarefa inválida!" << endl;
                return 1;
            }
        }

        Cpu cpu;

        // SIMULAÇÃO
        unsigned time = 0;
        while (time < simTime) {
            cpu.run(tasks, time);
            ++time;
        }

        // OUTPUT
        std::string gantt = cpu.getGrid();
        std::cout << "\n" << gantt << std::endl;

        std::cout << cpu.getNumContSwitch() << " " << cpu.getNumPreemp() << std::endl;

        size_t idleTime = std::count(gantt.begin(), gantt.end(), '_');
        double utiliz = static_cast<double>(simTime - idleTime) / simTime;

        std::cout << std::fixed << std::setprecision(4) << utiliz << " " << (utiliz <= 1.0 ? "OK" : "NOK") << std::endl;
    }

    return 0;
}
