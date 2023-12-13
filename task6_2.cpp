
#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Класс для представления команды
class Command {
public:
    int number;

    Command(int num) : number(num) {}
};

// Класс для представления ступени конвейера
class Stage {
public:
    string name;
    Command* command;

    Stage(string stageName) : name(stageName), command(nullptr) {}
    Stage() : name(""), command(nullptr) {}
};

// Класс для представления конвейера
class Pipeline {
public:
    queue<Command*> commandQueue;
    Stage stages[5];

    Pipeline()
    {
        for (int i = 0; i < 5; ++i)
        {
            stages[i] = Stage("C" + to_string(i + 1));
        }
    }

    // Функция для выполнения конвейера
    void executePipeline()
    {
        for (int cycle = 1; cycle <= 10; ++cycle)
        {
            cout << "Cycle " << cycle << ":\n";
            moveCommandsThroughPipeline();
            displayResults();
        }
    }

private:
    // Функция для перемещения команд через конвейер
    void moveCommandsThroughPipeline()
    {
        for (int i = 4; i >= 0; --i)
        {
            if (stages[i].command == nullptr && !commandQueue.empty())
            {
                stages[i].command = commandQueue.front();
                commandQueue.pop();
            }
        }
    }

    // Функция для отображения результатов
    void displayResults()
    {
        if (stages[4].command != nullptr)
        {
            cout << "Command " << stages[4].command->number << " completed!\n\n";
            delete stages[4].command;  // освобождаем память команды
            stages[4].command = nullptr;
        }
    }
};

int main()
{
    Pipeline pipeline;

    // Заполняем очередь командами
    for (int i = 1; i <= 10; ++i)
    {
        pipeline.commandQueue.push(new Command(i));
    }

    // Выполняем конвейер
    pipeline.executePipeline();

    return 0;
}
