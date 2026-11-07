#include <iostream>
using namespace std;

void countingSort(int arr[], int n, int exp) {
    int output[100];
    int freq[10] = {0};
    int cumulative[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        freq[digit]++;
    }
    for (int i = 1; i < 10; i++) {
        cumulative[i] = cumulative[i - 1] + freq[i];
    }
    cout << "\nFrequency Count:\n";
    for (int i = 0; i < 10; i++) {
        cout << i << ": " << freq[i] << endl;
    }
    cout << "\nCumulative Count:\n";
    for (int i = 0; i < 10; i++) {
        cout << i << ": " << cumulative[i] << endl;
    }
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[cumulative[digit] - 1] = arr[i];
        cumulative[digit]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    cout << "\nOutput Array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void radixSort(int arr[], int n) {
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    for (int exp = 1; max / exp > 0; exp *= 10) {
        if (exp == 1) {
            cout << "Ones Pass\n";
        }
        else if (exp == 10) {
            cout << "\nTens Pass\n";
        }
        else {
            cout << "\nHundreds Pass\n";
        }

        countingSort(arr, n, exp);
    }
}

int main() {
    int arr[] = {329, 457, 657, 839, 436, 720, 355};
    int n = 7;

    radixSort(arr, n);

    cout << "\nFinal Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

