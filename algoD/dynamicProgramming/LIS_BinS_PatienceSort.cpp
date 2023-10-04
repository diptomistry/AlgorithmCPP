#include<bits/stdc++.h>
using namespace std;

int findLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> tails(n, 0); // Initialize tails vector to store LIS endings
    int lisLength = 1; // Initialize LIS length to 1

    tails[0] = arr[0]; // The first element of arr is the smallest ending element

    for (int i = 1; i < n; i++) {
        // Binary search to find the position where arr[i] can be inserted
        auto it = lower_bound(tails.begin(), tails.begin() + lisLength, arr[i]);//lower_bound(first, last, value(is the value you want to search for.));
        //returns an iterator(address) pointing to the first element in a sorted range that is not less than the given value.

        // If arr[i] is greater than all elements in tails, extend LIS
        if (it == tails.begin() + lisLength) {
            tails[lisLength] = arr[i];
            lisLength++;
        }
        // Otherwise, replace the first element greater than or equal to arr[i]
        else {
            *it = arr[i];
        }
    }

    return lisLength;
}

int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int lisLength = findLIS(arr);
    cout << "Length of Longest Increasing Subsequence: " << lisLength << endl;

    return 0;
}
//O(nlogn)
//https://www.youtube.com/watch?v=on2hvxBXJH4&ab_channel=takeUforward