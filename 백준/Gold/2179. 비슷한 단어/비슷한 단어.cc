#define _CRT_SECURE_NO_WARNINGS
#include <cstdio> 
#define MAX_N 20001
#define MAX_LEN 101

using namespace std;

struct Node {
	int time;
	Node* child[26] = { NULL };
	Node(int time) {
		this->time = time;
	}
};

struct Result {
	int m, time;
};

int N;
char words[MAX_N][MAX_LEN];
Node root = Node(-1);

Result dfs(const char* word, int idx, int time, bool combo, Node* cur);

int main() {
	scanf("%d", &N);

	Result max = { -1, N };
	int sub = -1;
	for (int n = 0; n < N; ++n) {
		scanf("%s", &words[n]);

		Result res = dfs(words[n], 0, n, true, &root);
		if (res.m > max.m || (res.m == max.m && res.time < max.time)) {
			max = res;
			sub = n;
		}
	}

	int count = 0;
	for (int n = 0; n < N && count < 2; ++n) {
		bool flag = false;
		if (n == sub) {
			flag = true;
		}
		else {
			flag = true;
			for (int i = 0; i <= max.m; ++i) {
				if (words[n][i] != words[sub][i]) {
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			++count;
			printf("%s\n", words[n]);
		}
	}

}

int char2idx(char c) {
	if (c >= 'a') return c - 'a';
	return c - 'A';
}

Result get_max(const Result& a, const Result& b) {
	if (a.m > b.m) return a;
	return b;
}

Result dfs(const char* word, int idx, int time, bool combo, Node* cur) {
	Result res = { -1, N };
	if (word[idx] == '\0') return res;
	
	int cidx = char2idx(word[idx]);

	if (cur->child[cidx] == NULL) {
		cur->child[cidx] = new Node(time);
		combo = false;
	}
	else if (combo) {
		res.m = idx;
		res.time = cur->time;
	}
	
	return get_max(res, dfs(word, idx + 1, time, combo, cur->child[cidx]));
}