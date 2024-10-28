#include <iostream>
using namespace std;

int climbStairs(int n) {
    if (n <= 2) return n;

    int first = 1;
    int second = 2;
    int result = 0;

    for (int i = 3; i <= n; i++) {
        result = first + second;
        first = second;
        second = result;
    }

    return result;
}

int main() {
    int n = 5; // Number of steps
    cout << "Number of ways to climb " << n << " stairs: " << climbStairs(n) << endl;
    return 0;
}
