#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <list>

using namespace std;

#define MAX 5 //So thanh pho trong lop RandomGenerator

template <typename T> std::string to_string(const T& t) //Ham to_string() chuyen cac kieu du lieu ve dang string
{
    std::ostringstream os; os << t; return os.str();
}
