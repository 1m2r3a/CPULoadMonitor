#ifndef HELPER_H
#define HELPER_H

#include <Windows.h>
#include <vector>

#define SIZE 1024

using namespace std;

DWORD GetProcessorCount();

vector<PCTSTR> GetProcessNames();

vector<PCTSTR> GetValidCounterNames();

#endif
