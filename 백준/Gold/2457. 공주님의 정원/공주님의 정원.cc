#define MAX 100001
#include <iostream>
#include <queue>

using namespace std;

int date[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

struct Flower {
	int start_m, start_d, end_m, end_d;
	int total_date;
	int start_date, end_date;

	bool operator <(const Flower& a) const {
		/*if (this->start_m == a.start_m) {
			if (this->start_d == a.start_d) return this->total_date < a.total_date;
			return this->start_d > a.start_d;
		}
		return this->start_m > a.start_m;*/
		
		//if (this->start_date == a.start_date) return this->total_date < a.total_date;
		return this->start_date > a.start_date;
	}
};

struct tmp_Flower {
	Flower f;

	bool operator <(const tmp_Flower& a) const {
		return this->f.end_date < a.f.end_date;
	}
};

int N;
priority_queue<Flower> pq;

int get_date(int m, int d) {
	int start = 0;
	for (int i = 1; i < m; i++) start += date[i];
	return start + d;
}


int get_total_date(int start_m, int start_d, int end_m, int end_d) {
	int total = 0;
	for (int i = start_m; i < end_m; i++) total += date[i];
	return total + end_d - start_d;
}

bool is_inside(Flower a, int cur_start_date) {
	return a.start_date <= cur_start_date && a.end_date > cur_start_date;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int n = 0; n < N; n++) {
		int start_m, start_d, end_m, end_d;
		cin >> start_m >> start_d >> end_m >> end_d;

		/*if (start_m <= 2) {
			start_m = 3;
			start_d = 1;
		}
		if (end_m == 12) {
			end_d = 1;
		}*/

		pq.push({start_m, start_d, end_m, end_d, get_total_date(start_m, start_d, end_m, end_d), start_m * 100 + start_d, end_m * 100 + end_d});
	}

	int current_m = 3, current_d = 1;
	int count = 0;

	while (!pq.empty() && current_m < 12) {
		priority_queue<tmp_Flower> tmp;

		int current_date = current_m * 100 + current_d;
		while (!pq.empty() && pq.top().start_date <= current_date) {
			if(is_inside(pq.top(), current_date)) tmp.push({ pq.top() });
			pq.pop();
		}
		
		if (tmp.empty()) {
			count = 0;
			break;
		}
		count++;
		tmp_Flower f = tmp.top();
		tmp.pop();

		current_m = f.f.end_m;
		current_d = f.f.end_d;
	}

	if (current_m < 12) count = 0;

	cout << count;
}