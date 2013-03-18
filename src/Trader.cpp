//
// Trade.cpp for Trade in /home/paglia_f//Work/ProgElemApp/Trade/src
//
// Made by floran pagliai
// Login   <paglia_f@epitech.net>
//
// Started on  Thu Jan 31 17:16:57 2013 floran pagliai
// Last update Mon Mar 18 16:25:37 2013 floran pagliai
//

#include "Trader.h"

Trader::Trader(int capital, Logger *logger) : _logger(logger) {
    _capital = capital;
    _stock = 0;
    _days = -1;
    stringstream log;
    log << "[Capital]\t" << _capital;
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

/*----FUNCTIONS----*/
void    Trader::Trade() {
    char buffer[256];
    std::string value;
    stringstream log;
    int day = 0;

    while (day != _days - 1) {
        cin.getline(buffer, 256);
        value = buffer;
        if (_days == -1) {
            _days = atoi(buffer);
            log << "[Period]\t" << _days << endl;
            _logger->writeLog(log.str());
            log.str("");
        } else {
            _stockPrice = atoi(buffer);
            _stockPrices.push_back(_stockPrice);
            log << endl << "--Day " << day + 1 << "--" << endl << "[Capital] " << _capital << endl
                    << "[Stock]\t" << _stockPrice;
            _logger->writeLog(log.str());
            log.str("");
            switch (technicalAnalysis()) {
                case BUY: buy(moneyManagement());
                    break;
                case SELL: sell(_stock);
                    break;
                case WAIT: cout << "wait " << endl;
                    break;
            }
            if (_stockPrice == 0)
                break;
            ++day;
        }
    }
    log << endl << "--Day " << day + 1 << "--" << endl;
    _logger->writeLog(log.str());
    sell(_stock);
}

void    Trader::buy(int stock) {
    std::stringstream log;
    //stock -= 1;
    if ((_capital - (0.15 / 100 * _capital)) >= stock * _stockPrice && stock > 0) {
        log << "==>BUY " << stock << " for " << stock * _stockPrice << "euros";
        _logger->writeLog(log.str());
        cout << "buy " << stock << endl;
	_stock += stock;        
	_capital -= stock * _stockPrice;
        _capital = _capital - (0.15 / 100 * (stock * _stockPrice));
        
    } else
        cout << "wait" << endl;
}

void    Trader::sell(int stock) {
    std::stringstream log;
    if (_stock >= stock && stock > 0) {
        log << "==>SELL " << stock << " for " << stock * _stockPrice << "euros";
        _logger->writeLog(log.str());
        cout << "sell " << stock << endl;
	_stock -= stock;        
	_capital += stock * _stockPrice;
        _capital = _capital - (0.15 / 100 * (stock * _stockPrice));
    } else
        cout << "wait" << endl;
}
