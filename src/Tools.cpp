/*
 * File:   Tools.cpp
 * Author: floran
 *
 * Created on 2 février 2013, 04:12
 */

#include "Trader.h"

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
      log << "[Pivot] " << pivot << " -->SELL";
      _logger->writeLog(log.str());
      return (Trader::SELL);
    }
  else
  {
  log << "[Pivot] " << pivot << " -->BUY";
  _logger->writeLog(log.str());
  return (Trader::BUY);
  }
}

Trader::Action  Trader::movingAverage() {
    int average;
    for (size_t i = 0; i <= _stockPrices.size(); i++)
    {
        average += _stockPrices[i];
    }
   average = average / _stockPrices.size();
    std::stringstream	log;
    log << "[Average] " << average;
    _logger->writeLog(log.str());
   if (_stockPrice < average)
       return Trader::BUY;
   else if (_stockPrice > average)
       return Trader::SELL;
   else
       return Trader::WAIT;

}