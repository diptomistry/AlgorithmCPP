#include <iostream>
#include <vector>

using namespace std;

// Merge two sorted subarrays and count inversions
long long mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;       // Index for the left subarray
    int j = mid + 1;    // Index for the right subarray
    int k = left;       // Index for the merged array
    long long inversionCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] >= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // Inversion found
            temp[k++] = arr[j++];
            inversionCount += (mid - i + 1);
        }
    }

    // Copy the remaining elements of the left and right subarrays
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the merged array back to the original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inversionCount;
}

// Merge sort with inversion counting
long long mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
    long long inversionCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inversionCount += mergeSort(arr, temp, left, mid);
        inversionCount += mergeSort(arr, temp, mid + 1, right);
        inversionCount += mergeAndCount(arr, temp, left, mid, right);
    }
    return inversionCount;
}

// Function to count inversions in an array
long long countInversions(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp(n);
    return mergeSort(arr, temp, 0, n - 1);
}

int main() {
    vector<int> arr = {2000,-1500,2500,-2300,3000};
    long long inversionCount = countInversions(arr);
    
    cout << "Number of inversions: " << inversionCount << endl;

    return 0;
}
