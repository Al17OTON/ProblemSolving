#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

// 2 X 2 행렬
// a b
// c d
struct Mat {
	long long a, b, c, d;
};

Mat mat_mul(const Mat& mat1, const Mat& mat2) {
	Mat mat = { 0, 0, 0, 0 };

	mat.a = (mat1.a * mat2.a + mat1.b * mat2.c) % MOD;
	mat.b = (mat1.a * mat2.b + mat1.b * mat2.d) % MOD;
	mat.c = (mat1.c * mat2.a + mat1.d * mat2.c) % MOD;
	mat.d = (mat1.c * mat2.b + mat1.d * mat2.d) % MOD;

	return mat;
}

long long fib(long long N) {
	if (N <= 1) return N;

	--N;
	int max_idx = -1;
	for (int i = 0; i < 64; ++i) {
		if (N & (1LL << i)) {
			max_idx = i;
		}
	}
	vector<Mat> mats;
	mats.push_back({ 1,1,1,0 });
	
	while (mats.size() != max_idx + 1) {
		mats.push_back(mat_mul(mats.back(), mats.back()));
	}

	// 단위 행렬
	Mat I = { 1, 0, 0, 1 };
	for (int i = 0; i <= max_idx; ++i) {
		if (N & (1LL << i)) {
			I = mat_mul(mats[i], I);
		}
	}
	return I.a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long N;
	cin >> N;

	cout << fib(N);
}