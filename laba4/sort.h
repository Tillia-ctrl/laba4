#ifndef SORT_H
#define SORT_H

#include "phone_call.h"

void heapSort(PhoneCall* array[], int size, bool byDuration = true);
void quickSort(PhoneCall* array[], int low, int high, bool byDuration = true);

#endif
