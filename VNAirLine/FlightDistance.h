#pragma once
#ifndef FlightDistance_HEADER
#define FlightDistance_HEADER
#include "Header.h"
class FlightDistance
{
public:
    virtual string tostring(int)=0;
    void displayMeasurementInstructions();
};
#endif // !FlightDistance_HEADER



