#include <stdio.h>
#define MAX 20

int MIN = 100000000;
int N;
int S[MAX][MAX];					//능력치 배열
bool member[MAX] = { false };		//START팀에 소속된 선수 표시
int start[MAX / 2], link[MAX / 2];	//각 팀의 선수 인덱스 저장

int abs(int a, int b) {		//절댓값 반환 함수
	int result = a - b;
	if (result < 0) return result * -1;
	return result;
}

void check() {				//member배열을 통해 각 팀 팀원의 인덱스 분류 및 팀간의 능력차 계산
	int sInd = 0, lInd = 0;
	int startV = 0, linkV = 0;
	for (int i = 0; i < N; i++) {
		if (member[i]) start[sInd++] = i;
		else link[lInd++] = i;
	}
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			if (i != j) {
				startV += S[start[i]][start[j]];
				linkV += S[link[i]][link[j]];
			}
		}
	}
	int result = abs(startV, linkV);
	if (result < MIN) MIN = result;
}

void setTeam(int n, int c, int last) {	//재귀함수를 통하여 START팀의 선수를 배정
	if (c <= last) return;
	if (n == N / 2) {
		check();
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!member[i]) {
			member[i] = true;
			setTeam(n + 1, i, c);
			member[i] = false;
		}

	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) scanf("%d", &S[i][j]);
	}

	setTeam(0, 0, -1);

	printf("%d\n", MIN);

}