#include <iostream>

using namespace std;

// Function to calculate (a * b) mod m without overflow
long long multiplyMod(long long a, long long b, long long m) {
    long long result = 0;
    a %= m;

    while (b > 0) {
        if (b % 2 == 1) {
            result = (result + a) % m;
        }
        a = (a * 2) % m;
        b /= 2;
    }

    return result;
}

// Function to calculate (a^k) mod m using divide and conquer
long long powerMod(long long a, long long k, long long m) {
    if (k == 0) {
        return 1;
    } else if (k % 2 == 0) {
        long long temp = powerMod(a, k / 2, m);
        return multiplyMod(temp, temp, m) % m;
    } else {
        long long temp = powerMod(a, k / 2, m);
        return (multiplyMod(temp, temp, m) * a) % m;
    }
}

int main() {
    long long a = 3;  // Base
    long long k = 7;  // Exponent
    long long m = 1000000007;  // Modulus

    long long result = powerMod(a, k, m);
    cout << a << "^" << k << " mod " << m << " = " << result << endl;

    return 0;
}
