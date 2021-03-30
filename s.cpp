#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <algorithm>

using namespace std;

class Error
{
public:
    Error(string error);
};

class Command
{
private:
    map<string, string> commands{{"gcm", "git commit -am"}, {"gcma", "git commit --amend"}, {"gch", "git checkout"}, {"gchb", "git checkout -b"}};

public:
    string getCommand(string key) { return commands[key]; }
    void run(string cmd);
    void run(string cmd, string arg);
};

class String
{
private:
    static const string WHITESPACE;

    static string ltrim(string s);
    static string rtrim(string s);
public:
    static string trim(string s);
};
const string String::WHITESPACE = " \r\t\f\v";


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
    if(String::trim(arg).find(" ") != string::npos)
        arg = "\"" + arg + "\"";

    string command = getCommand(cmd) + " " + arg;

    char *runnableCommand;
    runnableCommand = &command[0];
    system(runnableCommand);
}


string String::ltrim(string s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
string String::rtrim(string s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
string String::trim(string s)
{
    return rtrim(ltrim(s));
}
 