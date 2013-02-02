/*
** Logger.h for Logger in /home/paglia_f//Work/ProgElemApp/Trade/src
**
** Made by floran pagliai
** Login   <paglia_f@epitech.net>
**
** Started on  Thu Jan 31 17:00:26 2013 floran pagliai
** Last update Thu Jan 31 17:16:28 2013 floran pagliai
*/

#ifndef __LOGGER_H_
#define __LOGGER_H_

#include <iostream>
#include <fstream>
#include <string>

class Logger {
 private:
  std::string	_fileName;

 public:
  Logger(std::string fileName);
  ~Logger();

  void		writeLog(std::string const &);
};

#endif
