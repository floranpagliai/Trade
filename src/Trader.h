#ifndef __TRADER_H__
#define	__TRADER_H__

#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include "Logger.h"

using namespace std;

class Trader {
public:
    Trader(int capital, Logger *logger);
    virtual ~Trader();

    int         getCapital() const;
    int         getDays() const;

    enum	Action {
    BUY,
    SELL,
    WAIT
    };

    void        Trade();
    void        buy(int);
    void        sell(int);

    Action      technicalAnalysis();
    float       movingAverage();
    float       exponentialMovingAverage(int);
    float       MACD(int, int);

 protected:
    int         _capital;
    int         _days;
    int         _stock;
    int         _stockPrice;
    vector<int>	_stockPrices;

    Logger      *_logger;
};

#endif	/* __TRADER_H__ */

