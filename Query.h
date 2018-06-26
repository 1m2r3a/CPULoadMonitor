#ifndef QUERY_HELPER
#define QUERY_HELPER

#include <Pdh.h>
#include <vector>
#include <QDebug>
#include "CounterInfo.h"
#include "Helper.h"
#define SAMPLE_INTERVAL 1

using namespace std;

class Query
{
private:
    HANDLE Event;
    PDH_HQUERY query;

public:

    Query()  {
    }

    void Init() {

        PDH_STATUS status;

        status = PdhOpenQuery(NULL, 0, &query);

        if (status != ERROR_SUCCESS)
            return;

        Event = CreateEvent(NULL, FALSE, FALSE, L"MyEvent");

        if (Event == NULL)
           return;
    }


    void AddCounterInfo(PCWSTR name, CounterInfo &ci) {
        PDH_STATUS status;

        ci.counterName = name;
        status = PdhAddCounter(query, ci.counterName, 0, &ci.counter);

        if (status != ERROR_SUCCESS)
            return;

    }

    double getRecord(CounterInfo ci) {
        PDH_STATUS status;
        ULONG CounterType;
        ULONG WaitResult;
        PDH_FMT_COUNTERVALUE DisplayValue;

        status = PdhCollectQueryData(query);
        if (status != ERROR_SUCCESS)
            return -1;

        status = PdhCollectQueryDataEx(query, SAMPLE_INTERVAL, Event);
        if (status != ERROR_SUCCESS)
            return -2;

        WaitResult = WaitForSingleObject(Event, INFINITE);

        if (WaitResult == WAIT_OBJECT_0)
        {
            status = PdhGetFormattedCounterValue(ci.counter, PDH_FMT_DOUBLE, &CounterType, &DisplayValue);
            //qDebug(" %f %ls\n", DisplayValue.doubleValue, ci.counterName);

            if (status == ERROR_SUCCESS)
                return DisplayValue.doubleValue;
        }

        return -1;
    }
};
#endif



