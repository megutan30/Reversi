#include "GameLog.h"
#include <iostream>

using namespace std;

vector<LogEntry> GameLog::entries;

void GameLog::addLog(const std::string& action) {
    LogEntry entry;
    entry.turnNumber = entries.size() + 1;
    entry.action = action;
    entries.push_back(entry);
}

void GameLog::displayLog() {
    for (const auto& entry : entries) {
        cout << "Turn " << entry.turnNumber << ": " << entry.action << std::endl;
    }
}
