#ifndef FILTERS_H
#define FILTERS_H

#include "phone_call.h"

void filterMobileCalls(PhoneCall* source[], int source_size, PhoneCall* result[], int& result_size);
void filterNovember2021Calls(PhoneCall* source[], int source_size, PhoneCall* result[], int& result_size);

#endif
