//
// Trade.cpp for Trade in /home/paglia_f//Work/ProgElemApp/Trade/src
//
// Made by floran pagliai
// Login   <paglia_f@epitech.net>
//
// Started on  Thu Jan 31 17:16:57 2013 floran pagliai
// Last update Thu Jan 31 17:19:02 2013 floran pagliai
//

#include "Trader.h"

using namespace std;

Trader::Trader(int capital, Logger *logger) : _logger(logger) {
    _capital = capital;
    _days = -1;

    stringstream   log;
    log << "[Capital]\t" << _capital << endl << "DING DING !";
    _logger->writeLog(log.str());
}

Trader::~Trader() {
}

/*----GETTERS----*/
int     Trader::getCapital() const {
    return _capital;
}

int     Trader::getDays() const {
    return _days;
}

void    Trader::Trade() {
  char		buffer[256];
  std::string   value;
  stringstream   log;
  int           day = 1;

  while(value.compare("--end--") != 0 && day - 1 != _days)
  {
      cin.getline(buffer, 256);
      value = buffer;
      if (_days == -1) {
          _days = atoi(buffer);
          log << "[Period]\t" << _days << endl;
          _logger->writeLog(log.str());
          log.str("");
      }
      else {

      log << "[Day " << day << "]\t" << value;
      _logger->writeLog(log.str());
      log.str("");
      cout << "wait" << endl;
      day++;
      }

  }
}

