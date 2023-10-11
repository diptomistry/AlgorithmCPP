#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int matrixChainMultiplication(vector<int>& dimensions, int i, int j) {
    if (i == j) {
        return 0; // Base case: When there's only one matrix, no multiplication is needed.
    }

    int minCost = INT_MAX;

    for (int k = i; k < j; ++k) {
        int cost = matrixChainMultiplication(dimensions, i, k) +
                    matrixChainMultiplication(dimensions, k + 1, j) +
                    dimensions[i - 1] * dimensions[k] * dimensions[j];

        if (cost < minCost) {
            minCost = cost;
        }
    }

    return minCost;
}

int main() {
    vector<int> dimensions = {2,3,4,1,3};
    int n = dimensions.size();
    int minMultiplications = matrixChainMultiplication(dimensions, 1, n - 1);
    
    cout << "Minimum number of multiplications: " << minMultiplications << endl;

    return 0;
}
