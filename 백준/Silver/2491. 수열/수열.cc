#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N;

int max(int a, int b) { return a > b ? a : b; }

int main() {
	scanf("%d", &N);

	int num, pre, gcount = 1, lcount = 1, maxi = 1;
	scanf("%d", &pre);

	for (int n = 1; n < N; ++n) {
		scanf("%d", &num);
		if (num > pre) {
			++gcount;
			lcount = 1;
		}
		else if (num < pre) {
			++lcount;
			gcount = 1;
		}
		else {
			++lcount;
			++gcount;
		}
		pre = num;

		maxi = max(maxi, max(lcount, gcount));
	}

	printf("%d", maxi);

}