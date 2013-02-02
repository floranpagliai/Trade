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

Trader::Trader(int capital, Logger *logger) : _logger(logger) {
    _capital = capital;
    _days = -1;

    stringstream   log;
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
  char		buffer[256];
  std::string   value;
  stringstream   log;
  int           day = 0;

  while(value.compare("--end--") != 0 && day != _days - 1)
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
      _stockPrice = atoi(buffer);
      _stockPrices.push_back(_stockPrice);
      log << "[Day " << day << "]\t" << _stockPrice;
      _logger->writeLog(log.str());
      log.str("");
      switch (pivotPoints()) {
          case BUY: buy(((_capital/2)/_stockPrice)); break;
          case SELL: sell(_stock); break;
          case WAIT: cout << "wait " << endl; break;
      }
      day++;
      }
  }
  log << "[Stock]\t" << _stock;
      _logger->writeLog(log.str());
  sell(_stock);
}

void    Trader::buy(int stock) {
    if (_capital >= stock * _stockPrice && stock > 0)
    {
        cout << "buy " << stock << endl;
        _capital -= stock * _stockPrice;
        _stock += stock;
    }
    else
        cout << "wait " << endl;
}

void    Trader::sell(int stock) {
    if (_stock >= stock)
    {
        cout << "sell " << stock << endl;
        _capital += stock * _stockPrice;
        _stock -= stock;
    }
    else
        cout << "wait " << endl;
}

Trader::Action  Trader::fourXTwo(int day) {
if (_stockPrices[day -1] < _stockPrices[day -2] < _stockPrices[day -3] < _stockPrices[day -4] && day >= 4)
    return Trader::BUY;
else
    return Trader::WAIT;
}

Trader::Action		Trader::pivotPoints()
{
  std::stringstream	log;
  int			minimum = _stockPrices.front();
  int			maximum = _stockPrices.front();
  int			last = _stockPrices.back() - 1;
  float			pivot, s1, s2, r1, r2;

  if (_stockPrices.size() < 3)
    return (Trader::WAIT);

  log.str("");
  for (size_t i = 0; i < _stockPrices.size() - 1; ++i)
    {
      minimum = _stockPrices[i] < minimum ? _stockPrices[i] : minimum;
      maximum = _stockPrices[i] > maximum ? _stockPrices[i] : maximum;
    }
  pivot = (minimum + maximum + last) / 3.0;
  s1 = (2 * pivot) - maximum;
  s2 = pivot - (maximum - minimum);
  r1 = (2 * pivot) - minimum;
  r2 = pivot + (maximum - minimum);

  if (pivot < _stockPrices.back())
    {
      log << "Le point pivot est a " << pivot << ". L'action est a " << _stockPrices.back() << ". Il faut vendre !";
      _logger->writeLog(log.str());
      return (Trader::SELL);
    }
  log << "Le point pivot est a " << pivot << ". L'action est a " << _stockPrices.back() << ". Il faut acheter !";
  _logger->writeLog(log.str());
  return (Trader::BUY);
}