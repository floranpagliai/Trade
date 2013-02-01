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
    _days = 0;

    stringstream   log;
    log << "[Capital]\t" << capital << endl << "DING DING !";
    _logger->writeLog(log.str());
}

Trader::~Trader() {
}


