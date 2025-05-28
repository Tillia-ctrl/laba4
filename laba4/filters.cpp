#include "filters.h"
#include <cstring>  // или #include <string.h> для функции strcmp()

void filterMobileCalls(PhoneCall* source[], int source_size, PhoneCall* result[], int& result_size) {
    result_size = 0;
    for (int i = 0; i < source_size; i++) {
        if (strcmp(source[i]->tariff, "мобильный") == 0) {
            result[result_size++] = source[i];
        }
    }
}

void filterNovember2021Calls(PhoneCall* source[], int source_size, PhoneCall* result[], int& result_size) {
    result_size = 0;
    for (int i = 0; i < source_size; i++) {
        if (source[i]->date.month == 11 && source[i]->date.year == 2021) {
            result[result_size++] = source[i];
        }
    }
}