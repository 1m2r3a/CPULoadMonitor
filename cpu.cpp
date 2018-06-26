#include "cpu.h"

CPU::CPU() : processorsNumber(0)
{

}
void CPU::init()
{
    processorsNumber = GetProcessorCount();
    //qDebug("Number of processorsssss: %ld\n", processorsNumber);
    std::wstring name( L"\\Processor(_Total)\\% Processor Time" );
    /*To get the processor time or the idle time a string with a certain format must be provided
    * To get the total processor time \Processor(_Total)\% Processor Time
    * or 0-NumberOfProcessor instead of total
    * To get the total idle time \Processor(_Total)\% Idle Time
    * same principle as above can be applied
    */

    //init the total
    Thread* thread = new Thread();
    thread->setName("_Total");
    std::ostringstream oss;

    oss << "\\Processor(" << thread->getName()<< ")\\% Processor Time";
    std::string temp = oss.str();

    std::wstring statement(temp.begin(), temp.end());
    thread->setProcessorTimeName(statement.c_str());
    oss.clear(); oss.str("");

    oss << "\\Processor(" << thread->getName() << ")\\% Idle Time";
    temp = oss.str();
    statement.assign(temp.begin(), temp.end());
    thread->setIdleName(statement.c_str());
    qDebug("%ls", thread->getProcessorTimeName().c_str());
    threads.push_back(thread);
    //each Thread
    for(unsigned char i = 0; i < processorsNumber; i++)
    {
        qDebug("%ls", thread->getProcessorTimeName().c_str());
        qDebug("%ls", thread->getIdleName().c_str());
        thread = new Thread();
        thread->setName(std::to_string(i));
        oss.clear(); oss.str("");
        oss << "\\Processor(" << thread->getName()<< ")\\% Processor Time";
        std::string temp = oss.str();

        std::wstring statement(temp.begin(), temp.end());
        thread->setProcessorTimeName(statement.c_str());
        oss.clear(); oss.str("");

        oss << "\\Processor(" << thread->getName() << ")\\% Idle Time";
        temp = oss.str();
        statement.assign(temp.begin(), temp.end());
        thread->setIdleName(statement.c_str());
        threads.push_back(thread);
    }

    threads.at(0)->queryTheQuery();
}

#include <intrin.h>
unsigned char CPU::GetProcessorCount()
{
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);

    return sysinfo.dwNumberOfProcessors;

}



