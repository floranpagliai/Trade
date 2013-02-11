#include "Trader.h"

Trader::Action  Trader::technicalAnalysis() {
    float       mAverage = movingAverage();;
    float       eMAverage = exponentialMovingAverage(26);

    if (_stockPrices.size() >= 26)
    {
    if (eMAverage >= mAverage)
        return BUY;
    else if (eMAverage <= mAverage)
        return SELL;
    else
        return WAIT;
    }
    return WAIT;
}

float             Trader::movingAverage() {
    float         movingAverage = 0;

    for (int i = 0; i < _stockPrices.size() - 1; i++)
    {
        movingAverage += _stockPrices[i];
    }
   movingAverage /= _stockPrices.size();
   std::stringstream	log;
   log << "[movingAverage] " << movingAverage;
   _logger->writeLog(log.str());
   return movingAverage;
}

float           Trader::MACD(int EMAShort, int EMALong) {
    return exponentialMovingAverage(EMAShort) - exponentialMovingAverage(EMALong);
}

float             Trader::exponentialMovingAverage(int days) {
    float         exponentialMovingAverage = 0;
    int         coeff = 0;
    int      i = _stockPrices.size() - days;

    for (int n = 0; n < days; n++)
    {
        exponentialMovingAverage += _stockPrices[i++] * (n + 1);
        coeff += (n + 1);
    }
    exponentialMovingAverage /= coeff;
    std::stringstream	log;
    log << "[exponentialMovingAverage " << days << "] " << exponentialMovingAverage;
    _logger->writeLog(log.str());
   return exponentialMovingAverage;
}