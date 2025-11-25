#include <iostream>
#include <unordered_map>

using namespace std;

int N, answer = 0;
int sum_map[51][51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> sum_map[i][j];
			sum_map[i][j] += sum_map[i - 1][j] + sum_map[i][j - 1] - sum_map[i - 1][j - 1];
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {

			unordered_map<int, int> up_right, down_right, up_left, down_left;

			// 오른쪽 위
			for (int ii = i - 1; ii > 0; --ii) {
				for (int jj = j + 1; jj <= N; ++jj) {
					int sum = sum_map[i - 1][jj] - sum_map[i - 1][j] - sum_map[ii - 1][jj] + sum_map[ii - 1][j];
					++up_right[sum];
				}
			}

			// 오른쪽 아래
			for (int ii = i + 1; ii <= N; ++ii) {
				for (int jj = j + 1; jj <= N; ++jj) {
					int sum = sum_map[ii][jj] - sum_map[ii][j] - sum_map[i][jj] + sum_map[i][j];
					++down_right[sum];
				}
			}

			// 왼쪽 위
			for (int ii = i; ii > 0; --ii) {
				for (int jj = j; jj > 0; --jj) {
					int sum = sum_map[i][j] - sum_map[i][jj - 1] - sum_map[ii - 1][j] + sum_map[ii - 1][jj - 1];
					++up_left[sum];
				}
			}

			// 왼쪽 아래
			for (int ii = i; ii <= N; ++ii) {
				for (int jj = j; jj > 0; --jj) {
					int sum = sum_map[ii][j] - sum_map[ii][jj - 1] - sum_map[i - 1][j] + sum_map[i - 1][jj - 1];
					++down_left[sum];
				}
			}

			for (unordered_map<int, int>::iterator iter = up_left.begin(); iter != up_left.end(); ++iter) {
				answer += iter->second * down_right[iter->first];
			}
			for (unordered_map<int, int>::iterator iter = down_left.begin(); iter != down_left.end(); ++iter) {
				answer += iter->second * up_right[iter->first];
			}
		}
	}

	cout << answer;
}