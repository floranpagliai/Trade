/*
 * File:   Trade.h
 * Author: floran
 *
 * Created on 31 janvier 2013, 15:38
 */

#ifndef __TRADER_H__
#define	__TRADER_H__

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "Logger.h"

class Trader {
private:
    int         _capital;
    int         _days;
    Logger      *_logger;

public:
    Trader(int capital, Logger *logger);
    virtual ~Trader();

    int         getCapital() const;
    int         getDays() const;

    void        Trade();
};

#endif	/* __TRADER_H__ */

