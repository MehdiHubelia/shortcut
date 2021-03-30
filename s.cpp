#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <map>

using namespace std;

class Error
{
public:
    Error(string error);
};

class Command
{
private:
    map<string, string> commands{{"gcm", "git commit -am"}, {"gch", "git checkout"}, {"gchb", "git checkout -b"}};

public:
    string getCommand(string key) { return commands[key]; }
    void run(string cmd);
    void run(string cmd, string arg);
};

int main(int argc, char *argv[])
{
    if (argc <= 1)
        Error("Un argument est attendu.");
    else if (argc == 2)
    {
        Command cmd;
        cmd.run(argv[1]);
    }
    else
    {
        Command cmd;
        cmd.run(argv[1], argv[argc - 1]);
    }
}

Error::Error(string error)
{
    std::cout << error << std::endl;
    exit(1);
}

void Command::run(string cmd)
{
    run(cmd, "");
}

void Command::run(string cmd, string arg)
{
    string command = getCommand(cmd) + " " + arg;

    std::cout << command << std::endl;
    system("pwd");

    char *runnableCommand;
    runnableCommand = &command[0];
    system(runnableCommand);
}