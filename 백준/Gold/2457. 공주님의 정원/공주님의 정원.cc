#define _CRT_SECURE_NO_WARNINGS
#define MAX 100001
#define YEAR 365
#include <iostream>
#include <algorithm>

int dateArr[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //1 ~ 12 월

struct Flower {
	int startMonth, startDay;
	int endMonth, endDay;
};

int date2Index(int month, int day) {
	int idx = day - 1;
	for (int i = 1; i < month; i++) {
		idx += dateArr[i - 1];
	}
	return idx;
}

bool compare(const Flower& a, const Flower& b) {
	if (a.startMonth == b.startMonth && a.startDay == b.startDay) {	//시작일이 같은경우
		if (a.endMonth == b.endMonth) return a.endDay > b.endDay;	//꽃이 지는 날 기준으로 정렬
		return a.endMonth > b.endMonth;
	}
	if (a.startMonth == b.startMonth) return a.startDay < b.startDay;
	return a.startMonth < b.startMonth;
}

int N, counter = YEAR - (dateArr[0] + dateArr[1] + dateArr[11]); //1, 2, 12월 제외
Flower flowers[MAX];
int timeTable[YEAR] = { 0 };	//1 년 = 365 문제에서 윤년을 고려하지 않는다.

int dp();

int main() {
	scanf("%d", &N);

	for (int n = 0; n < N; n++) {
		scanf("%d %d %d %d", &flowers[n].startMonth, &flowers[n].startDay, &flowers[n].endMonth, &flowers[n].endDay);
		if (flowers[n].startMonth <= 2) {
			flowers[n].startMonth = 3;
			flowers[n].startDay = 1;
		}
		if (flowers[n].endMonth == 12) {
			flowers[n].endMonth = 12;
			flowers[n].endDay = 1;
		}
	}

	std::sort(flowers, flowers + N, compare);
	
	printf("%d\n", dp());
	return 0;
}

int dp() {
	int curIdx = date2Index(3, 1);
	if (flowers[0].startMonth != 3 && flowers[0].startDay != 1) {
		return 0;
	}

	for (int n = 0; n < N; n++) {
		int startIdx = date2Index(flowers[n].startMonth, flowers[n].startDay);
		int endIdx = date2Index(flowers[n].endMonth, flowers[n].endDay);

		if (startIdx > curIdx) return 0;	//중간에 꽃이 안피는 시기가 존재하면 0
		if (endIdx <= curIdx) continue;		//꽃을 최소한으로 해야하니 이미 꽃이 피어있다면 제외
		

		for (; curIdx < endIdx; curIdx++) {
			timeTable[curIdx] = timeTable[startIdx - 1] + 1;
			counter--;
		}

		if (counter <= 0) break;
	}
	return timeTable[date2Index(11, 30)];
}