#include "Trader.h"

Trader::Action  Trader::technicalAnalysis() {
    if (_stockPrices.size() >= 26)
    {
    std::stringstream	log;
    log << "[MACD] " << MACD(12, 26);
    _logger->writeLog(log.str());
    }
    return WAIT;
}

float             Trader::movingAverage() {
    float         average = 0;

    for (int i = 0; i < _stockPrices.size() - 1; i++)
    {
        average += _stockPrices[i];
    }
   average /= _stockPrices.size();
   std::stringstream	log;
   log << "[movingAverage] " << average;
   _logger->writeLog(log.str());
   return average;
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