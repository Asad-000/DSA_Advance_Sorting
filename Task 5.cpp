#include <iostream>
using namespace std;

int comparisons = 0;
int count = 0;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= high) {
            comparisons++;
            if (arr[i] <= pivot) {
                i++;
            }  else {
                break;
            }
        }
        while (j > low) {
            comparisons++;
            if (arr[j] > pivot) {
                j--;
            }else {
                break;
            }
        }
		    if (i >= j) {
            break;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        i++;
        j--;
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    count++;

    cout << "\nPivot: " << pivot << endl;
    cout << "Array after partition: ";
    for (int k = 0; k < 7; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;

    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    int arr[7] = {55, 25, 75, 15, 65, 35, 45};

    quickSort(arr, 0, 6);

    cout << "\nSorted array: ";
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nTotal comparisons: " << comparisons;
    cout << "\nTotal partition operations: " << count;

    return 0;
}

