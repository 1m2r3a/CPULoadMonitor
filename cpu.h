#ifndef CPU_H
#define CPU_H


#include <vector>

#include "Thread.h"

using namespace std;
class CPU
{
public:

    CPU();
    void init();

    std::vector<Thread*>::const_iterator getThread(int index);
    std::vector<Thread*> threads;

private:
    unsigned char GetProcessorCount();

    unsigned char processorsNumber;

};

#endif // CPU_H
