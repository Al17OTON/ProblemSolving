#include <iostream>
#define COUNTRY 6
using namespace std;

int board[COUNTRY][3] = { 0 };
int tmp[COUNTRY][3] = { 0 };
int result[4] = { 0 };

bool is_possible(int country, int target);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int f = 0; f < 4; f++) {
		bool flag = true;
		int total_win = 0, total_loss = 0, total_draw = 0;
		for (int country = 0; country < COUNTRY; country++) {
			int win, draw, loss;
			cin >> win >> draw >> loss;

			board[country][0] = win;
			board[country][1] = draw;
			board[country][2] = loss;

			if (win + draw + loss != 5) flag = false;
			total_win += win;
			total_loss += loss;
			total_draw += draw;
		}

		if (total_win != total_loss || total_draw % 2 != 0) flag = false;

		if (flag) {
			flag = is_possible(0, 1);
		}

		result[f] = flag ? 1 : 0;
	}

	for (int i = 0; i < 4; i++) {
		cout << result[i] << " ";
	}
}

bool is_possible(int country, int target) {
	if (country >= COUNTRY) {
		return true;
	}
	if (target >= COUNTRY) {
		return is_possible(country + 1, country + 2);
	}

	for (int i = 0; i < 3; i++) {
		if (board[country][0 + i] > 0 && board[target][2 - i] > 0) {
			board[country][0 + i]--;
			board[target][2 - i]--;
			if(is_possible(country, target + 1)) return true;
			board[country][0 + i]++;
			board[target][2 - i]++;
		}
	}
	return false;
}