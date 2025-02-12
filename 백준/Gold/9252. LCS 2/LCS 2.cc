#include <stdio.h>

char A[1002], B[1002], result[1002];
int dp[1002][1002];

int MAX(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	scanf("%s %s", A, B);
	int i, j;
	for (i = 1; A[i - 1]; i++) {
		for (j = 1; B[j - 1]; j++) {
			if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]);
		}
	}
    
    int length = dp[--i][--j];
    int idx = length;
    while(dp[i][j] > 0) {
        if(dp[i][j] == dp[i - 1][j]) --i;
        else if(dp[i][j] == dp[i][j - 1]) --j;
        else {
            result[--idx] = A[i - 1];
            --i;
            --j;
        }
    }
    
	printf("%d\n", length);
    for(i = 0; i < length; i++) {
        printf("%c", result[i]);
    }
}