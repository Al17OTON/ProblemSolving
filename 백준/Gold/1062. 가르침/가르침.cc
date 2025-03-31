#define MAX_N 51
#define MAX_LEN 16
#include <cstdio>

using namespace std;

int N, K;
int words[MAX_N];

int combination(const int& idx, const int& count, const int& bit);
int str2bit(const char* word);
int countWord(const int& bit);
int max(int a, int b) { return a > b ? a : b; }

int main() {
	scanf("%d %d", &N, &K);
	
	char word[MAX_LEN];
	for (int n = 0; n < N; ++n) {
		scanf("%s", &word);
		words[n] = str2bit(word);
	}
	
	printf("%d\n", combination(1, 5, str2bit("antic")));
}

int combination(const int& idx, const int& count, const int& bit) {
	if (count >= K) return countWord(bit);
	if (idx == 26) return 0;

	int maxi = 0;
	if (!(bit & 1 << idx)) maxi = max(maxi, combination(idx + 1, count + 1, bit | 1 << idx));
	return max(maxi, combination(idx + 1, count, bit));
}

int countWord(const int& bit) {
	if (K < 5) return 0;
	int count = 0;

	for (int n = 0; n < N; ++n) {
		if ((bit & words[n]) == words[n]) ++count;
	}
	return count;
}

int str2bit(const char* word) {
	int bit = 0;

	for (int i = 0; word[i] != '\0'; ++i) {
		bit |= 1 << word[i] - 'a';
	}

	return bit;
}