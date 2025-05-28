#include "printer.h"
#include <iomanip>
#include <iostream>

using namespace std;

void printCalls(PhoneCall* array[], int size) {
    cout << left << setw(15) << "�����" << setw(12) << "����" << setw(12) << "�����"
        << setw(15) << "�����������������" << setw(15) << "�����" << setw(10) << "���������" << endl;
    cout << string(80, '-') << endl;

    for (int i = 0; i < size; i++) {
        PhoneCall* call = array[i];
        cout << left << setw(15) << call->number
            << setw(2) << call->date.day << "." << setw(2) << call->date.month << "." << setw(6) << call->date.year
            << setw(2) << call->time.hours << ":" << setw(2) << call->time.minutes << ":" << setw(6) << call->time.seconds
            << setw(2) << call->duration.hours << ":" << setw(2) << call->duration.minutes << ":" << setw(11) << call->duration.seconds
            << setw(15) << call->tariff
            << fixed << setprecision(2) << call->total_cost << " ���." << endl;
    }
}