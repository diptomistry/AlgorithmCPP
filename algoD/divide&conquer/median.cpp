#include <iostream>
#include <vector>
#include <random>

using namespace std;

// Function to partition the array around a random pivot
int partition(vector<int>& arr, int left, int right) {
    int pivotIndex = left + rand() % (right - left + 1);
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]); // Move pivot to the right
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivotValue) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[right]); // Move pivot to its final position
    return i + 1;
}

// Quickselect algorithm to find the kth smallest element
int quickSelect(vector<int>& arr, int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }

    int pivotIndex = partition(arr, left, right);

    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickSelect(arr, left, pivotIndex - 1, k);
    } else {
        return quickSelect(arr, pivotIndex + 1, right, k);
    }
}

int findMedian(vector<int>& arr) {
    int n = arr.size();
    if (n % 2 == 1) {
        return quickSelect(arr, 0, n - 1, n / 2); // Odd-sized array
    } else {
        int median1 = quickSelect(arr, 0, n - 1, n / 2 - 1);
        int median2 = quickSelect(arr, 0, n - 1, n / 2);
        return (median1 + median2) / 2;
    }
}

int main() {
    vector<int> arr = {3, 2, 1, 5, 4};
    int median = findMedian(arr);

    cout << "Median: " << median << endl;

    return 0;
}
