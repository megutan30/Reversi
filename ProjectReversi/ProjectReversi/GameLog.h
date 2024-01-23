#ifndef GAMELOG_H
#define GAMELOG_H

#include<string>
#include <vector>

struct LogEntry {
	int turnNumber;
	std::string action;
};

class GameLog {
public:
    static void addLog(const std::string& action);
    static void displayLog();

private:
    static std::vector<LogEntry> entries;
};
#endif