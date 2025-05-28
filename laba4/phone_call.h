#ifndef PHONE_CALL_H
#define PHONE_CALL_H

#include "constants.h"

struct PhoneCall {
    char number[MAX_STRING_SIZE];
    struct {
        int day;
        int month;
        int year;
    } date;
    struct {
        int hours;
        int minutes;
        int seconds;
    } time;
    struct {
        int hours;
        int minutes;
        int seconds;
    } duration;
    char tariff[MAX_STRING_SIZE];
    double cost_per_minute;
    double total_cost;
};

#endif
