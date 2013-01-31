/*
 * File:   Trade.h
 * Author: floran
 *
 * Created on 31 janvier 2013, 15:38
 */

#ifndef __TRADE_H__
#define	__TRADE_H__

class Trade {
private:
    int         _capital;
    int         _days;

public:
    Trade(int capital);
    virtual ~Trade();
};

#endif	/* __TRADE_H__ */

