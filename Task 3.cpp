#include <iostream>
using namespace std;

int calls = 0;
int merges = 0;
int comparisons = 0;

void merge(int arr[], int l, int mid, int r) {
    int n = r - l + 1;
    int* temp = new int[n];
    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= r) {
        comparisons++;
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
    for (int i = 0; i < n; i++) {
        arr[l + i] = temp[i];
    }
    delete[] temp;
    merges++;
}

void mergeSort(int arr[], int l, int r) {
    calls++;

    if (l < r) {
        int mid = (l + r) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: n must be greater than 0.";
        return 0;
    }
    int* arr = new int[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);
    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nRecursive calls: " << calls;
    cout << "\nMerge operations: " << merges;
    cout << "\nElement comparisons: " << comparisons;

    delete[] arr;

    return 0;
}

