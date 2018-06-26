#ifndef PERFORMANCE_COUNTER_H
#define PERFORMANCE_COUNTER_H

#include <Pdh.h>
#include <vector>


using namespace std;

class CounterInfo
{
public:
    CounterInfo() { };
    PCWSTR counterName;

    PDH_HCOUNTER counter;
};


#endif
