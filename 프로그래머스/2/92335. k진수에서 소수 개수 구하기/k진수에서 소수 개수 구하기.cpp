#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> num_change(int n, int k) {
    vector<int> num;
    num.push_back(0);
    while(n >= k) {
        num.push_back(n % k);
        n /= k;
    }
    num.push_back(n);
    num.push_back(0);
    // reverse(num.begin(), num.end());

    return num;
}

bool is_prime(long long num) {
    if(num == 1) return false;
    for (long long i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int solution(int n, int k) {
    int answer = -1;
    vector<long long> primes;
    vector<int> changed = num_change(n, k);
    
    long long place = 1;
    long long num = 0;
    for(int i = 0; i < changed.size(); ++i) {
        int a = changed[i];
        if(a == 0) {
            if(num != 0 && is_prime(num)) primes.push_back(num);
            place = 1;
            num = 0;
        } else {
            num += a * place;
            place *= 10;
        }
    }
    
    return primes.size();
}