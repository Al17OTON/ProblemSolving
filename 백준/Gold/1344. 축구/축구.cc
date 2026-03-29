#include <iostream>
#include <cmath>

using namespace std;

double A, B;
bool prime[19] = {false, false, true, true, false, true, false, true, false, false, false, true, false, true, false, false, false, true, false};
int arr[19];

int main() {
    cin >> A >> B;

    A /= 100;
    B /= 100;

    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2; i < 19; ++i) {
        arr[i] = 1;
        for(int j = i - 1; j > 0; --j) {
            arr[j] += arr[j - 1]; 
        }
    }

    double sum_a = 0, sum_b = 0;
    for(int i = 0; i < 19; ++i) {
        if(prime[i]) {
            sum_a += arr[i] * pow(A, i) * pow(1 - A, 18 - i);
            sum_b += arr[i] * pow(B, i) * pow(1 - B, 18 - i);
        }
    }

    cout << sum_a + sum_b - (sum_a * sum_b);
}