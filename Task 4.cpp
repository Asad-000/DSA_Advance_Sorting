#include <iostream>
using namespace std;

int count = 0;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    count++;

    cout << "\nPivot: " << pivot;
    cout << " Low: " << low;
    cout << " High: " << high << endl;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    cout << "Array after partition: ";
    for (int j = 0; j < 7; j++) {
        cout << arr[j] << " ";
    }
    cout << endl;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    int arr[7] = {40, 20, 70, 10, 60, 30, 50};

    quickSort(arr, 0, 6);

    cout << "\nSorted array: ";
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nTotal partition operations: " << count;

    return 0;
}

