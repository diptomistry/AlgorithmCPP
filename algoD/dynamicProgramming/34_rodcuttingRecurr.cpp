#include <iostream>


#include <climits>
#include <chrono> 
using namespace std;

int rodCutting(int prices[], int n) {  
    if (n == 0) {
        return 0;



    }
    int max_val = INT_MIN;




    for (int i = 1; i <= n; ++i) {

        max_val = max(max_val, prices[i - 1] + rodCutting(prices, n - i));
    }
return max_val;
}

int main() {
    int n;
    cin >> n;

    int prices[n];
   
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
