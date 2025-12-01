#ifndef PRETTIEST_H
#define PRETTIEST_H

#include <iostream>

inline void log(std::string msg) { std::cout << "\x1b[32m>>> " + msg + "\x1b[m" << std::endl; }
inline void error(std::string msg) { std::cout << "\x1b[41m!!! " + msg + "\x1b[m" << std::endl; }
inline void warn(std::string msg) { std::cout << "\x1b[1;33m... " + msg + "\x1b[m" << std::endl; }

#endif