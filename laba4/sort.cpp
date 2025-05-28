#include "sort.h"
#include <algorithm>

using namespace std;

void heapify(PhoneCall* array[], int n, int i, bool byDuration) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (byDuration) {
        if (left < n && (array[left]->duration.hours * 3600 + array[left]->duration.minutes * 60 + array[left]->duration.seconds) >
            (array[largest]->duration.hours * 3600 + array[largest]->duration.minutes * 60 + array[largest]->duration.seconds))
            largest = left;

        if (right < n && (array[right]->duration.hours * 3600 + array[right]->duration.minutes * 60 + array[right]->duration.seconds) >
            (array[largest]->duration.hours * 3600 + array[largest]->duration.minutes * 60 + array[largest]->duration.seconds))
            largest = right;
    }
    else {
        if (left < n && (strcmp(array[left]->number, array[largest]->number) < 0 ||
            (strcmp(array[left]->number, array[largest]->number) == 0 && array[left]->total_cost > array[largest]->total_cost)))
            largest = left;

        if (right < n && (strcmp(array[right]->number, array[largest]->number) < 0 ||
            (strcmp(array[right]->number, array[largest]->number) == 0 && array[right]->total_cost > array[largest]->total_cost)))
            largest = right;
    }

    if (largest != i) {
        swap(array[i], array[largest]);
        heapify(array, n, largest, byDuration);
    }
}

void heapSort(PhoneCall* array[], int size, bool byDuration) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i, byDuration);

    for (int i = size - 1; i > 0; i--) {
        swap(array[0], array[i]);
        heapify(array, i, 0, byDuration);
    }
}

int partition(PhoneCall* array[], int low, int high, bool byDuration) {
    PhoneCall* pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (byDuration) {
            if ((array[j]->duration.hours * 3600 + array[j]->duration.minutes * 60 + array[j]->duration.seconds) >
                (pivot->duration.hours * 3600 + pivot->duration.minutes * 60 + pivot->duration.seconds)) {
                i++;
                swap(array[i], array[j]);
            }
        }
        else {
            if (strcmp(array[j]->number, pivot->number) < 0 ||
                (strcmp(array[j]->number, pivot->number) == 0 && array[j]->total_cost > pivot->total_cost)) {
                i++;
                swap(array[i], array[j]);
            }
        }
    }
    swap(array[i + 1], array[high]);
    return i + 1;
}

void quickSort(PhoneCall* array[], int low, int high, bool byDuration) {
    if (low < high) {
        int pi = partition(array, low, high, byDuration);
        quickSort(array, low, pi - 1, byDuration);
        quickSort(array, pi + 1, high, byDuration);
    }
}