#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <chrono>

#define DTYPE_PHYSICAL 0;
#define DTYPE_FIRE 1;
#define DTYPE_FROST 2;
#define DTYPE_NATURE 3;
#define DTYPE_SHADOW 4;
#define DTYPE_ARCANE 5;
#define DTYPE_VOID 6;

int getIntFromString(std::string s);
std::vector<std::string> split(const std::string& s, char seperator);