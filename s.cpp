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
    if (String::trim(arg).find(" ") != string::npos)
        arg = "\"" + arg + "\"";

    string command = getCommand(cmd) + " " + arg;

    char *runnableCommand;
    runnableCommand = &command[0];
    system(runnableCommand);
}

string String::ltrim(string s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == string::npos) ? "" : s.substr(start);
}

string String::rtrim(string s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}

string String::trim(string s)
{
    return rtrim(ltrim(s));
}
