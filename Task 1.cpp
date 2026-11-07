#include <iostream>
using namespace std;

int count = 0;

void merge(int arr[], int l, int mid, int r) {
    int i = l, j = mid + 1, k = 0;
    int temp[100];

    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int i = l; i <= r; i++) {
        arr[i] = temp[i - l];
    }

    count++;

    cout << "After merge: ";
    for (int i = 0; i < 8; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

int main() {
    int arr[8] = {78, 45, 92, 63, 45, 88, 51, 70};

    mergeSort(arr, 0, 7);

    cout << "\nSorted array: ";
    for (int i = 0; i < 8; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nTotal merge operations: " << count;

    return 0;
}

