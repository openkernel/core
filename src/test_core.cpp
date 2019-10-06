/*
 * Logger_test.cpp
 *
 *  Created on: Aug 17, 2016
 *      Author: vasu
 */

#include <Logger.hpp>
const char * const __MODULE__ = "TESTCORE";

using namespace okcore;
int main(int ac, const char *av[])
{
    Logger::init();
    logError("This is some ERROR");
    logInfo("This is some INFO");
    logDebug("This is some DEBUG");
    Logger::setLevel(Logger::INFO);
    logError("This is some ERROR");
    logInfo("This is some INFO");
    logDebug("This is some DEBUG");
    Logger::setLevel(Logger::DEBUG);
    logError("This is some ERROR");
    logInfo("This is some INFO");
    logDebug("This is some DEBUG");

}


