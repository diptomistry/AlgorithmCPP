//bounded:cant take fraction, either take entirely or not take at all

#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    //a 2D dynamic programming table dp with dimensions (n+1) x (W+1) where n is the number of items and W is the capacity of knapsack.

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {//Include the item if its weight is less than or equal to the current capacity
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
                //dp[i][w] represents the maximum value that can be obtained with the first i items, considering a knapsack with a weight capacity of w
            } else {//Otherwise, exclude the item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50;

    int maxValue = knapsack(W, weights, values);
    cout << "Maximum value: " << maxValue << endl;

    return 0;
}
