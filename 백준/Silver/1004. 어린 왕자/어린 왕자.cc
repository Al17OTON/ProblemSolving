#include <iostream>

using namespace std;

bool check_inside(int x, int y, int r, int target_x, int target_y) {
	int r2 = r * r;
	int a = target_x - x;
	a *= a;
	int b = target_y - y;
	b *= b;

	return a + b < r2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int answer = 0;
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int N;
		cin >> N;
		for (int n = 0; n < N; ++n) {
			int x, y, r;
			cin >> x >> y >> r;

			bool out = check_inside(x, y, r, x1, y1);
			bool in = check_inside(x, y, r, x2, y2);
			
			if (out != in) ++answer;
		}

		cout << answer << "\n";
	}
}