/*
 * File:   main.cpp
 * Author: floran
 *
 * Created on 31 janvier 2013, 03:25
 */

#include "Logger.h"
#include "Trader.h"

using namespace std;

int main(int argc, char** argv) {
  Logger	logger("log.txt");
  char		buffer[256];
  cin.getline(buffer, 256);
  int		capital = atoi(buffer);
  Trader	trader(capital, &logger);

  trader.Trade();
  return 0;
}
