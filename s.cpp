#include "s.h"

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

void Command::run(string cmd, string arg)
{
    if (String::trim(arg).find(" ") != string::npos)
        arg = "\"" + arg + "\"";

    string command = getCommand(cmd) + " " + arg;

    char *runnableCommand;
    runnableCommand = &command[0];
    system(runnableCommand);
}
