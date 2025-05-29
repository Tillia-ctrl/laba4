#include <iostream>
#include "phone_call.h"
#include "file_reader.h"
#include "filters.h"
#include "sort.h"
#include "printer.h"

using namespace std;

int main() {
        cout << "Laboratory work #8. GIT\n";
        cout << "Variant #9. Telephone\n";
        cout << "Author: Menshikova Polina 24Pi1d\n";
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа. Обработка телефонных разговоров\n\n";

    PhoneCall* calls[MAX_FILE_ROWS_COUNT];
    int size;

    try {
        readCallsFromFile("data.txt", calls, size);

        int choice;
        do {
            cout << "\nМеню:\n";
            cout << "1. Вывести все телефонные разговоры на мобильные телефоны\n";
            cout << "2. Вывести все телефонные разговоры в ноябре 2021 года\n";
            cout << "3. Сортировка по убыванию продолжительности (Heap sort)\n";
            cout << "4. Сортировка по убыванию продолжительности (Quick sort)\n";
            cout << "5. Сортировка по номеру и стоимости (Heap sort)\n";
            cout << "6. Сортировка по номеру и стоимости (Quick sort)\n";
            cout << "0. Выход\n";
            cout << "Выберите действие: ";
            cin >> choice;

            PhoneCall* result[MAX_FILE_ROWS_COUNT];
            int result_size;

            switch (choice) {
            case 1:
                filterMobileCalls(calls, size, result, result_size);
                cout << "\nТелефонные разговоры на мобильные телефоны:\n";
                printCalls(result, result_size);
                break;
            case 2:
                filterNovember2021Calls(calls, size, result, result_size);
                cout << "\nТелефонные разговоры в ноябре 2021 года:\n";
                printCalls(result, result_size);
                break;
            case 3:
                heapSort(calls, size);
                cout << "\nСортировка по убыванию продолжительности (Heap sort):\n";
                printCalls(calls, size);
                break;
            case 4:
                quickSort(calls, 0, size - 1);
                cout << "\nСортировка по убыванию продолжительности (Quick sort):\n";
                printCalls(calls, size);
                break;
            case 5:
                heapSort(calls, size, false);
                cout << "\nСортировка по номеру и стоимости (Heap sort):\n";
                printCalls(calls, size);
                break;
            case 6:
                quickSort(calls, 0, size - 1, false);
                cout << "\nСортировка по номеру и стоимости (Quick sort):\n";
                printCalls(calls, size);
                break;
            case 7: { // Новый пункт меню
                double avgCost = calculateAverageCostPerSecond(calls, size);
                cout << "Средняя стоимость секунды разговора: " << avgCost << " руб.\n";
                break;
            }
            case 0:
                cout << "Выход из программы." << endl;
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова." << endl;
            }
        } while (choice != 0);

        // Освобождение памяти
        for (int i = 0; i < size; i++) {
            delete calls[i];
        }
    }
    catch (const char* error) {
        cout << error << endl;
    }

    return 0;
}