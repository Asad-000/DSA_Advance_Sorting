#include <iostream>
using namespace std;

int count = 0;

void merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int left[100], right[100];

    for (int i = 0; i < n1; i++) {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = arr[mid + 1 + i];
    }
    cout << "Left subarray: ";
    for (int i = 0; i < n1; i++) {
        cout << left[i] << " ";
    }
    cout << "\nRight subarray: ";
    for (int i = 0; i < n2; i++) {
        cout << right[i] << " ";
    }
    cout << endl;

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        count++;
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
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
    int arr[8] = {1299, 499, 2499, 799, 499, 1599, 999, 299};
	mergeSort(arr, 0, 7);

    cout << "\nSorted prices: ";
    for (int i = 0; i < 8; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nTotal comparisons: " << count;

    return 0;
}

