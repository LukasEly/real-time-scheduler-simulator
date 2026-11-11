#include <cctype>
#include <string>
#include <limits>
#include "../include/Cpu.hpp"

Cpu::Cpu() {
    pid = -1;
    symbol = ' ';
    numPreemp = 0;
    numContSwitch = 0;
    grid = "";
    comput = 0;
    deadline = -1;
    time = 0;
}

Cpu::~Cpu() {}

void Cpu::load(int p, char s, int c, int d) {
    symbol = s;
    deadline = d;
    if (pid == -1) {
        pid = p;
    } else if (pid != p) {
        pid = p;
        ++numContSwitch;
        if (comput > 0)
            ++numPreemp;
    }
    comput = c;
}

void Cpu::run(const std::vector<Task>& tasks, unsigned time) {
    // Verifica se a tarefa atual terminou
    if (comput == 0 && pid != -1) {
        std::cout << "Tarefa " << symbol << " concluída no tempo " << time << "." << std::endl;
        pid = -1; // Libera a CPU
    }

    // Seleciona uma nova tarefa se a CPU estiver livre
    while (pid == -1) { // Enquanto a CPU estiver livre, tente carregar uma nova tarefa
        Task* selectedTask = nullptr;
        unsigned minDeadline = std::numeric_limits<unsigned>::max();

        for (const auto& task : tasks) {
            std::cout << "Verificando tarefa: " << task.getId()
                      << " (Computing: " << task.getComputing()
                      << ", Period: " << task.getPeriod()
                      << ", Deadline: " << task.getDeadline() << ")" << std::endl;
        
            // Verifica se a tarefa deve ser ativada no tempo atual ou se ainda está pronta para execução
            if ((time % task.getPeriod() == 0 && task.getComputing() > 0) && task.getComputing() > 0) {
                std::cout << "Tarefa " << task.getId() << " está pronta para execução no tempo " << time << "." << std::endl;
        
                if (task.getDeadline() < minDeadline) {
                    std::cout << "Tarefa " << task.getId() << " tem o menor deadline até agora: " << task.getDeadline() << "." << std::endl;
                    minDeadline = task.getDeadline();
                    selectedTask = const_cast<Task*>(&task);
                }
            } else {
                std::cout << "Tarefa " << task.getId() << " não está pronta para execução no tempo " << time << "." << std::endl;
            }
        }

        if (selectedTask) {
            // Carrega a nova tarefa na CPU
            load((time << 5) | selectedTask->getId(), selectedTask->getId(),
                 selectedTask->getComputing(), selectedTask->getDeadline());
            std::cout << "Tarefa " << selectedTask->getId() << " carregada na CPU no tempo " << time << "." << std::endl;
        } else {
            break; // Não há tarefas prontas, CPU permanecerá ociosa
        }
    }

    // Executa a tarefa carregada ou marca a CPU como ociosa
    if (pid != -1) {
        std::cout << "Executando tarefa: " << symbol << ", tempo restante: " << comput << std::endl;
        if (deadline != -1 && time >= deadline)
            grid.append(1, std::tolower(symbol)); // Marca como atrasada
        else
            grid.append(1, symbol); // Marca como executada no prazo
        ++time;
        --comput; // Decrementa o tempo de computação
    } else {
        std::cout << "CPU ociosa no tempo: " << time << std::endl;
        ++time;
        grid.append(1, '_'); // Marca como ociosa
    }
}

std::string Cpu::getGrid() const {
    return grid;
}

int Cpu::getNumPreemp() const {
    return numPreemp;
}

int Cpu::getNumContSwitch() const {
    return numContSwitch;
}

