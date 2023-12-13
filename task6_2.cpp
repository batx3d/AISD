
#include <iostream>
#include <queue>
#include <string>

using namespace std;

// ����� ��� ������������� �������
class Command {
public:
    int number;

    Command(int num) : number(num) {}
};

// ����� ��� ������������� ������� ���������
class Stage {
public:
    string name;
    Command* command;

    Stage(string stageName) : name(stageName), command(nullptr) {}
    Stage() : name(""), command(nullptr) {}
};

// ����� ��� ������������� ���������
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

    // ������� ��� ���������� ���������
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
    // ������� ��� ����������� ������ ����� ��������
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

    // ������� ��� ����������� �����������
    void displayResults()
    {
        if (stages[4].command != nullptr)
        {
            cout << "Command " << stages[4].command->number << " completed!\n\n";
            delete stages[4].command;  // ����������� ������ �������
            stages[4].command = nullptr;
        }
    }
};

int main()
{
    Pipeline pipeline;

    // ��������� ������� ���������
    for (int i = 1; i <= 10; ++i)
    {
        pipeline.commandQueue.push(new Command(i));
    }

    // ��������� ��������
    pipeline.executePipeline();

    return 0;
}
