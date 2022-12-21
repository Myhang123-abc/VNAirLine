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
#include <iomanip>
#include <algorithm>

#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

using namespace std;

#define _USE_MATH_DEFINES
#define MAX 20 //So thanh pho trong lop RandomGenerator

template <typename T> std::string to_string(const T& t) //Ham to_string() chuyen cac kieu du lieu ve dang string
{
    std::ostringstream os; os << t; return os.str();
}