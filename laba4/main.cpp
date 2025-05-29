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
    cout << "������������ ������. ��������� ���������� ����������\n\n";

    PhoneCall* calls[MAX_FILE_ROWS_COUNT];
    int size;

    try {
        readCallsFromFile("data.txt", calls, size);

        int choice;
        do {
            cout << "\n����:\n";
            cout << "1. ������� ��� ���������� ��������� �� ��������� ��������\n";
            cout << "2. ������� ��� ���������� ��������� � ������ 2021 ����\n";
            cout << "3. ���������� �� �������� ����������������� (Heap sort)\n";
            cout << "4. ���������� �� �������� ����������������� (Quick sort)\n";
            cout << "5. ���������� �� ������ � ��������� (Heap sort)\n";
            cout << "6. ���������� �� ������ � ��������� (Quick sort)\n";
            cout << "0. �����\n";
            cout << "�������� ��������: ";
            cin >> choice;

            PhoneCall* result[MAX_FILE_ROWS_COUNT];
            int result_size;

            switch (choice) {
            case 1:
                filterMobileCalls(calls, size, result, result_size);
                cout << "\n���������� ��������� �� ��������� ��������:\n";
                printCalls(result, result_size);
                break;
            case 2:
                filterNovember2021Calls(calls, size, result, result_size);
                cout << "\n���������� ��������� � ������ 2021 ����:\n";
                printCalls(result, result_size);
                break;
            case 3:
                heapSort(calls, size);
                cout << "\n���������� �� �������� ����������������� (Heap sort):\n";
                printCalls(calls, size);
                break;
            case 4:
                quickSort(calls, 0, size - 1);
                cout << "\n���������� �� �������� ����������������� (Quick sort):\n";
                printCalls(calls, size);
                break;
            case 5:
                heapSort(calls, size, false);
                cout << "\n���������� �� ������ � ��������� (Heap sort):\n";
                printCalls(calls, size);
                break;
            case 6:
                quickSort(calls, 0, size - 1, false);
                cout << "\n���������� �� ������ � ��������� (Quick sort):\n";
                printCalls(calls, size);
                break;
            case 7: { // ����� ����� ����
                double avgCost = calculateAverageCostPerSecond(calls, size);
                cout << "������� ��������� ������� ���������: " << avgCost << " ���.\n";
                break;
            }
            case 0:
                cout << "����� �� ���������." << endl;
                break;
            default:
                cout << "�������� �����. ���������� �����." << endl;
            }
        } while (choice != 0);

        // ������������ ������
        for (int i = 0; i < size; i++) {
            delete calls[i];
        }
    }
    catch (const char* error) {
        cout << error << endl;
    }

    return 0;
}