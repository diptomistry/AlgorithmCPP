//dynamic programming (DP) approach to solving the rod cutting problem(bottom-up)
#include<bits/stdc++.h>

using namespace std;

int rodCutting(vector<int>& prices, int n) {
    vector<int> dp(n + 1, 0); 
    for (int i = 1; i <= n; ++i) {
        int max_val = INT_MIN;
        for (int j = 1; j <= i; ++j) {
            max_val = max(max_val, prices[j - 1] + dp[i - j]);
        }
        dp[i] = max_val;// Update the DP table with the maximum revenue for the current rod length i.
    }
    return dp[n];
}

int main() {
    int n;
    //cout << "Enter the length of the rod: ";
    cin >> n;

    vector<int> prices(n);
    //cout << "Enter the price for each piece of the rod:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }
    auto start_time = chrono::high_resolution_clock::now(); 
    int max_value = rodCutting(prices, n);
    auto end_time = chrono::high_resolution_clock::now(); 
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "Maximum value: " << max_value << endl;
    cout << "Time taken: " << duration.count() << " ms" << endl;
    return 0;    
}
