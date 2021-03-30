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
    map<string, string> commands{
        {"gaa", "git add -A"},
        {"gcm", "git commit -am"}, {"gcma", "git commit --amend"},
        {"gch", "git checkout"}, {"gchb", "git checkout -b"},
        {"glo", "git log --oneline"}, {"glop", "git log --pretty=format:\"%h  %cr  %cn : %s\""},
        {"gps", " git push --set-upstream origin"}
    };

public:
    string getCommand(string key)
    {
        string cmd = commands[key];
        if (cmd != "")
            return cmd;
        else
            Error("La commande est introuvable");
        return "";
    }
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
