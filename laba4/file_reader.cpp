#include "file_reader.h"
#include "constants.h"
#include <fstream>
#include <cstring>

void readCallsFromFile(const char* file_name, PhoneCall* array[], int& size) {
    std::ifstream file(file_name);
    if (file.is_open()) {
        size = 0;
        char dot, colon;
        while (!file.eof() && size < MAX_FILE_ROWS_COUNT) {
            PhoneCall* call = new PhoneCall;
            file >> call->number;
            file >> call->date.day >> dot >> call->date.month >> dot >> call->date.year;
            file >> call->time.hours >> colon >> call->time.minutes >> colon >> call->time.seconds;
            file >> call->duration.hours >> colon >> call->duration.minutes >> colon >> call->duration.seconds;
            file >> call->tariff;
            file >> call->cost_per_minute;

            // Рассчитываем общую стоимость
            int total_seconds = call->duration.hours * 3600 + call->duration.minutes * 60 + call->duration.seconds;
            double total_minutes = total_seconds / 60.0;
            if (total_seconds % 60 != 0) total_minutes += 1; // Округляем вверх
            call->total_cost = total_minutes * call->cost_per_minute;

            array[size++] = call;
        }
        file.close();
    }
    else {
        throw "Ошибка открытия файла";
    }
}