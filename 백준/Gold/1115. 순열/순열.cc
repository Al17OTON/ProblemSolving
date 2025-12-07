#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> P;

class Union {
	int uni[51];
public:
	Union() {
		for (int i = 0; i < N; ++i) {
			uni[i] = i;
		}
	}

	int find(int x) {
		if (uni[x] == x) return x;
		return uni[x] = find(uni[x]);
	}

	bool set(int x, int y) {
		x = find(x);
		y = find(y);

		if (x == y) return false;
		
		uni[y] = x;

		return true;
	}

	int get() {
		int res = 0;
		for (int i = 0; i < N; ++i) {
			if (find(i) == i) ++res;
		}
		return res;
	}
};

// 순환 갯수를 체크하기 단, 순환이 1개라면 0 -> 유니온파인드
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int n = 0; n < N; ++n) {
		int num;
		cin >> num;
		P.push_back(num);
	}

	Union uni;
	for (int n = 0; n < N; ++n) {
		uni.set(n, P[n]);
	}

	int res = uni.get();
	if (res == 1) res = 0;
	cout << res;
}