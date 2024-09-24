#include "../AsyncLog.h"

void testLog() {
    AsyncLog::init("./log/");
    // Log("this is a Log");
    // LogDebug("this is a LogDebug");
    // LogInfo("this is a LogInfo");
    // LogWarn("this is a LogWarn");
    // LogError("this is a LogError");
}

int main() {
    testLog();
}