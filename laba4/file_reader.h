#ifndef FILE_READER_H
#define FILE_READER_H

#include "phone_call.h"

void readCallsFromFile(const char* file_name, PhoneCall* array[], int& size);

#endif