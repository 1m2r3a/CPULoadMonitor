#ifndef THREAD_H
#define THREAD_H

#include <vector>
#include <QString>
#include <sstream>

#include "Query.h"
#include "Helper.h"

using namespace std;
class Thread
{
public:
    Thread();
    unsigned char getLoad();
    void setLoad(unsigned char value);

    unsigned char getIdle() const;
    void setIdle(unsigned char value);

    std::string getName() const;
    void setName(const std::string &value);

    std::wstring getIdleName() const;
    void setIdleName(const std::wstring &value);

    std::wstring getProcessorTimeName() const;
    void setProcessorTimeName(const std::wstring &value);

    void queryTheQuery();
    Query query;
    CounterInfo getCounterInfo() const;
    void setCounterInfo(const CounterInfo &value);

private:
    unsigned char load;
    unsigned char idle;

    CounterInfo counterInfo;
    std::string name;
    std::wstring idleName, processorTimeName; // TO DO: refactor
};
#endif // THREAD_H
