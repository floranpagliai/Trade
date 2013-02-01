//
// Logger.cpp for Logger in /home/paglia_f//Work/ProgElemApp/Trade/src
//
// Made by floran pagliai
// Login   <paglia_f@epitech.net>
//
// Started on  Thu Jan 31 17:07:27 2013 floran pagliai
// Last update Thu Jan 31 18:14:13 2013 floran pagliai
//

#include "Logger.h"

using namespace std;

Logger::Logger(std::string fileName) {
  _fileName = fileName;

  ofstream	logFile;

  logFile.open(_fileName.c_str(), ios::out);
  logFile << "ROBOT TRADER QUANTUM LOG" << std::endl;
  logFile.close();
}

Logger::~Logger() {
}

void	Logger::writeLog(std::string const &log) {
  ofstream	logFile;

  logFile.open(_fileName.c_str(), ios::app | ios::out);
  logFile << log << std::endl;
  logFile.close();
}
