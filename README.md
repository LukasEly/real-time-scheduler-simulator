# Simulador de escalonamento de tempo real

Simulador em C++ de escalonamento de tarefas periódicas. A cada unidade de tempo a CPU escolhe, entre as tarefas liberadas, a de menor deadline, e o programa mostra a grade de execução com o número de preempções e de trocas de contexto.

## Contexto

Trabalho da disciplina **Sistemas de Tempo Real** (PUCRS), 6º semestre de Engenharia de Computação. A estrutura das classes `Cpu` e `Task` partiu do código base do Prof. Roland Teodorowitsch.

## Autor

- Lukas Ely

## Tecnologias

- C++17
- Make

## Como compilar e executar

```sh
make
./bin/main < entrada.txt
```

Formato da entrada: uma linha com `<número de tarefas> <tempo de simulação>`, seguida de uma linha por tarefa com `<computação> <período> <deadline>`. A entrada termina com `0 0`.

Exemplo:

```
2 10
1 4 4
2 6 6
0 0
```

## Estrutura de pastas

```
.
├── include/
│   ├── Cpu.hpp    estado da CPU e contadores
│   └── Task.hpp   tarefa periódica
├── src/
│   ├── Cpu.cpp    seleção da tarefa e execução por unidade de tempo
│   ├── Task.cpp
│   └── main.cpp   leitura da entrada e laço de simulação
└── Makefile
```
