#include <iostream>
using namespace std;

void countingSort(int arr[], int n, int exp) {
    int output[100];
    int freq[10] = {0};
    int cumulative[10] = {0};

    cout << "\nOriginal array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        freq[digit]++;
    }
    cout << "Frequency count: ";
    for (int i = 0; i < 10; i++) {
        cout << freq[i] << " ";
    }
    cout << endl;
    cumulative[0] = freq[0];

    for (int i = 1; i < 10; i++) {
        cumulative[i] = cumulative[i - 1] + freq[i];
    }
    cout << "Cumulative count: ";
    for (int i = 0; i < 10; i++) {
        cout << cumulative[i] << " ";
    }
    cout << endl;
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[cumulative[digit] - 1] = arr[i];
        cumulative[digit]--;
    }
    cout << "Output array: ";
    for (int i = 0; i < n; i++) {
        cout << output[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    cout << "After copying back: ";
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
    int passes = 0;
    for (int exp = 1; max / exp > 0; exp *= 10) {
        passes++;
        cout << "\nPass " << passes << "\n";
        countingSort(arr, n, exp);
    }
    cout << "\nTotal digit passes: " << passes << endl;
}

int main() {
    int trackingIDs[] = {4721, 305, 472, 89, 3005, 721, 1000, 305, 9999, 42, 870, 100};

    int n = 12;

    cout << "Original tracking IDs: ";
    for (int i = 0; i < n; i++) {
        cout << trackingIDs[i] << " ";
    }
    cout << endl;
    
    radixSort(trackingIDs, n);
    
    cout << "\nFinal sorted tracking IDs: ";
    for (int i = 0; i < n; i++) {
        cout << trackingIDs[i] << " ";
    }
    cout << endl;

    return 0;
}

