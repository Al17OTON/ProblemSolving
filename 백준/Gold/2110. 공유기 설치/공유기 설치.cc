#include <iostream>
#include <algorithm>
#define MAX 200000

using namespace std;

int N, C, arr[MAX];

int binarySolution() {

	int left = 0, right = arr[N - 1], mid, counter, pre, result;

	while (left <= right) {

		pre = 0;
		mid = (left + right) / 2;
		counter = 1;

		for (int i = 0; i < N; i++) {

			if (arr[i] - arr[pre] >= mid) {
				counter++;
				pre = i;
			}
		}

		if (counter >= C) {
			result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return result;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> C;

	for (int i = 0; i < N; i++) {

		cin >> arr[i];
	}
	sort(arr, arr + N);
    
	cout << binarySolution() << endl;
}