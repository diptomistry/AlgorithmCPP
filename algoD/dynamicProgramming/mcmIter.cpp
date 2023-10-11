#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int matrixChainMultiplication(vector<int>& dimensions) {
    int n = dimensions.size() - 1; // Number of matrices
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Fill in the dp table traversing diagonally
    for (int len = 2; len <= n; ++len) {//len=j-1//starting from 0 as all other diagonal elements are 0
        for (int i = 0; i < n - len + 1; ++i) {//row(i) starts from 0
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; ++k) {//j(col)//k(n=m)//(0,4)->case 1:(0,1),(1,4)=>a(0,1)+b(1,4)+v(0)*v(2)*v(4)
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[0][n - 1];//returning the top right corner element
}

int main() {
    vector<int> dimensions = {2,3,4,1,3};
    int minMultiplications = matrixChainMultiplication(dimensions);
    
    cout << "Minimum number of multiplications: " << minMultiplications << endl;

    return 0;
}
//https://www.youtube.com/watch?v=-UPo_dzBw1c&ab_channel=AnujBhaiya
