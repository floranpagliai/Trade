#include "Trader.h"

Trader::Action Trader::technicalAnalysis() {
    if (_stockPrices.size() >= 26) {
        float macd = MACD(12, 26);
        _macd.push_back(MACD(12, 26));
        std::stringstream log;
        log << "[MACD] " << macd;
        _logger->writeLog(log.str());
        log.str("");
        if (_stockPrices.size() > 35) {
            float signalLine = exponentialMovingAverage(9, _macd);
            log << "[Signal Line] " << signalLine;
            _logger->writeLog(log.str());
            if (macd <= signalLine)
                return BUY;
            else if (macd >= signalLine)
                return SELL;
            else
                return WAIT;
        }
        return WAIT;
    }
    return WAIT;
}

float Trader::movingAverage(int days) {
    float movingAverage = 0;

    for (int i = 0; i < days - 1; i++) {
        movingAverage += _stockPrices[i];
    }
    movingAverage /= days;
    std::stringstream log;

    return movingAverage;
}

float Trader::exponentialMovingAverage(int days, vector<int> stockPrices) {
    float exponentialMovingAverage = 0;
    int coeff = 0;
    int i = stockPrices.size() - days;

    for (int n = 0; n < days; n++) {
        exponentialMovingAverage += stockPrices[i++] * (n + 1);
        coeff += (n + 1);
    }
    exponentialMovingAverage /= coeff;
    return exponentialMovingAverage;
}

float Trader::MACD(int EMAShort, int EMALong) {
    return exponentialMovingAverage(EMAShort, _stockPrices) - exponentialMovingAverage(EMALong, _stockPrices);
}

int Trader::moneyManagement() {
  return (_capital / _stockPrice)/2;
}
