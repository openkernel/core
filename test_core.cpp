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
    logError("ERROR");
    logInfo("INFO");
    logDebug("DEBUG");
    Logger::setLevel(Logger::INFO);
    logError("ERROR");
    logInfo("INFO");
    logDebug("DEBUG");
    Logger::setLevel(Logger::DEBUG);
    logError("ERROR");
    logInfo("INFO");
    logDebug("DEBUG");

}


