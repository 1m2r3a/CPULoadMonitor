#include "Thread.h"

Thread::Thread() : name(""), load(0), idle(0)
{

}

unsigned char Thread::getLoad()
{
    return load;
}

void Thread::setLoad(unsigned char value)
{
    load = value;
}

unsigned char Thread::getIdle() const
{
    return idle;
}

void Thread::setIdle(unsigned char value)
{
    idle = value;
}

std::string Thread::getName() const
{
    return name;
}

void Thread::setName(const std::string &value)
{
    name = value;
}

std::wstring Thread::getIdleName() const
{
    return idleName;
}

void Thread::setIdleName(const std::wstring &value)
{
    idleName = value;
}

std::wstring Thread::getProcessorTimeName() const
{

    return processorTimeName;
}

void Thread::setProcessorTimeName(const std::wstring &value)
{
    processorTimeName = value;
}

void Thread::queryTheQuery()
{
    query.Init();
    query.AddCounterInfo(processorTimeName.c_str(), counterInfo);
    qDebug(">>>>>>>>>>>>>>>%ls",processorTimeName.c_str());
}

CounterInfo Thread::getCounterInfo() const
{
    return counterInfo;
}

void Thread::setCounterInfo(const CounterInfo &value)
{
    counterInfo = value;
}
