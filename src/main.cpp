/*
 * File:   main.cpp
 * Author: floran
 *
 * Created on 31 janvier 2013, 03:25
 */

#include <iostream>
#include <stdlib.h>
#include "Trade.h"

using namespace std;

int main(int argc, char** argv) {
    char        buffer[256];
    cin.getline(buffer, 256);
    int         capital = atoi(buffer);
    Trade trader(capital);
    return 0;
}
